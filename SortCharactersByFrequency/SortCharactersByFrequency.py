#-*- coding:utf-8 -*-

# 451. Sort Characters By Frequency   QuestionEditorial Solution  My Submissions
# Given a string, sort it in decreasing order based on the frequency of characters.

# Example 1:

# Input:
# "tree"

# Output:
# "eert"

# Explanation:
# 'e' appears twice while 'r' and 't' both appear once.
# So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
# Example 2:

# Input:
# "cccaaa"

# Output:
# "cccaaa"

# Explanation:
# Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
# Note that "cacaca" is incorrect, as the same characters must be together.
# Example 3:

# Input:
# "Aabb"

# Output:
# "bbAa"

# Explanation:
# "bbaA" is also a valid answer, but "Aabb" is incorrect.
# Note that 'A' and 'a' are treated as two different characters.

class PriQue:
	def __init__(self,data=None,char_set={}):
		if data == None:
			data = [None] * 256
			size = 0
		else:
			size = len(data)
		self.char_set = char_set
		self.size = size
		self.que = data[:]
		if size == 0:
			return
		#O(n)
		for i in xrange((size-1)/2,-1,-1):
			self.heapfiy(size,i)
	
	def swap(self,i,j):
		char_set = self.char_set
		a = self.que
		a[i],a[j] = a[j],a[i]
		#ci,cj = ord(a[i][0]),ord(a[j][0])
		ci,cj = a[i][0],a[j][0]
		char_set[ci],char_set[cj] = char_set[cj],char_set[ci]
	
	def heapfiy(self,root=0):
		a = self.que
		size = self.size
		#O(lgn)
		def Left(i):
			return i*2 + 1
		def Right(i):
			return i*2 + 2
		def parent(i):
			return (i-1)/2
		l = Left(root)
		r = Right(root)
		large_idx = root
		if l < size and a[root][1] < a[l][1]:
			large_idx = l
		if r < size and a[large_idx][1] < a[r][1]:
			large_idx = r
		if large_idx != root:
			self.swap(large_idx,root)
			self.heapfiy(large_idx)
	def pop(self):
		#O(lgn)
		if self.size == 0:
			return None
		val = self.que[0]
		self.size -= 1
		self.que[0] = self.que[self.size]
		self.heapfiy()
		return val
	def insert(self,val):
		self.que[self.size] =[val[0],0]
		self.char_set[val[0]] = self.size
		self.size += 1
		return self.add_key_val(self.size-1,val)

	def add_key_val(self,idx,val):
		a = self.que
		assert a[idx][0] == val[0]
		a[idx][1] += val[1]
		
		p = (idx-1)/2
		while idx > 0 and a[idx][1] > a[p][1]:
			#a[idx],a[p] = a[p], a[idx]
			self.swap(idx,p)
			idx = p
			p = (idx-1)/2
		return idx


class Solution(object):
	def frequencySort(self, s):
		"""
		:type s: str
		:rtype: str
		"""
		#char_set = [None] * 256
		char_set = {}

		# q  = PriQue([2,3,4,5,1,10,7,8,6])
		# print q.pop()
		# print q.que
		q = PriQue(char_set=char_set)

		
		for c in s:
			if char_set.get(c) == None:
				q.insert([c,1])
				#char_set[ord(c)] = idx
			else:
				idx = char_set[c]
				q.add_key_val(idx,[c,1])

		top = q.pop()
		ret = []
		while top:
			c,cnt = top
			ret.append(c*cnt)
			top = q.pop()
		return "".join(ret)




t = "a"*1000+"b"*500+"a"*1000+"c"*1000000
def test():
	sol = Solution()
	# print sol.frequencySort("tree")
	# print sol.frequencySort("cccaaa")
	# print sol.frequencySort("bbAa")
	# print sol.frequencySort("raaeaedere")
	sol.frequencySort(t)



if __name__ == "__main__":
	#test()
	import cProfile
	cProfile.run("test()")





