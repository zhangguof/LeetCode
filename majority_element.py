#-*- coding:utf-8 -*-

#problem

# Given an array of size n, find the majority element. 
#The majority element is the element that appears more than n/2 times.

# You may assume that the array is non-empty and the majority element always exist in the array.

class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def majorityElement(self, nums):
    	pass



    # @param {integer[]} nums
    # @return {integer}
    def _majorityElement(self, nums):
    	n = len(nums)
    	max_count = 0
    	max_num = None
    	num_counts = {}
    	for num in nums:
    		if num not in num_counts:
    			num_counts[num] = 0
    		num_counts[num] += 1
    		if num_counts[num] > max_count:
    			max_count = num_counts[num]
    			max_num = num
    	print num_counts
    	return max_num





if __name__=="__main__":
	sol = Solution()
	print sol.majorityElement([6,5,5])
	print sol.majorityElement([3,3,4])
