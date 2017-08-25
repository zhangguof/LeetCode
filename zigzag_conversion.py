#-*- coding:utf-8 -*-

#problem

# The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

# P   A   H   N
# A P L S I I G
# Y   I   R
# And then read line by line: "PAHNAPLSIIGYIR"
# Write the code that will take a string and make this conversion given a number of rows:

# string convert(string text, int nRows);
# convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".


class Solution:
	# @param {string} s
	# @param {integer} numRows
	# @return {string}
	def convert(self, s, numRows):
		if numRows == 1:
			return s

		# def gen_next(nRows):
		# 	i=-1
		# 	ord_ = 1
		# 	while True:
		# 		if ord_ > 0:
		# 			i = i+1
		# 			if i >= nRows:
		# 				i = nRows - 2
		# 				ord_ = -1
		# 		else:
		# 			i = i-1
		# 			if i<0:
		# 				i = 1
		# 				ord_ = 1
		# 		yield i
		rows = [ [] for x in xrange(numRows)]
		# gen_idx = gen_next(numRows)

		idx = 0
		ord_dir = 1
		for a  in s:
			rows[idx].append(a)
			if ord_dir > 0:
				idx += 1
				if idx >= numRows:
					idx = numRows - 2
					ord_dir = -1
			else:
				idx -= 1
				if idx < 0:
					idx = 1
					ord_dir = 1

		ret = []
		for r in rows:
			#print r
			ret.append("".join(r))
		return "".join(ret)

if __name__ == "__main__":
	sol = Solution()
	print sol.convert("PAYPALISHIRING",3)
	print sol.convert("ABC",1)
	print sol.convert("ABCD",1)