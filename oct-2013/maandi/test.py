import sys

def factors(n):    
    return set(reduce(list.__add__,
                ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))
 
tests = int(sys.stdin.readline())

for test in range(tests):
	count = 0

	n = long(sys.stdin.readline())

	for i in factors(n):
		if ("4" in str(i) or "7" in str(i)):
			count = count + 1

	print count
