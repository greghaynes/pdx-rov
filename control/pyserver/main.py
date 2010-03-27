import varserver
import asyncore
import socket
import serial
import logging
import struct
import sys, getopt

LOG_LEVEL = logging.DEBUG
SC_PATH = ''
port = 8080

class Servo(object):
	speed = 2
	min = (0, 300) # (client, servo)
	max = (180, 1200)
	def __init__(self, controller, channel):
		self.controller = controller
		self.channel = channel
		self.serv_val_factor = (self.max[1] - self.min[1]) / (self.max[0] - self.min[0])
		self.client_val_factor = 1 / float(self.serv_val_factor)
	def convert_client_value(self, value):
		if value < self.min[0] or value > self.max[0]:
			raise ValueError('Out of range')
		return (self.min[1] - self.min[0]) + (self.serv_val_factor * value)
	def convert_server_value(self, value):
		if value < self.min[1] or value > self.max[1]:
			raise ValueError('Out of range')
		return self.client_val_factor * (value + (self.min[0] - self.min[1]))
	def set_position(self, q_var, value, client):
		value = int(value)
		try:
			serv_value = self.convert_client_value(value)
		except ValueError:
			client.send('INVALID_VALUE\n')
		else:
			sv = struct.pack('H', serv_value)
			cmd = struct.pack('BB', self.channel, self.speed)
			cmd += sv[0] + sv[1]
			self.controller.sendCommand(cmd)
			self.controller.server.broadcast_var_state(q_var, value)
	def position(self, q_var, client):
		self.controller.sendCommand('RSP' + struct.pack('B', self.channel))
		data = self.controller.s.read(3)
		if len(data) == 3:
			data = data[2] + data[1]
			data = struct.unpack('H', data)
			logging.debug(data)
			try:
				data = self.convert_server_value(data[0])
			except ValueError:
				client.send('INVALID_VALUE\n')
			else:
				client.send('%s=%i' % (q_var, data))
		client.send('\n')

class ServoController(object):
	def __init__(self, s, serer):
		self.s = s
		self.server = server
	def sendCommand(self, command):
		self.s.write('!SC' + command + '\r')
	def version(self, q_var, client):
		self.sendCommand('VER?')
		data = self.s.read(3)
		if len(data) > 0:
			client.send(data)
		client.send('\n')

def setupLogging():
	logging.basicConfig(level=LOG_LEVEL, format="%(asctime)s - %(levelname)s - %(name)s: %(message)s")

def showHelp():
	print 'Usage: python main.py [-h] [-p port] -c device_path'

if __name__ == '__main__':
	try:
		opts, args = getopt.getopt(sys.argv[1:], 'p:c:h', '')
	except getopt.GetOptError:
		print 'Invalid argument'
		showHelp()
	for opt in opts:
		if opt[0] == '-p':
			port = int(opt[1])
		elif opt[0] == '-c':
			SC_PATH = opt[1]
		elif opt[0] == '-h':
			showHelp()
			sys.exit(0)
	if SC_PATH == '':
		showHelp()
		sys.exit(0)
	setupLogging()
	server = varserver.VarServer('', port)
	sc = ServoController(serial.Serial(SC_PATH, 2400, timeout=.1), server)
	server.var_hh.add_query_handler('FW_VERSION', 'FW_Version', sc.version)
	s1 = Servo(sc, 0)
	server.var_hh.add_query_handler('SERVO_POS', 'Servo1', s1.position)
	server.var_hh.add_set_handler('SERVO_POS', 'Servo1', s1.set_position)
	asyncore.loop(timeout=2)

