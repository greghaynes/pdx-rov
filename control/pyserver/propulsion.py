from jsonserver import InvalidCommandError

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

class Motor(object):
	def __init__(self, name, port, value=0):
		self.name = name
		self.port = port
		self.value = value

class MotorController(object):
	def __init__(self, teensy, motor_port):
		self.teensy = teensy	
		self.motors = {}
		for motor, port in motor_port.items():
			self.motors[motor] = Motor(motor, port)
	def set_motor(self, motor, value):
		if value < 0:
			raise ValueError('Out of range')
		elif value > 255:
			value = 255
		if self.motors[motor].value != value:
			self.teensy.send_command('\x04', chr(self.motors[motor].port) + chr(value))
			self.motors[motor].value = value

class Propulsion(object):
	def __init__(self, teensy):
		self.motor_controller = MotorController(teensy, motor_port)
		self.command_handlers = {
			'move': self.move_command
			}
		self.move_direction_motors = {
			'forward': (
				('FL', 'FR'),
				('BL', 'BR')
				),
			'strafe': (
				('FL', 'BL'),
				('FR', 'BR')
				),
			'ascend': (
				('DL', 'DR'),
				('UL', 'UR')
				),
			'yaw': (
				('FL', 'BR'),
				('FR', 'BL')
				),
			'roll': (
				('UL', 'DR'),
				('UR', 'DL')
				)
			}
	def handle_command(self, request, command, arguments):
		try:
			self.command_handlers[command](request, command, arguments)
		except KeyError:
			raise InvalidCommandError(command)
	def accumulate_move_motors(self, motors, effected_motors, magnitude):
		for motor in effected_motors:
			motors[motor] += magnitude
	def move_command(self, request, command, arguments):
		tmp_motors = {
			'FL': 0, 'FR': 0,
			'BL': 0, 'BR': 0,
			'UL': 0, 'UR': 0,
			'DL': 0, 'DR': 0
			}
		for direction in ('forward', 'strafe', 'ascend', 'yaw', 'roll'):
			try:
				magnitude = arguments[direction]
			except KeyError:
				pass
			else:
				if magnitude > 0:
					effected_motors = self.move_direction_motors[direction][0]
				else:
					effected_motors = self.move_direction_motors[direction][1]
					magnitude = -magnitude
				self.accumulate_move_motors(
					tmp_motors,
					effected_motors,
					magnitude
					)
		for motor, mag in tmp_motors.items():
			self.motor_controller.set_motor(motor, mag)

