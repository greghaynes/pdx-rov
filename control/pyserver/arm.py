import from servo import HS548Servo, HS564Servo

arm_servos = {
	'gripper': (
		0, # teensy port
		HS548Servo, # Servo model
		800 #default value
		),
	'wrist': (
		1,
		AnalogServo,
		800
		)
	'elbow': (
		2,
		HS548Servo,
		800
		)
	'shoulder': (
		3,
		HS564Servo,
		800
		)
	}

class Arm(object):
	def __init__(self):
		pass
	

