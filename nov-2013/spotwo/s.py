import sys
import math

class Memoize:
    def __init__(self, f):
        self.f = f
        self.memo = {}
    def __call__(self, *args):
        if not args in self.memo:
            self.memo[args] = self.f(*args)
        return self.memo[args]

tests = int(raw_input())
twos = [58735347, 35084955, 833284959, 534981650, 444769176, 174683759, 914400619, 969233273, 879289042, 292441966, 577140940, 754326264, 73473749, 252824185, 404160288, 248097545, 338551618, 240149607, 803512230, 229407740, 772494375, 391524810, 994021262, 819855989, 994498569, 824187012, 134271769, 414682450, 476717689, 978311635, 213475114, 974674403, 829787081, 71108578, 915398907, 75265151, 215687307, 513497891, 816280417, 306292255, 405241093, 125918023, 164150368, 36221046, 998632880, 385894014, 125655169, 973586826, 669157962, 774491455, 112754241, 246797651, 409643880, 812734592, 418385479, 792845266, 279632277, 582344008, 294967268, 65536, 256, 16, 4, 2]

def get_answer(a):
        num = 1

        new_power = int(bin(a)[2:])
        new_bin = str(bin(new_power)[2:]).zfill(64)

        for index, c in enumerate(str(new_bin)):
                if c == "1":
                        num = num * twos[index] % 1000000007

	return pow(num, 2) % 1000000007

get_answer = Memoize(get_answer)

for i in xrange(tests):
	a = int(raw_input())

	print get_answer(a)
