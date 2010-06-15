import serial
import asyncore
import os
import time

import timer
import logging

class Teensy(object):
	def __init__(self, path):
		self.device = serial.Serial(path, timeout=.01)
		self.adc_listeners = []
		self.command_handlers = {
			}
	def send_command(self, command, data):
		self.device.write(command + data + '\n')
	def add_adc_listener(self, func):
		self.adc_listeners.append(func)

