#-*- coding:utf-8 -*-
# Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

# For example,
# If n = 4 and k = 2, a solution is:

# [
#   [2,4],
#   [3,4],
#   [2,3],
#   [1,2],
#   [1,3],
#   [1,4],
# ]
# Subscribe to see which companies asked this question

class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """

        if n==1 and k==1:
        	return [[1]]
        if k==0:
        	return [[]]
        if k==n:
        	return[list(xrange(1,n+1))]

        a = self.combine(n-1,k-1)
        #print "(n:%d,k:%d),a=:"%(n,k),a
        for i in a:
        	i.append(n)
        b = self.combine(n-1,k)
        # print "(n:%d,k:%d),b=:"%(n,k),b
        # print "(n:%d,k:%d),a=:"%(n,k),a
        a.extend(b)
        return a

if __name__ == "__main__":
	sol = Solution()
	def test(n,k):
		print "combine(%d,%d)=:"%(n,k),sol.combine(n,k)
	
	test(1,1)
	test(2,1)
	test(2,2)
	test(3,1)
	test(3,2)
	test(3,3)
	test(4,2)
	test(4,3)
	test(5,5)


