import sys

@profile
def main():
	n = int(sys.stdin.readline())

	a = []

	for i in xrange(n):
		a = a + map(int, sys.stdin.readline().split())

	tests = int(sys.stdin.readline())

	for test in xrange(tests):
        	q = map(int, sys.stdin.readline().split())
	        x1 = q[0]
        	y1 = q[1]
	        x2 = q[2]
        	y2 = q[3]

		startIndex = (n * (x1 - 1)) + (y1 - 1)
		rowLength = (y2 - y1) + 1
		rowCount = (x2 - x1) + 1
		offset = n - rowLength

		i = startIndex

		bv = 0

		for row in xrange(rowCount):
			br = i
			er = rowLength + i - 1
	
			if (br == er):
				bv |= 1 << a[br] - 1		
			else:
				for x in xrange(br, er + 1):
					bv |= 1 << a[x] - 1
					if bv == 1023:
						break

			if bv == 1023:
				break
	
			i = i + offset + rowLength

		print bin(bv).count("1")

main()
