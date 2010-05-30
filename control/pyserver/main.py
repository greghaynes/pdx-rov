from jsonserver import JsonServer
from propulsion import Propulsion
from teensy import Teensy
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

def setupLogging():
	logging.basicConfig(level=LOG_LEVEL, format="%(asctime)s - %(levelname)s - %(name)s: %(message)s")

def showHelp():
	print 'Usage: python main.py [-h] [-p port] -s sc_path -t teensy1 -u teensy2'

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

	propulsion = Propulsion(Teensy('/dev/ttyACM0'))
	
	server = JsonServer('', port)
	server.add_module('propulsion', propulsion)
	
	asyncore.loop(timeout=30)

