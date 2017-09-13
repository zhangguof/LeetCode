#-*- coding:utf-8 -*-
# Determine whether an integer is a palindrome. Do this without extra space.

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        t = x/10
        n10 = 1
        if x<0:
        	return False
        while t:
            t = t/10
            n10 *= 10
        while n10:
            t = x/n10
            if x%10 != t:
               return False
            x = x - t*n10
            x = x/10
            n10 = n10 / 100
            
        return True
            

if __name__ == "__main__":
	sol = Solution()
	print sol.isPalindrome(123321)
	print sol.isPalindrome(12321)
	print sol.isPalindrome(0)
