from jsonserver import InvalidCommandError
import logging

temp_probes = {
	'Arm': 3,
	}

class Temperature(object):
	def __init__(self, teensy):
		self.teensy = teensy
		self.teensy.add_adc_listener(self.handle_temp_update)
		self.client_update_waiting = {}
	def handle_command(self, client, request, command, arguments):
		if command != 'query':
			raise InvalidCommandError(command)
		probe = arguments['probe']
		port = temp_probes[probe]
		try:
			self.client_update_waiting[port].append((client, probe))
		except KeyError:
			self.client_update_waiting[port] = [(client, probe)]
		self.teensy.send_command('\x07', chr(port))
	def handle_temp_update(self, port, value):
		try:
			for c_p in self.client_update_waiting[port]:
				client = c_p[0]
				probe = c_p[1]
				command = {
					'module': 'temperature',
					'command': 'query',
					arguments: {
						'probe': probe,
						'value': value
						}
					}
				client.send_response(0, command)
			del self.client_update_waiting[port]
		except KeyError:
			logging.error('Updated temp sensor but no clients waiting')
