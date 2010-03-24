import varserver
import asyncore
import socket
import serial
import logging

LOG_LEVEL = logging.DEBUG

sc_servos = {
	'Servo1': '/dev/ttyUSB0'
}

var_query_handlers = {}

def servoSet(var, val, s):
	print 'set var'

def servoQuery(var, client, s):
	print 'query var'

def setupServos():
	for name, path in sc_servos.iteritems():
		try:
			s = serial.Serial(path, 2400)
		except serial.serialutil.SerialException:
			errmsg = 'Invalid serial device for %s: %s' % (name, path)
			logging.error(errmsg)
			raise ValueError(errmsg)
		else:
			var_handlers[name] = (setupServos, (s,))

def setupLogging():
	logging.basicConfig(level=LOG_LEVEL, format="%(asctime)s - %(levelname)s - %(name)s: %(message)s")

if __name__ == '__main__':
	setupLogging()
	setupServos()
	server = varserver.VarServer('', 8080)
	for var, handler in var_query_handlers.iteritems():
		server.var_hh.add_query_handler(var, handler[0], *handler[1])
	asyncore.loop(timeout=2)

