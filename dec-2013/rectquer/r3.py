import sys

n = int(sys.stdin.readline())

a = []

for i in range(n):
	a = a + list(map(int, sys.stdin.readline().split()))

tests = int(sys.stdin.readline())

for test in range(tests):
	q = list(map(int, sys.stdin.readline().split()))
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

	for row in range(rowCount):
		br = i
		er = rowLength + i

		for x in range(br, er):
			if not a[x] in d:
				count = count + 1
				d[a[x]] = 1
				if count == 10:
					break

		if count == 10:
			break
	
		i = i + offset + rowLength

	print(count)
