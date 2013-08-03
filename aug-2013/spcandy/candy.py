import sys
 
tests = int(sys.stdin.readline())

for test in range(tests):
        nk = sys.stdin.readline()
	n = long(nk.split(' ')[0])
	k = long(nk.split(' ')[1])

	if n == 0 and k == 0:
		print "0 0"
	else:
		if n > 0 and k == 0:
			print "0 " + str(n)
		else:
			print str(n / k) + " " + str(n % k)
