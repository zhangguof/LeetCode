#-*- coding:utf-8 -*-
# Write a program to find the n-th ugly number.

# Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

# Note that 1 is typically treated as an ugly number.

import heapq
g_n = {1:1}
class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
        	return 1
        def min(a,b,c):
        	r = a
        	if a>b:
        		r = b
        	if r>c:
        		r = c
        	return r
        p2,p3,p5 = 0,0,0
        p,count = 1,1
        a = [0] * n
        a[0] = 1
        #print "n:",n
        while count<n:
        	a[p] = min(a[p2]*2,a[p3]*3,a[p5]*5)
        	while a[p2]*2 <= a[p]:
        		p2+=1
        	while a[p3]*3 <= a[p]:
        		p3+=1
        	while a[p5]*5 <= a[p]:
        		p5+=1
        	p+=1
        	count+=1
        return a[p-1]



        if n == 1:
        	return 1
        a = 1
        L1,L2,L3 = L1

    def nthUglyNumber1(self, n):
        """
        :type n: int
        :rtype: int
        """

        heap_set = set()
        def push(heap,x):
        	if x not in heap_set:
        		heapq.heappush(heap,x)
        		heap_set.add(x)
        def pop(heap):
        	r = heapq.heappop(heap)
        	heap_set.remove(r)
        	return r

        if n==1:
        	return 1
        if n in g_n:
        	return g_n[n]
        heap = []
        heapq.heapify(heap)
        a = 1
        for i in xrange(2,n+1):
        	push(heap,a*2)
        	push(heap,a*3)
        	push(heap,a*5)
        	a = pop(heap)
        	g_n[i] = a

        return a


if __name__ == "__main__":
	sol = Solution()
	print sol.nthUglyNumber(1)
	print sol.nthUglyNumber(2)
	print sol.nthUglyNumber(3)
	print sol.nthUglyNumber(4)
	print sol.nthUglyNumber(10)



