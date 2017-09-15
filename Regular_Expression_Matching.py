#-*- coding:utf-8 -*-
 # 10. Regular Expression Matching
# implement regular expression matching with support for '.' and '*'.

# '.' Matches any single character.
# '*' Matches zero or more of the preceding element.

# The matching should cover the entire input string (not partial).

# The function prototype should be:
# bool isMatch(const char *s, const char *p)

# Some examples:
# isMatch("aa","a") → false
# isMatch("aa","aa") → true
# isMatch("aaa","aa") → false
# isMatch("aa", "a*") → true
# isMatch("aa", ".*") → true
# isMatch("ab", ".*") → true
# isMatch("aab", "c*a*b") → true

class DFA:
	def __init__(self,s):
		self.s = s
		self.stats = {}
		self.moves = {} #moves[state][ch]->(new_state,state2)
		self.has_start = {}
		self.stat_cnt = 0
		self.init_stats()

	def init_stats(self):
		s = self.s + "$"
		stat_cnt = 1
		self.stats[0] = None
		self.moves[0] = {}
		self.has_start[0] = True

		
		for ch in s:
			if ch != "*":
				#a*a -> a+
				# if self.has_start.get(stat_cnt-1) == ch:
				# 	continue

				self.stats[stat_cnt] = ch
				self.moves[stat_cnt] = {}
				#self.moves[stat_cnt-1][ch] = stat_cnt
				self.add_move(stat_cnt-1,ch,stat_cnt)
				i = stat_cnt-1
				
				while (i>0 and self.has_start.get(i,"")):
					#self.moves[i-1][ch] = stat_cnt
					self.add_move(i-1,ch,stat_cnt)
					i = i-1
				stat_cnt += 1
			else:
				stat_ch = self.stats[stat_cnt-1]
				#self.moves[stat_cnt-1][stat_ch] = stat_cnt-1
				self.add_move(stat_cnt-1,stat_ch,stat_cnt-1)
				self.has_start[stat_cnt-1] = stat_ch

		self.stat_cnt = stat_cnt
				
		# self.stats[stat_cnt] = "$" 
		# self.moves[stat_cnt-1]["$"] = stat_cnt
	def add_move(self,cur_stat,ch,new_state):
		old_states = self.moves[cur_stat].get(ch)
		if old_states is None:
			self.moves[cur_stat][ch] = [new_state,]
		else:
			old_states.append(new_state)

	def get_next_state(self,cur_stat,ch):
		next_stats = []
		if self.moves[cur_stat].get(ch):
			next_stats.extend(self.moves[cur_stat][ch])
		if "." in self.moves[cur_stat]:
			next_stats.extend(self.moves[cur_stat]['.'])
		return next_stats


	def do_match(self,s,cur_stat=0):
		#cur_stat = 0
		# s = s+"$"
		#print 'matching:',s,cur_stat
		final_stat = self.stat_cnt-1
		for idx,ch in enumerate(s):
			next_stats = self.get_next_state(cur_stat,ch)
			if next_stats is None:
				return False
			if len(next_stats) == 1:
				cur_stat = next_stats[0]
			else:
				for next_st in next_stats:
					r = self.do_match(s[idx+1:],next_st)
					#print "r:",r,ch,next_st,s[idx+1:]
					if r:
						return r
				return False
		if cur_stat!=final_stat:
			return False
		return True



class Solution(object):
	def isMatch(self, s, p):
		"""
		:type s: str
		:type p: str
		:rtype: bool
		"""
		dfs = DFA(p)
		#print dfs.moves
		#print dfs.has_start
		s = s+"$"
		return dfs.do_match(s)

if __name__ == "__main__":
	sol = Solution()
	# print sol.isMatch("aab","aab")
	# print sol.isMatch("cdaab","c*a*b")
	# print sol.isMatch("ab", ".*")
	# print sol.isMatch("aaa", "a*a")
	# print sol.isMatch("aaa", "ab*a*c*a")
	# print sol.isMatch("aaa","a*a*a")
	# print sol.isMatch("aaba","ab*a*c*a")
	# print sol.isMatch("abcdede","ab.*de")

