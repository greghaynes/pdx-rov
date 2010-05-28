import asyncore, socket
import json

# Response Codes
# 0 - Success
# 1 - Invalid Module
# 2 - Invalid Command

def create_command(module_name, command_name, args={}):
	return {
		'module': module_name,
		'command': command_name,
		'arguments': args}

error_command = create_command('core', 'error')

class RequestError(Exception):
	def __init__(self, desc):
		self.desc = desc
	def __str__(self):
		return repr(self.desc)

class InvalidModuleError(Exception):
	def __init__(self, command):
		RequestError.__init__(self, command)

class InvalidCommandError(Exception):
	def __init__(self, command):
		RequestError.__init__(self, command)

class JsonClient(asyncore.dispatcher):
	def __init__(self, server, socket):
		self.server = server
		self.ibuffer = ''
		self.obuffer = []
	def writable(self):
		return len(self.obuffer) > 0
	def handle_read(self):
		buff = self.socket.recv(1024)
		if len(buff) == 0:
			self.close()
		else:
			self.ibuffer += buff
			tmp_buff = self.buffer.split('\n\n')
			self.ibuffer = tmp_buff.pop()
			for line in tmp_buff:
				self.handle_request_data(line)
	def handle_close(self):
		self.close()
	def handle_request_data(self, data):
		request = json.loads(data)
		self.handle_request(request)
	def handle_request(self, request):
		self.server.handle_command(self, request, request.command)
	def send_response(self, code, command):
		resp_dict = {
			'code': code,
			'command': command}
		self.obuffer.append(json.dumps(resp_dict))

class JsonServer(asyncore.dispatcher):
	def __init__(self, host, port):
		asyncore.dispatcher.__init__(self)
		self.create_socket(socket.AF_INET, socket.SOCK_STREAM)
		self.clients = []
		self.modules = {}
	def handle_accept(self):
		conn = self.socket.accept()
		self.clients.append(VarClient(self, conn[0]))
	def handle_command(self, client, request, command):
		try:
			self.modules[command.module].handle_command(
				request,
				command.commmand,
				command.arguments)
		except (KeyError, InvalidModuleError):
			client.send_response(1, error_command)
		except InvalidCommandError:
			client.send_response(2, error_command)

