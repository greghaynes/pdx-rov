from servo import HS548Servo, HS564Servo, AnalogServo, INCREASE, DECREASE, STOP
from jsonserver import RequestError, InvalidArgumentError
import logging

arm_servos = {
	'gripper': (
		2, # teensy port
		HS548Servo, # Servo model
		800 #default value
		),
	'wrist': (
		1,
		AnalogServo,
		2223
		),
	'elbow': (
		5,
		HS548Servo,
		835
		),
	'shoulder': (
		3,
		HS564Servo,
		826
		),
	'pauldron': (
		4,
		HS564Servo,
		1549
		)
	}

class Arm(object):
	def __init__(self, teensy):
		self.joint_servo = {}
		for joint, servo_desc in arm_servos.items():
			self.joint_servo[joint] = servo_desc[1](
				servo_desc[2],
				servo_desc[0],
				teensy)
	def handle_command(self, client, request, command, arguments):
		try:
			joint_name = arguments['joint']
			magnitude = arguments['magnitude']
		except KeyError:
			raise RequestError('Insufficient Arguments')
		try:
			servo = self.joint_servo[joint_name]
		except KeyError:
			raise InvalidArgumentError('Bad Argument')
		logging.debug('Moving %s by %i' % (joint_name, magnitude))
		servo.move(magnitude)

