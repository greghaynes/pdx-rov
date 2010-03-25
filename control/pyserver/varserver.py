import socket
import asyncore
import logging
import re

class VarHandlerHandler(object):
	def __init__(self):
		self.query_handlers = {}
		self.set_handlers = {} 
	def emit_query(self, var, client):
		try:
			handlers = self.query_handlers[var]
		except KeyError:
			logging.debug('No query handlers for %s' % var)
			client.send('NOT_REGISTERED\n')
		else:
			for handler in handlers:
				handler[0](var, client, *handler[1])
	def emit_set(self, var, val, client):
		try:
			handlers = self.set_handlers[var]
		except KeyError:
			logging.debug('No set handlers for %s' % var)
			client.send('NOT_REGISTERED\n')
		else:
			for handler in handlers:
				handler[0](var, val, client, *handler[1])
	def add_query_handler(self, var, handler, *args):
		try:
			handlers = self.query_handlers[var]
		except KeyError:
			self.query_handlers[var] = []
			handlers = self.query_handlers[var]
		handlers.append((handler, args))
	def add_set_handler(self, var, handler, *args):
		try:
			handlers = self.set_handlers[var]
		except KeyError:
			self.query_handlers[var] = []
			handlers = self.set_handlers[var]
		handlers.append((handler, args))

class VarClient(asyncore.dispatcher):
	inre = re.compile('\w*[=?]')
	def __init__(self, server, socket):
		self.server = server
		self.buffer = ''
		self.out_buffer = []
		asyncore.dispatcher.__init__(self, socket)
	def writable(self):
		return len(self.out_buffer) > 0
	def handle_write(self):
		for item in self.out_buffer:
			self.socket.send(item)
		del self.out_buffer[:]
	def handle_read(self):
		self.buffer += self.socket.recv(1024)
		tmp_buff = self.buffer.split('\n')
		self.buffer = tmp_buff.pop()
		for line in tmp_buff:
			self.handle_line(line)
	def handle_line(self, line):
		logging.debug('Received line %s' % line)
		m = self.inre.match(line)
		if m:
			s = m.group(0)
			ctl = s[len(s)-1]
			var = s[:len(s)-1]
			if ctl == '?':
				self.handle_query(var)
			elif ctl == '=':
				val = line[len(s):]
				self.handle_set(var, val)
			else:
				self.send('INVALID_REQUEST\n')
		else:
			self.send('INVALID_REQUEST\n')
	def handle_query(self, var):
		logging.debug('Query for %s' % var)
		self.server.var_hh.emit_query(var, self)
	def handle_set(self, var, val):
		logging.debug('Set %s to %s' % (var, val))
		self.server.var_hh.emit_set(var, val, self)
	def send(self, data):
		self.out_buffer.append(data)

class VarServer(asyncore.dispatcher):
	def __init__(self, ip, port, var_hh=VarHandlerHandler()):
		self.var_hh = var_hh
		self.ip = ip
		self.port = port
		asyncore.dispatcher.__init__(self)
		self.create_socket(socket.AF_INET, socket.SOCK_STREAM)

		self.set_reuse_addr()
		self.bind((self.ip, self.port))
		self.clients = []
		self.listen(1024)
	def handle_accept(self):
		conn = self.socket.accept()
		logging.debug('Accepted connection from %s', conn[1])
		self.clients.append(VarClient(self, conn[0]))
	def broadcast(self, data):
		for client in self.clients:
			client.send(data)

def varHandler(var, client):
	print '%s queried' % var

if __name__ == '__main__':
	server = VarServer('127.0.0.1', 8080)
	server.var_hh.add_query_handler('Motor1', varHandler)
	asyncore.loop(timeout=2)
