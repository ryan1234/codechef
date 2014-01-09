from random import randint

print "30"

for i in xrange(30):
	print "10000 1000000000"
	
	for j in xrange(10000):
		start = randint(1, 50000000)
		end = randint(start + 1, 1000000000)
		index = randint(1, 1000)
		print str(start) + " " + str(end) + " " + str(index)
