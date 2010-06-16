from jsonserver import InvalidCommandError

motor_port = {
	'FL': 2,
	'FR': 1,
	'BL': 0,
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
		value = int(value)
		if value < 0:
			raise ValueError('Out of range')
		elif value > 255:
			value = 255
		if self.motors[motor].value != value:
			self.teensy.send_command('\x04', chr(self.motors[motor].port) + chr(value))
			self.motors[motor].value = value
	def motor_states(self):
		states = {}
		for motor in self.motors:
			states[motor.name] = motor.value
		return states

class Propulsion(object):
	def __init__(self, teensy):
		self.motor_controller = MotorController(teensy, motor_port)
		self.command_handlers = {
			'move': self.move_command,
			'motor_states': self.get_motor_states
			}
		self.move_direction_motors = {
			'forward': (
				(('FL', .75), ('FR', 1)),
				(('BL', .75), ('BR', 1))
				),
			'strafe': (
				(('FL', 1), ('BL', .9)),
				(('FR', 1), ('BR', .9))
				),
			'ascend': (
				(('DL', 1), ('DR', 1)),
				(('UL', .8), ('UR', .8))
				),
			'yaw': (
				(('FL', 1), ('BR', 1)),
				(('FR', 1), ('BL', 1))
				),
			'roll': (
				(('UL', 1), ('DR', 1)),
				(('UR', 1), ('DL', 1))
				)
			}
	def handle_command(self, client, request, command, arguments):
		try:
			self.command_handlers[command](client, request, command, arguments)
		except KeyError:
			raise InvalidCommandError(command)
	def normalize_motors(self, motors):
		'''If a motor value is over 255 scale all (linearly) so the max value is 255'''
		maxval = 0
		for motor, value in motors.items():
			if maxval < value:
				maxval = value
		if maxval <= 255:
			'''No normalization needed'''
			return motors
		normconst = float(255) / maxval:
		for motor, value in motors.items():
			motors[motor] = int(value * normconst)
	def accumulate_move_motors(self, motors, effected_motors, magnitude):
		for motor_factor in effected_motors:
			motor = motor_factor[0]
			factor = motor_factor[1]
			magnitude *= factor
			motors[motor] += magnitude
	def move_command(self, client, request, command, arguments):
		'''Every move command requires all motor values to be sent'''
		tmp_motors = {
			'FL': 0, 'FR': 0,
			'BL': 0, 'BR': 0,
			'UL': 0, 'UR': 0,
			'DL': 0, 'DR': 0
			}
		
		for direction in ('forward', 'strafe', 'ascend', 'yaw', 'roll'):
			'''Accumulate values from each motion vector'''
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

		normalize_motors(tmp_motors)

		for motor, mag in tmp_motors.items():
			'''Send the values to the controller'''
			self.motor_controller.set_motor(motor, mag)
	def get_motor_states(self, client, request, command, arguments):
		client.send_response(0, {
			'module': 'propulsion',
			'command': 'motor_states',
			'arguments': { 'motors': self.motor_controller.motor_states() },
			}

