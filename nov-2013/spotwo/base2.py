import math

twos = []

for i in xrange(64):
	twos.append(math.pow(2, math.pow(2, i)) % 1000000007)

print twos
