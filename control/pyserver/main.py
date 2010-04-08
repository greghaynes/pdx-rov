import varserver
from servo import PositionServo, ServoController
import asyncore
import socket
import serial
import logging
import sys, getopt

LOG_LEVEL = logging.DEBUG
SC_PATH = ''
port = 8080

armservo_channel = [
	('Gripper', 0),
	('Wrist', 4),
	('Elbow', 3),
	('RotatorCuff', 2),
	('Shoulder', 1)
	]

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
	server.addHandler(sc)
	for a_c in armservo_channel:
		s = PositionServo(sc, a_c[1], a_c[0])
		server.addHandler(s)
	asyncore.loop(timeout=2)

