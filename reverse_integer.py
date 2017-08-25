#-*- coding:utf-8 -*-

#problem
# Reverse digits of an integer.

# Example1: x = 123, return 321
# Example2: x = -123, return -321

class Solution:
    # @param {integer} x
    # @return {integer}
    def reverse(self, x):
        a = 0
        sig = -1 if x < 0 else 1
        x = abs(x)
        while x != 0:
        	a = a*10 + x % 10
        	x /= 10
        a = a * sig
        if a < -(1<<31) or a > ((1<<31) -1  ):
        	return 0
        return a


if __name__=="__main__":
	sol = Solution()
	print sol.reverse(123)
	print sol.reverse(-123)
	print sol.reverse(sol.reverse(2**32))
