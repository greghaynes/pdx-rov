import asyncore, socket
import json

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
		requests = json.loads(data)
		for request in requests:
			self.handle_request(request)
	def handle_request(self, request):
		for command in request.commands:
			self.server.handle_command(self, request, command)

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
		except KeyError:
			pass

