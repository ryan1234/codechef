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

	for spot in spots:
		print sorted(spots[spot], key=lambda x: x[1])
