#-*- coding:utf-8 -*-
#problem:
# Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

# For example, given the range [5, 7], you should return 4.


class Solution:
    # @param m, an integer
    # @param n, an integer
    # @return an integer
    def rangeBitwiseAnd(self, m, n):
        s = 0
        r = 0
        while m and n:
            if m==n:
                s += m<<r
                break
            m = m>>1
            n = n>>1
            r+=1
        return s



        

if __name__ == "__main__":
	sol = Solution()
	print sol.rangeBitwiseAnd(5,7)

        