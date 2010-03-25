import varserver
import asyncore
import socket
import serial
import logging

LOG_LEVEL = logging.DEBUG
SC_PATH = '/dev/ttyUSB0'

class ServoController(object):
	def __init__(self, s):
		self.s = s
	def version(self, q_var, client):
		self.s.write('!SCVER?\r')
		data = self.s.read(3)
		if len(data) > 0:
			client.send(data)
		client.send('\n')

def setupLogging():
	logging.basicConfig(level=LOG_LEVEL, format="%(asctime)s - %(levelname)s - %(name)s: %(message)s")

if __name__ == '__main__':
	setupLogging()
	server = varserver.VarServer('', 8080)
	sc = ServoController(serial.Serial(SC_PATH, 2400, timeout=.1))
	server.var_hh.add_query_handler('SC_Version', sc.version)
	asyncore.loop(timeout=2)

