import varserver
import struct

class PositionServo(varserver.VarHandler):
	default_speed = 2
	min = 300
	max = 1200
	def __init__(self, servo_controller, channel, var_name):
		varserver.VarHandler.__init__(self, 'SERVO_POS', var_name)
		self.servo_controller = servo_controller
		self.channel = channel
		self.value_commands = {
			'Enable': self.enable,
			'Disable': self.disable
			}
	def handle_set(self, client, value):
		try:
			value = value.strip()
			self.value_commands[value](client, value)
		except KeyError:
			values  = value.split(',')
			pos = int(values[0])
			try:
				speed = int(values[1])
			except IndexError:
				speed = self.default_speed
			if pos > self.max or pos < self.min:
				raise ValueError('Out of range')
			else:
				sv = struct.pack('H', pos)
				cmd = struct.pack('BB', self.channel, speed)
				cmd += sv[0] + sv[1]
				self.servo_controller.sendCommand(cmd)
				self.servo_controller.server.broadcast_var_state(self.var_name, value)
	def handle_query(self, client):
		self.servo_controller.sendCommand('RSP' + struct.pack('B', self.channel))
		data = self.controller.s.read(3)
		if len(data) == 3:
			data = data[2] + data[1]
			data = struct.unpack('H', data)
			logging.debug(data)
			client.send('%s=%i' % (self.var_name, data))
		else:
			client.send('TIMEOUT')
		client.send('\n')
	def enable(self, client, value):
		print 'Enabling'
		self.servo_controller.sendCommand('PSE' + chr(self.channel))
	def disable(self, client, value):
		self.servo_controller.sendCommand('PSD' + chr(self.channel))

class ServoController(varserver.VarHandler):
	def __init__(self, s, server):
		varserver.VarHandler.__init__(self, 'FW_VERSION', 'FW_VERSION')
		self.s = s
		self.server = server
	def sendCommand(self, command):
		self.s.write('!SC' + command + '\r')
	def version(self, q_var, client):
		self.sendCommand('VER?')
		data = self.s.read(3)
		if len(data) > 0:
			client.send(data)
		client.send('\n')
	def handle_query(self, client):
		self.sendCommand('VER?')
		data = self.controller.read(3)
		client.send(data)
		client.send('\n')

