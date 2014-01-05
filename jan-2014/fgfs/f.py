import sys

@profile
def main():
	inp = map(int, sys.stdin.read().split())

	tests = inp[0]
	readAt = 1

	for test in xrange(tests):
		nk = inp[readAt:readAt + 2]
		readAt += 2

		spots = {}

		for nn in xrange(nk[0]):
			sfp = inp[readAt:readAt + 3]
			readAt += 3

			s = sfp[0]
			f = sfp[1]
			p = sfp[2]

			if not p in spots:
				spots[p] = []

			spots[p].append((s, f))
		total = 0

		for spot in spots:
			ss = sorted(spots[spot], key=lambda x: x[1])
			finish = 0
			for s in ss:
				if finish <= s[0]:
					finish = s[1]
					total += 1
		print total

main()
