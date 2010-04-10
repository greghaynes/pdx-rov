import varserver
from servo import PositionServo, ServoController
from prop import PropController, Prop
import asyncore
import socket
import serial
import logging
import sys, getopt

LOG_LEVEL = logging.DEBUG
SC_PATH = ''
T1_PATH = ''
T2_PATH = ''
port = 8080

armservo_channel = [
	('Gripper', 0),
	('Wrist', 4),
	('Elbow', 3),
	('RotatorCuff', 2),
	('Shoulder', 1)
	]

teensy1_prop_port = [
	('FL', 0),
	('FR', 1),
	('BL', 2),
	('BR', 3)
	]

def setupLogging():
	logging.basicConfig(level=LOG_LEVEL, format="%(asctime)s - %(levelname)s - %(name)s: %(message)s")

def showHelp():
	print 'Usage: python main.py [-h] [-p port] -s device_path -t teensy1 -u teensy2'

if __name__ == '__main__':
	try:
		opts, args = getopt.getopt(sys.argv[1:], 'p:s:t:u:h', '')
	except getopt.GetOptError:
		print 'Invalid argument'
		showHelp()
	for opt in opts:
		if opt[0] == '-p':
			port = int(opt[1])
		elif opt[0] == '-s':
			SC_PATH = opt[1]
		elif opt[0] == '-t':
			T1_PATH = opt[1]
		elif opt[0] == '-u':
			T2_PATH = opt[1]
		elif opt[0] == '-h':
			showHelp()
			sys.exit(0)
	setupLogging()
	server = varserver.VarServer('', port)
	if SC_PATH != '':
		logging.info('Using \'%s\' as servo controller device' % SC_PATH)
		sc = ServoController(serial.Serial(SC_PATH, 2400, timeout=.1), server)
		server.addHandler(sc)
		for a_c in armservo_channel:
			s = PositionServo(sc, a_c[1], a_c[0])
			server.addHandler(s)
	else:
		logging.info('No servo controller specified')
	if T1_PATH != '':
		logging.info('Using \'%s\' as motor controller 1 device' % T1_PATH)
		pc = PropController(serial.Serial(T1_PATH, timeout=.1))
		for p_c in teensy1_prop_port:
			p = Prop(pc, p_c[1], p_c[0])
			server.addHandler(p)
	else:
		logging.info('No motor controller 1 specified')
	asyncore.loop(timeout=2)

