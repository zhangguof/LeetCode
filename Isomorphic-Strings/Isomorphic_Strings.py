#-*- coding:utf-8 -*-

# Given two strings s and t, determine if they are isomorphic.

# Two strings are isomorphic if the characters in s can be replaced to get t.

# All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

# For example,
# Given "egg", "add", return true.

# Given "foo", "bar", return false.

# Given "paper", "title", return true.

class Solution(object):
	def isIsomorphic(self, s, t):
		"""
	:type s: str
	:type t: str
	:rtype: bool
	"""
		s_m = {}
		t_m = {}
		s_len = len(s)
		for i in xrange(0,s_len):
			s_c, t_c = s[i], t[i]
			if s_c not in s_m:
				s_m[s_c] = t_c
			if t_c not in t_m:
				t_m[t_c] = s_c
			if t_c != s_m[s_c]:
				print s_m,t_m
				return False
			if s_c != t_m[t_c]:
				print s_m,t_m
				return False
		#print s_m,t_m
		return True

if __name__=="__main__":
	sol = Solution()
	print sol.isIsomorphic("add","egg")
	print sol.isIsomorphic("foo","bar")
	print sol.isIsomorphic("paper","title")
	print sol.isIsomorphic("ab","aa")
