import sys

def pow_mod(x, y, z):
    number = 1
    while y:
        if y & 1:
            number = number * x % z
        y >>= 1
        x = x * x % z
    return number

tests = int(raw_input())

for i in xrange(tests):
	n = int(raw_input())
	#print (pow(2, n) - 1) % 1000000007
	print pow_mod(2, n, 1000000007) - 1
