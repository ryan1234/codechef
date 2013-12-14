from random import randint

n = 300

print "300"

for x in xrange(n):
	row = []

	for y in xrange(n):
		row.append(str(randint(1,10)))

	print ' '.join(row)

print str(pow(10,5))

for x in xrange(pow(10,5)):
	x1 = randint(1,150)
	y1 = randint(1,150)
	x2 = randint(x1,x1+50)
	y2 = randint(y1,y1+50)

	print str(x1) + " " + str(y1) + " " + str(x2) + " " + str(y2)

