#-*- coding:utf-8 -*-
# 216. Combination Sum III   QuestionEditorial Solution  My Submissions
# Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


# Example 1:

# Input: k = 3, n = 7

# Output:

# [[1,2,4]]

# Example 2:

# Input: k = 3, n = 9

# Output:

# [[1,2,6], [1,3,5], [2,3,4]]

class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        r = []
        nums = [1,2,3,4,5,6,7,8,9]
        def combin_num(index,ik,sum,L):
        	if sum < 0:
        		return
        	if ik == k-1:
        		#print "index:",index
        		for i in xrange(index,9):
        			L[ik] = nums[i]
        			if sum == nums[i]:
        				r.append(L[:])
        		return
        	for i in xrange(index,9):
        		L[ik] = nums[i]
        		combin_num(i+1,ik+1,sum-nums[i],L)
       	combin_num(0,0,n,[None]*k)
       	return r






if __name__ == "__main__":
	sol = Solution()
	print sol.combinationSum3(3,9)
