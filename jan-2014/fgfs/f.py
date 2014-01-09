import sys

tests = int(raw_input())

for test in xrange(tests):
	nk = map(int, raw_input().split())
	n = nk[0]
	k = nk[1]

	spots = {}

	for nn in xrange(n):
		sfp = map(int, raw_input().split())
		s = sfp[0]
		f = sfp[1]
		p = sfp[2]

		if not p in spots:
			spots[p] = []

		spots[p].append((s, f))

	total = 0

	for spot in spots:
		ss = sorted(spots[spot], key=lambda x: x[1])
		O = []
		finish = 0
		for s in ss:
			if finish <= s[0]:
				finish = s[1]
				O.append(s)

		total += len(O)

	print total
