import sys

def schedule_unweighted_intervals(I):
    I.sort(lambda x, y: x.finish - y.finish) 

    O = []
    finish = 0
    for i in I:
        if finish <= i.start:
            finish = i.finish
            O.append(i)

    return O

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

		spots[p].append((s, f, 1))

	print spots
	total = 0

	for key in spots:
		total += schedule_unweighted_intervals(spots[key])

	print total

G = [(100, 200), (150, 500), (200, 300)]
print schedule_unweighted_intervals(G)
#G = [(43,70,27),(3,18,24),(65,99,45),(20,39,26),(45,74,26),(10,28,20),(78,97,23),(0,9,22)]
#print weighted_interval_scheduling(G)
