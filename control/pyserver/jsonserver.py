import asyncore, socket
import json
import logging

# Response Codes
# 0 - Success
# 1 - Invalid Module
# 2 - Invalid Command

def create_command(module_name, command_name, args={}):
	return {
		'module': module_name,
		'command': command_name,
		'arguments': args
		}

error_command = create_command('core', 'error')

class RequestError(Exception):
	def __init__(self, desc):
		self.desc = desc
	def __str__(self):
		return repr(self.desc)

class InvalidModuleError(RequestError):
	def __init__(self, command):
		RequestError.__init__(self, command)

class InvalidCommandError(RequestError):
	def __init__(self, command):
		RequestError.__init__(self, command)

class InvalidArgumentError(RequestError):
	def __init__(self, argument):
		RequestError.__init__(self, argument)

class JsonClient(asyncore.dispatcher):
	def __init__(self, server, socket):
		asyncore.dispatcher.__init__(self, socket)
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
			tmp_buff = self.ibuffer.split('\n\n')
			self.ibuffer = tmp_buff.pop()
			for line in tmp_buff:
				self.handle_request_data(line)
	def handle_close(self):
		self.close()
	def handle_request_data(self, data):
		request = json.loads(data)
		self.handle_request(request)
	def handle_request(self, request):
		self.server.handle_command(self, request, request['command'])
	def send_response(self, code, command):
		resp_dict = {
			'code': code,
			'command': command}
		self.obuffer.append(json.dumps(resp_dict))

class JsonServer(asyncore.dispatcher):
	def __init__(self, host, port):
		asyncore.dispatcher.__init__(self)
		self.create_socket(socket.AF_INET, socket.SOCK_STREAM)
		self.bind((host, port))
		self.clients = []
		self.modules = {}
		self.listen(1024)
	def handle_accept(self):
		conn = self.socket.accept()
		logging.debug("Accepted connection");
		self.clients.append(JsonClient(self, conn[0]))
	def handle_command(self, client, request, command):
		try:
			module = command['module']
			command_name = command['command']
			arguments = command['arguments']
		except KeyError:
			logging.error("Invalid request")
		else:
			try:
				self.modules[module].handle_command(
					request,
					command_name,
					arguments)
			except (KeyError, InvalidModuleError):
				logging.error("Invalid module \'%s\'" % command['module'])
				client.send_response(1, error_command)
			except InvalidCommandError:
				logging.error("Invalid command")
				client.send_response(2, error_command)
	def add_module(self, module_name, module):
		self.modules[module_name] = module
	def writable(self):
		return False
	def handle_close(self):
		logging.debug("Server closed")
		self.close()

