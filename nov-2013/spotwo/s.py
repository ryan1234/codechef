import sys
import math

tests = int(raw_input())
#twos = [1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288]
twos = [524288, 262144, 131072, 65536, 32768, 16384, 8192, 4096, 2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1]

for i in xrange(tests):
	a = int(raw_input())

	num = 1

	new_power = int(bin(a)[2:])
	new_bin = str(bin(new_power)[2:]).zfill(20)

	print new_bin

	for index, c in enumerate(str(new_bin)):
		if c == "1":
			num = num * math.pow(2, twos[index]) * 1000000007

	print num
	print math.pow(num, 2) % 1000000007
