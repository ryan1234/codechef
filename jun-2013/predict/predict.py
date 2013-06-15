import sys

num = sys.stdin.readline()
i = int(num)
for Case in range(i):
        n = sys.stdin.readline()
        p = float(n)

	x = float(0)

	if (p > 0.5):
		x = float(10000)
	else:
		x = float(0)

	total = float(10000)
	result = ((total + ((2 * (1 - p)) * x) - (total - x)) * p) + ((total + (2 * (1 - (1 - p))) * (total - x) - (total - (total - x))) * (1 - p))
	print "%.6f" % result
