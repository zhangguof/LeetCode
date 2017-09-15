# -*- coding:utf-8 -*-

# 150. Evaluate Reverse Polish Notation
# Evaluate the value of an arithmetic expression in Reverse Polish Notation.

# Valid operators are +, -, *, /. Each operand may be an integer or another expression.

# Some examples:
#   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
#   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

class Solution(object):
	def evalRPN(self, tokens):
		"""
		:type tokens: List[str]
		:rtype: int
		"""
		class Stack:
			def __init__(self):
				self.data = []
			def push(self,val):
				self.data.append(val)
			
			def pop(self):
				return self.data.pop(-1)
		def is_op(op):
			return op in ("+","-","*","/")

		def do_eval(num1,num2,op):
			#print "%d %s %d"%(num1,op,num2)
			if op == "+":
				return num1 + num2
			elif op == "-":
				return num1 - num2
			elif op == "*":
				return num1 * num2
			elif op == "/":
				if num1<0 and num2>0:
					return -(-num1/num2)
				if num1>0 and num2<0:
					return -(num1/-num2)
				return num1 / num2

		st = Stack()
		ret = 0
		for token in tokens:
			if not is_op(token):
				st.push(int(token))
			else:
				num2 = st.pop()
				num1 = st.pop()
				r = do_eval(num1,num2,token)
				st.push(r)
		return st.pop()



if __name__ == '__main__':
	sol = Solution()
	print sol.evalRPN(["4", "13", "5", "/", "+"])
	print sol.evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"])