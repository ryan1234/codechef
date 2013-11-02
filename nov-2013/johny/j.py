import sys
from bisect import bisect_left

def binary_search(a, x, lo=0, hi=None):   
    hi = hi if hi is not None else len(a) 
    pos = bisect_left(a,x,lo,hi)          
    return (pos if pos != hi and a[pos] == x else -1) 

def sort(array):
    less = []
    equal = []
    greater = []

    if len(array) > 1:
        pivot = array[0]
        for x in array:
            if x < pivot:
                less.append(x)
            if x == pivot:
                equal.append(x)
            if x > pivot:
                greater.append(x)
        return sort(less)+sort(equal)+sort(greater) 
    else:  
        return array

tests = int(raw_input())

for i in xrange(tests):
	array_size = int(raw_input())
	array = map(int, raw_input().split())
	johny = array[int(raw_input()) - 1]

	sorted_array = sort(array)
	print binary_search(sorted_array, johny) + 1
