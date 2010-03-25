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

class ServoController(object):
	def __init__(self, s):
		self.s = s
	def version(self, q_var, client):
		self.s.write('!SCVER?\r')
		data = self.s.read(3)
		if len(data) > 0:
			client.send(data)
		client.send('\n')
	def sposition(self, q_var, client):
		self.s.write('!SCRSP\x00\r')
		data = self.s.read(3)
		if len(data) == 3:
			data = struct.unpack('H', data[1:])
			client.send(data[0])
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
	sc = ServoController(serial.Serial(SC_PATH, 2400, timeout=.1))
	server.var_hh.add_query_handler('FW_Version', sc.version)
	server.var_hh.add_query_handler('Servo1', sc.sposition)
	asyncore.loop(timeout=2)

