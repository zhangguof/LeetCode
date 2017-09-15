#-*- coding:utf -*-
# 125. Valid Palindrome
# Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

# For example,
# "A man, a plan, a canal: Panama" is a palindrome.
# "race a car" is not a palindrome.

# Note:
# Have you consider that the string might be empty? This is a good question to ask during an interview.

# For the purpose of this problem, we define empty string as valid palindrome.

class Solution(object):
	def isPalindrome(self, s):
		"""
		:type s: str
		:rtype: bool
		"""
		if not s:
			return True
		def is_alph(c):
			ord_c = ord(c)
			ord_a = ord('a')
			ord_z = ord('z')
			ord_0 = ord('0')
			ord_9 = ord('9')
			return (ord_c >= ord_a and  ord_c<=ord_z) or (ord_c>=ord_0 and ord_c<=ord_9)
		L = list(s.lower())
		n = len(s)
		i,j = 0,n-1
		while i<j:
			while not is_alph(L[i]) and i<j:
				i+=1
			while not is_alph(L[j]) and i<j:
				j-=1
			if i<j:
				if L[i] != L[j]:
					return False
			i+=1
			j-=1
		return True


if __name__ == "__main__":
	sol = Solution()
	s1 = "A man, a plan, a canal: Panama"
	s2 = "0P"
	print sol.isPalindrome(s1)
	print sol.isPalindrome(s2)