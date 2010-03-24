import varserver
import asyncore
import socket
import serial
import logging

sc_servos = {
	'Servo1': '/dev/ttyUSB0'
}

var_query_handlers = {}

def servoQuery(var, client, s):
	print 'query var'

def setupServos():
	for name, path in sc_servos.iteritems():
		try:
			s = serial.Serial(path, 2400)
		except serial.serialutil.SerialException:
			logging.error('No serial device %s' % path)
			raise ValueError('Invalid serial device for %s: %s' % (name, path))
		else:
			var_handlers[name] = (setupServos, (s,))

if __name__ == '__main__':
	setupServos()
	server = varserver.VarServer('', 8080)
	for var, handler in var_query_handlers.iteritems():
		server.var_hh.add_query_handler(var, handler[0], *handler[1])
	asyncore.loop(timeout=2)

