import sys
import math

tests = int(raw_input())

for i in xrange(tests):
	nums = map(float, raw_input().split())
	l = nums[0]
	d = nums[1]
	s = nums[2]
	c = nums[3]

	# answer = s * ((c + 1) ** (d - 1))
	# (l / s, c + 1) = d - 1
	answer = math.log(l / s, c + 1)

	if answer <= 1:
		print "ALIVE AND KICKING"
	else:
		print "DEAD AND ROTTING"
