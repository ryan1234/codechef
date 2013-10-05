import sys
import math

def get_mid(ss, se):
	return ss + (se - ss) // 2

def get_left_index(index):
	return 2*index+1

def get_right_index(index):
	return 2*index+2

def getProductRecursive(st, ss, se, l, r, index, m):
    if (l <= ss and r >= se):
        return st[index]

    if (se < l or ss > r):
        return 1

    mid = get_mid(ss, se)

    left_index = get_left_index(index)
    right_index = get_right_index(index)

    return getProductRecursive(st, ss, mid, l, r, left_index, m) % m * getProductRecursive(st, mid+1, se, l, r, right_index, m) % m


class Segment(object):
    __slots__ = ['ss', 'se', 'index']

def getProductIterative(st, ss, se, l, r, index, m):
    segment = Segment()
    segment.ss = ss
    segment.se = se
    segment.index = index
    
    stack = []
    stack.append(segment)
    stack_index = 1
    total = 1
    
    while stack_index > 0:
	segment = stack[0]
        stack = stack[1:]
	stack_index -= 1

	if (l <= segment.ss and r >= segment.se):
		tree_val = st[segment.index] % m
		total = (total * tree_val) % m
	else:
		if (segment.se < l or segment.ss > r):
			total *= 1
		else:
			mid = segment.ss + (segment.se - segment.ss) / 2

			segment_left = Segment()
			segment_left.ss = segment.ss
			segment_left.se = mid
			segment_left.index = 2*segment.index+1			

			segment_right = Segment()
			segment_right.ss = mid+1
			segment_right.se = segment.se
			segment_right.index = 2*segment.index+2

			stack.append(segment_left)
			stack.append(segment_right)
			stack_index += 2

    return total

def constructSTUtil(arr, ss, se, st, si):
    if (ss == se):
        st[si] = arr[ss]
        return arr[ss]

    mid = ss + (se - ss) / 2
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) * constructSTUtil(arr, mid+1, se, st, si*2+2)
    return st[si]

def constructST(arr, n):
    x = int(math.ceil(math.log(n, 2)))
    max_size = 2 * pow(2, x) - 1
    st = [None] * max_size

    constructSTUtil(arr, 0, n-1, st, 0)

    return st

array_size = int(raw_input())
array = map(int, raw_input().split())
st = constructST(array, array_size)

segment_count = int(raw_input())

for z in xrange(segment_count):
	lrm = map(int, raw_input().split())
	l = lrm[0] - 1 
	r = lrm[1] - 1
	m = lrm[2]

	print getProductIterative(st, 0, array_size - 1, l, r, 0, m) % m
