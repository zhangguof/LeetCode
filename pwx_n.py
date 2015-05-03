#-*- coding:utf-8 -*-

class Solution:
    # @param {float} x
    # @param {integer} n
    # @return {float}
    def myPow(self, x, n):
    	if n == 0:
    		return 1
    	if n < 0:
    		return self.myPow(1.0/x,-n)
    	if n==1:
    		return x
    	if n%2 == 0:
    		y = self.myPow(x,n/2)
    		return y*y
    	else:
    		y = self.myPow(x,n/2)
    		return y*y*x


        

if __name__ == "__main__":
	sol = Solution()
	print sol.myPow(2,-3)

