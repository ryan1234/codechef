import sys

def main():
	inp = map(int, sys.stdin.read().split())

	a = []
	n = inp[0]
	readAt = 1

	for i in xrange(n):
		a = a + inp[readAt:readAt + n]
		readAt += n

	tests = inp[readAt]
	readAt += 1

	for test in xrange(tests):
		q = inp[readAt:readAt + 4]
		readAt += 4
		x1 = q[0]
		y1 = q[1]
		x2 = q[2]
		y2 = q[3]

		d = {}
		count = 0

		startIndex = (n * (x1 - 1)) + (y1 - 1)
		rowLength = (y2 - y1) + 1
		rowCount = (x2 - x1) + 1
		offset = n - rowLength

		i = startIndex

		for row in xrange(rowCount):
			br = i
			er = rowLength + i

			for x in xrange(br, er):
				if not a[x] in d:
					count += 1
					d[a[x]] = 1
					if count == 10:
						break

			if count == 10:
				break
	
			i += offset + rowLength

	sys.stdout.write(str(count) + "\n")
main()
