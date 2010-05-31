import time

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
		print delay
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
		self.motion = STOP
		self.magnitude = 0
		self.position = default
		servo_manager.add_servo(self)
		self.move_delay = 0
	def update(self, delay):
		self.move_delay += delay
		if self.move_delay >= self.magnitude:
			self.set_position(self.position + 1)
	def set_position(self, position):
		self.position = position
		valh = self.position / 255
		vall = self.position % 255
		self.teensy.send_command('\x04', chr(port) + chr(vall) + chr(valh))
	def move(self, direction, magnitude):
		self.motion = direction
		self.magnitude = magnitude

class HS548Servo(Servo):
	def __init__(self, default):
		Servo.__init__(self, (750, 2247), default, port, teensy)

class HS564Servo(Servo):
	def __init__(self, default):
		Servo.__init__(self, (750, 2100), default, port, teensy)

class AnalogServo(Servo):
	def __init__(self, default):
		Servo.__init__(self, (750, 2400), default, port, teensy)

