import sys

@profile
def main():
	inp = map(int, sys.stdin.read().split())

	n = inp[0]
	readAt = 1 + (n * n)

	tests = inp[readAt]
	readAt += 1

	for test in xrange(tests):
		q = inp[readAt:readAt + 4]
		readAt += 4
		#x1 = q[0]
		#y1 = q[1]
		#x2 = q[2]
		#y2 = q[3]

		d = {}
		count = 0

		startIndex = (n * (q[0] - 1)) + (q[1] - 1)
		rowLength = (q[3] - q[1]) + 1
		rowCount = (q[2] - q[0]) + 1
		offset = n - rowLength

		i = startIndex + 1
	
		for row in xrange(rowCount):
			br = i
			er = rowLength + i

			for x in xrange(br, er):
				if not inp[x] in d:
					count += 1
					d[inp[x]] = 1
					if count == 10:
						break

			if count == 10:
				break
	
			i += offset + rowLength

		print count

main()
