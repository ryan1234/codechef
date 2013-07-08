s = input()
C = set()
for q in [k * k for k in range(2, s + 1)]:
	i = 1
	while q * i <= s:
		C.add(q * i)
		i += 1
print s - len(C)
