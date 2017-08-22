#-*- coding:utf-8 -*-
#problem

# Given an array of integers, every element appears twice except for one. Find that single one.

# Note:
# Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?



class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def singleNumber(self, nums):
    	x = nums[0];
        for n in nums[1:]:
        	x ^= n
        return x

if __name__ == "__main__":
	solution = Solution()
	print solution.singleNumber([1,2,3,1,2,3,4])
