import serial
import asyncore
import os

class Teensy(asyncore.file_wrapper):
	def __init__(self, path):
		self.device = serial.Serial(path, timeout=0)
		self.ibuffer = ''
		self.obuffer = []
		asyncore.file_wrapper.__init__(self, self.device.fd)
	def handle_write(self):
		for data in self.obuffer:
			self.send(data)
		self.obuffer = []
	def writable(self):
		return len(self.obuffer) > 0
	def handle_read(self):
		print 'read'
		buff = self.device.read(1024)
		if len(buff) == 0:
			self.close()
		else:
			self.ibuffer += buff
			tmp_buff = buff.split('\n\n')
			self.ibuffer = tmp_buff.pop()
			for line in tmp_buff:
				self.handle_read_line(line)
	def handle_read_line(self, line):
		print line
	def handle_cloe(self):
		print 'close'
		self.close()

