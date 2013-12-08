import sys

tests = int(raw_input())

for i in xrange(tests):
     	n = int(raw_input())
	n = n - 1
	array = raw_input()

	print n * (n + 1) / 2
