motor_port = {
	'FL': 0,
	'FR': 1,
	'BL': 2,
	'BR': 3,
	'UL': 4,
	'UR': 5,
	'DL': 6,
	'DR': 7
	}

class MotorController(object):
	def __init__(self, serial_device):
		self.serial = serial_device;
	def motor_set(self, motor, magnitude):
		self.serial.write('\x04' + ord(motor_port[motor]) + ord(magnitude) + '\n')

