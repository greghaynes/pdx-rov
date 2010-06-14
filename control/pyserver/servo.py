import time
import logging

STOP = 0
INCREASE = 1
DECREASE = 2

servos = []

class ServoManager(object):
	def __init__(self):
		self.servos = []
		self.last_update = time.time()
	def update_servos(self, cur_time):
		delay = cur_time - self.last_update
		if delay >= .02:
			for servo in self.servos:
				servo.update(delay)
			self.last_update = cur_time 
	def add_servo(self, servo):
		self.servos.append(servo)

servo_manager = ServoManager()

class Servo(object):
	def __init__(self, range, default, port, teensy):
		self.range = range
		self.default = default
		self.direction = STOP
		self.magnitude = 0
		self.teensy = teensy
		self.port = port
		servo_manager.add_servo(self)
		self.set_position(default)
		self.old_pos
	def update(self, delay):
		self.set_position(self.position + self.cur_dpos())
	def set_position(self, position):
		self.position = position
		int_pos = int(position)
		if int_pos != self.old_pos:
			self.old_pos = int_pos
			valh = int_pos / 255
			vall = int_pos % 255
			self.teensy.send_command('\x04', chr(self.port) + chr(vall) + chr(valh))
	def move(self, magnitude):
		if magnitude > 255:
			magnitude = 255
		if magnitude < -255:
			magnitude = -255
		self.magnitude = magnitude
	def cur_dpos(self):
		self.magnitude / float(255)

class HS548Servo(Servo):
	def __init__(self, default, port, teensy):
		Servo.__init__(self, (750, 2247), default, port, teensy)

class HS564Servo(Servo):
	def __init__(self, default, port, teensy):
		Servo.__init__(self, (750, 2100), default, port, teensy)

class AnalogServo(Servo):
	def __init__(self, default, port, teensy):
		Servo.__init__(self, (750, 2400), default, port, teensy)

