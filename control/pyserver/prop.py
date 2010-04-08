import varserver

class PropController(object):
	def __init__(self, device):
		self.device = device
	def setPWM(self, port, value):
		vh = value / 255
		vl = value % 255
		self.device.write('\x00' + chr(port) + chr(vh) + chr(vl) + '\n')

class Prop(varserver.VarHandler):
	def __init__(self, prop_controller, port, name):
		varserver.VarHandler.__init__(self, 'PROP', name)
		self.prop_controller = prop_controller
		self.port = port
	def handle_set(self, client, value):
		self.prop_controller.setPWM(self.port, int(value))

