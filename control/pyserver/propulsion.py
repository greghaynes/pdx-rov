from jsonserver import InvalidCommandError

class Propulsion(object):
	def __init__(self, motor_controller):
		self.motor_controller = motor_controller
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
			self.command_handlers[command.command](request, command, arguments)
		except KeyError:
			raise InvalidCommandError(command)
	def accumulate_move_motors(self, motors, effected_motors, magnitude):
		for motor in effected_motors:
			motors[motor] += magnitude
	def process_move_strafe(self, motors, magnitude):
		if magnitude > 0:
			effected_motors = ('FL', 'BL')
		else:
			effected_motors = ('FR', 'BR')
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
				accumulate_move_motors(
					tmp_motors,
					self.move_direction_motors[direction],
					magnitude
					)

