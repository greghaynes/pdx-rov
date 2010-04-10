import varserver
import struct

class PropController(object):
	def __init__(self, device):
		self.device = device
	def setPWM(self, port, value):
		vh = value / 256
		vl = value % 256
		self.device.write('\x00' + chr(port) + chr(vh) + chr(vl) + '\n')

class Prop(varserver.VarHandler):
	def __init__(self, prop_controller, port, name):
		varserver.VarHandler.__init__(self, 'PROP', name)
		self.prop_controller = prop_controller
		self.port = port
	def handle_set(self, client, value):
		value = int(value)
		if value > 511 or value < 0:
			raise ValueError('Out of range')
		self.prop_controller.setPWM(self.port, value)

