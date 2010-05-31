import serial
import asyncore
import os
import time

import timer
import logging

class Teensy(asyncore.file_dispatcher):
	def __init__(self, path):
		self.device = serial.Serial(path, timeout=0)
		self.ibuffer = ''
		self.obuffer = []
		self.command_handlers = {
			'\x00': self.handle_ping
			}
		asyncore.file_dispatcher.__init__(self, self.device.fd)
	def handle_write(self):
		for data in self.obuffer:
			self.send(data)
		self.obuffer = []
	def writable(self):
		return len(self.obuffer) > 0
	def handle_read(self):
		buff = self.device.read(1024)
		if len(buff) == 0:
			self.close()
		else:
			self.ibuffer += buff
			tmp_buff = buff.split('\n')
			self.ibuffer = tmp_buff.pop()
			for line in tmp_buff:
				self.handle_read_line(line)
	def handle_read_line(self, line):
		try:
			self.command_handlers[line[0]](line)
		except KeyError:
			pass
	def handle_ping(self, line):
		resp = line[1:]
		self.obuffer.append('\x01' + data )
	def handle_cloe(self):
		self.close()
	def send_command(self, command, data):
		self.obuffer.append(command + data + '\n')

