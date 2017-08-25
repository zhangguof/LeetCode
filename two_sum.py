#-*- coding:utf-8 -*-

#problem
# Given an array of integers, find two numbers such that they add up to a specific target number.

# The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

# You may assume that each input would have exactly one solution.

# Input: numbers={2, 7, 11, 15}, target=9
# Output: index1=1, index2=2


class Solution:
	# @param {integer[]} nums
	# @param {integer} target
	# @return {integer[]}
	def twoSum(self, nums, target):
		num2index = {}
		for index,num in enumerate(nums, start=1):
			if num not in num2index:
				num2index[num] = []
			num2index[num].append(index)
		for i,num in enumerate(nums, start=1):
			num2 = target - num
			indexs = num2index.get(num2,[])
			if indexs:
				if len(indexs) > 1:
					return i, indexs[-1]
				if indexs[0] == i:
					continue
				return i, indexs[0]	




if __name__ == "__main__":
	sol = Solution()
	print sol.twoSum([0,4,3,0],0)