import socket
import asyncore
import logging
import re

class VarClient(asyncore.dispatcher):
	inre = re.compile('\w*[=?]')
	def __init__(self, server, socket):
		self.server = server
		self.buffer = ''
		self.out_buffer = []
		asyncore.dispatcher.__init__(self, socket)
	def writable():
		return len(out_buffer > 0)
	def handle_write(self):
		for item in self.out_buffer
			self.socket.send(item)
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
				self.out_buffer.append('INVALID_REQUEST\n')
		else:
			self.out_buffer.append('INVALID_REQUEST\n')
	def handle_query(self, var):
		print 'Query for %s' % var
	def handle_set(self, var, val):
		print 'Set %s to %s' % (var, val)

class VarServer(asyncore.dispatcher):
	def __init__(self, ip, port):
		self.query_handlers = {}
		self.set_handlers = {}
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
	def emit_query(self, var, client):
		try:
			handlers = self.query_handlers[var]
		except KeyError:
			logging.debug('No query handlers for %s' % var)
		else:
			for handler in handlers:
				handler(var, client)
	def emit_set(self, var, val, client):
		try:
			handlers = self.set_handlers[var]
		except KeyError:
			logging.debug('No set handlers for %s' % var)
		else:
			for handler in handlers:
				handler(var, val, client)
	def add_query_handler(self, var, handler):
		try:
			handlers = self.query_handlers[var]
		except KeyError:
			self.query_handlers[var] = []
			handlers = self.query_handlers[var]
		handlers.append(handler)
	def add_set_handler(self, var, handler):
		try:
			handlers = self.set_handlers[var]
		except KeyError:
			self.query_handlers[var] = []
			handlers = self.set_handlers[var]
		handlers.append(handler)

if __name__ == '__main__':
	server = VarServer('127.0.0.1', 8080)
	asyncore.loop(timeout=2)

