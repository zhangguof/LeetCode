#-*- coding:utf-8 -*-

#problem
# Implement atoi to convert a string to an integer.

# Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

# Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

# Update (2015-02-10):
# The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

# spoilers alert... click to show requirements for atoi.

class Solution:
    # @param {string} str
    # @return {integer}
    def myAtoi(self, str):
    	INT_MIN = -(1<<31)
    	INT_MAX = (1<<31)-1
        x = 0
        sig = 1
        str = str.strip()
        if str.startswith("-"):
        	sig = -1
        	str = str[1:]
        elif str.startswith("+"):
        	str = str[1:]


        ord_0 = ord("0")
        ord_9 = ord("9")
        for s in str:
        	ord_s = ord(s)
        	if ord_s < ord_0 or ord_s > ord_9:
        		break
        	x = x * 10 + (ord(s)-ord_0)
        x = x * sig
        if x > INT_MAX:
        	return INT_MAX
        if x < INT_MIN:
        	return INT_MIN
        return x

if __name__ == "__main__":
	sol = Solution()
	print sol.myAtoi("2147483648")
	print sol.myAtoi("-+1")
	print sol.myAtoi("  -0012a42")
