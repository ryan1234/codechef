import sys
import psyco
 
psyco.full()
 
def Ugh(m):
        A = [0 for i in range(0, m)]
        A[0] = 1
        R = [1,1]
        for n in range(1, m):
                A[n] = A[0]
                for k in range(n, 0, -1):
                        A[k-1] = (A[k-1] + A[k]) % 1000000007
                R.append(A[0])
        return R
 
bs = Ugh(1000)
 
num = sys.stdin.readline()
i = int(num)
for Case in range(i):
        n = sys.stdin.readline()
        m = int(n)
        print(bs[m])
