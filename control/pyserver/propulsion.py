import motorcontroller

from jsonserver import InvalidCommandError

class Propulsion(object):
	def __init__(self, motor_controller):
		self.motor_controller = motor_controller
		self.command_handlers = {
			}
	def handle_command(self, request, command, arguments):
		try:
			self.command_handlers[command.command]
		except KeyError:
			raise InvalidCommandError(command)

def setup(server): 
	prop_module = Propulsion(motorcontroller.motorcontroller)
	server.addModule(prop_module)

