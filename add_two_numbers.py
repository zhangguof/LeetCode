#-*- coding:utf -*- 

#problem
# You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

# Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 0 -> 8




# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#		self.val = x
#         self.next = None

class Solution:
	# @param {ListNode} l1
	# @param {ListNode} l2
	# @return {ListNode}
	def addTwoNumbers(self, l1, l2):
		p1, p2 = l1, l2
		head = None
		p0 = head
		hbit = 0
		while p1 or p2:
			a = p1.val if p1 else 0
			b = p2.val if p2 else 0
			s = a + b + hbit

			hbit = s/10
			x = s%10

			if not head:
				head = ListNode(x)
				p0 = head
			else:
				p0.next = ListNode(x)
				p0 = p0.next	
			if p1:
				p1 = p1.next
			if p2:
				p2 = p2.next
		#print hbit

		while hbit!=0:
			x = hbit % 10
			hbit = hbit / 10
			p0.next = ListNode(x)
			p0 = p0.next
		return head


# if __name__=="__main__":
# 	class Node:
# 		def __init__(self, x):
# 			self.val = x
# 			self.next = None

# 	def make_list(L):
# 		head = Node(L[0])
# 		p = head
# 		for l in L[1:]:
# 			p.next = Node(l)
# 			p = p.next
# 		return head
# 	def print_list(L):
# 		list0 = []
# 		while L:
# 			list0.append(str(L.val))
# 			L = L.next
# 		print "->".join(list0)
# 		return list0
# 	sol = Solution()
# 	head = sol.addTwoNumbers(make_list([0]),make_list([0]))
# 	print_list(head)