import sys

def main():
        tests = int(raw_input())

        for i in xrange(tests):
                s = raw_input()

		if "010" in s or "101" in s:
			print "Good"
		else:
			print "Bad"

main()
