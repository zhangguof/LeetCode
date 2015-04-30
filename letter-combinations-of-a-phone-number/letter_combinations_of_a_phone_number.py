#-*- coding:utf-8 -*-

#problem
# Given a digit string, return all possible letter combinations that the number could represent.

# A mapping of digit to letters (just like on the telephone buttons) is given below.



# Input:Digit string "23"
# Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

class Solution:
	# @param {string} digits
	# @return {string[]}
	digits2letters={
	"2":"abc","3":"def",
	"4":"ghi","5":"jkl","6":"mno",
   	"7":"pqrs","8":"tuv","9":"wxyz",
	}
	def get_letter(self,d):
		if d not in Solution.digits2letters:
			return ""

	def get_str_list(self,digits):
		if not digits:
			return []
		if len(digits) == 1:
			d = digits[0]
			return list(self.digits2letters.get(d,""))

		d = digits[0]
		Letters = self.digits2letters.get(d,"")
		suf_letters = self.get_str_list(digits[1:])
		if not Letters:
			return suf_letters
		if not suf_letters:
			return list(Letters)
		str_list = []
		
		for L in Letters:
			for sl in suf_letters:
				str_list.append(L+sl)
		return str_list

	def letterCombinations(self, digits):
		return self.get_str_list(digits)


if __name__ == "__main__":
	sol = Solution()
	print sol.letterCombinations("")

