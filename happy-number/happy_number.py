#-*- coding:utf-8 -*-
#problem:
# Write an algorithm to determine if a number is "happy".

# A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

# Example: 19 is a happy number

# 1^2 + 8^2 = 82
# 8^2 + 2^2 = 68
# 6^2 + 8^2 = 100
# 1^2 + 0^2 + 0^2 = 1


class Solution:
    # @param {integer} n
    # @return {boolean}
    def isHappy(self, n):
    	if n == 1:
    		return True
    	has_used = {}
    	has_used[n] = 1

    	while True:
    		s = 0
    		t = n
    		while t:
    			r = t%10
    			s += r * r
    			t /= 10
    		#print s
    		if s in has_used:
    			return False
    		if s == 1:
    			return True

    		has_used[s] = 1
    		n = s


if __name__ == "__main__":
	sol = Solution()
	print sol.isHappy(1)
        