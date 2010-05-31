import time

timers = []

def add_timer(secs, func, *args, **kwargs):
	timers.append((time.time() + secs, func, args, kwargs))

def update():
	cur_time = time.time()
	for i in xragne(len(timers)):
		if timers[i][0] <= cur_time:
			tup = timers[i]
			func = tup[1]
			args = tup[2]
			kwargs = tup[3]
			func(*args, **kwargs)
			del timers[i]

