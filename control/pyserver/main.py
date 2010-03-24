import varserver
import asyncore
import socket
import serial
import logging

LOG_LEVEL = logging.DEBUG

class ServoController(object):
	def __init__(self, s):
		self.s = s
	def version(self, q_var, client):
		self.s.write('!SCVER?\r')
		client.send(self.s.read(3))
		client.send('\n')

def setupLogging():
	logging.basicConfig(level=LOG_LEVEL, format="%(asctime)s - %(levelname)s - %(name)s: %(message)s")

if __name__ == '__main__':
	setupLogging()
	server = varserver.VarServer('', 8080)
	sc = ServoController(serial.Serial('/dev/ttyUSB0', 2400))
	server.var_hh.add_query_handler('SC_Version', sc.version)
	asyncore.loop(timeout=2)

