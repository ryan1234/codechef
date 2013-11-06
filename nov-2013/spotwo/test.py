nums = []

for i in reversed(xrange(64)):
	print i
	nums.append( pow(2, pow(2, i), 1000000007) )

print nums
