import socket
import asyncore
import logging
import re

class NotSupportedError(Exception):
	pass

class VarHandler(object):
	'''Subclass this is create your own handlers'''
	def __init__(self, var_type, var_name):
		self.var_type = var_type
		self.var_name = var_name
	def hande_query(self, client):
		raise NotSupportedError()
	def handle_set(self, client, value):
		raise NotSupportedError()

class VarClient(asyncore.dispatcher):
	inre = re.compile('\w*[=?:,]')
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
	def handle_close(self):
		logging.debug('Closed connection')
		self.close()
	def handle_line(self, line):
		logging.debug('Received line %s' % line)
		m = self.inre.match(line)
		if m:
			s = m.group(0)
			ctl = s[len(s)-1]
			var = s[:len(s)-1]
			if ctl == '?':
				self.handle_query(var)
				self.server.handle_var_query(self, var)
			elif ctl == '=':
				val = line[len(s):]
				self.server.handle_var_set(self, var, val)
			elif ctl == '.':
				type = self.server.var_hh.set_handlers[var][0][0]
				self.send('%s.%s\n' % type)
			elif ctl == ',':
				type = self.server.var_hh.query_handlers[var][0][0]
				self.send('%s,%s\n' % type)
			else:
				self.send('INVALID_REQUEST\n')
		else:
			self.send('INVALID_REQUEST\n')
	def send(self, data):
		self.out_buffer.append(data)

class VarServer(asyncore.dispatcher):
	'''Acts as a variable server to call set / query methods for var handlers
	   Each command is terminated with a newline (\\n)
	   Command format: Var<control_char>(value)<terminator>
	   Commands:
	      Var=value\\n - Responds with value set to variable
	      Var? - Responds with variables value
	      Var: - Responds with set variable type
	      Var, - Respends with query variable type'''
	def __init__(self, ip, port):
		self.handlers = {}
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
	def broadcast_var_state(self, var, val):
		self.broadcast('%s=%s\n' % (var, val))
	def addHandler(self, handler):
		try:
			handler = self.handlers[handler.var_name]
		except KeyError:
			self.handlers[handler.var_name] = handler
		else:
			raise ValueError('Multiple handlers for variable %s' % handler.var_name)
	def handle_var_query(self, client, var):
		try:
			val = self.handlers[var].handle_query(client)
		except KeyError:
			client.send('NOT_REGISTERED\n')
		except NotSupportedError:
			client.send('NOT_SUPPORTED\n')
		else:
			client.send('%s=%s\n' % (var, val))
	def handle_var_set(self, client, var, value):
		try:
			self.handlers[var].handle_set(client, value)
		except KeyError:
			client.send('NOT_REGISTERED\n')
		except NotSupportedError:
			client.send('NOT_SUPPORTED\n')
		except ValueError:
			client.send('OUT_OF_RANGE\n')

