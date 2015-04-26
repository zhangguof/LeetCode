#-*- #-*- coding:utf-8 -*-
# Definition for singly-linked list.
# class ListNode:
#	 def __init__(self, x):
#         self.val = x
#         self.next = None

#Problem
# Remove all elements from a linked list of integers that have value val.

# Example
# Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
# Return: 1 --> 2 --> 3 --> 4 --> 5

# def print_list(head):
# 	msgs = []
# 	while head:
# 		msgs.append(str(head.val))
# 		head = head.next
# 	s = "->".join(msgs)
# 	print s

class Solution:
	# @param {ListNode} head
	# @param {integer} val
	# @return {ListNode}
	def removeElements(self, head, val):
		while head and head.val == val:
			head = head.next
		if not head:
			return

		p = head
		q = p.next
		while p and q:
			#print "p:%s,q:%s"%(p.val,q.val)
			while q and q.val == val:
				q = q.next
			p.next = q
			p = q
			
			if p:
				q = p.next
		return head





if __name__ == "__main__":
	class ListNodeTest:
		def __init__(self, x):
			self.val = x
			self.next = None
	def print_list(head):
		msgs = []
		while head:
			msgs.append(str(head.val))
			head = head.next
		s = "->".join(msgs)
		print s


	def make_list(L):
		head = ListNodeTest(L[0])
		p = head
		for l in L[1:]:
			p.next = ListNodeTest(l)
			p = p.next
		return head
	# head = make_list([6,1,2,3,4,5,6,7,6])
	head = make_list([6,6,6,6,1,2,6,4,6])
	print_list(head)

	sol = Solution()
	head = sol.removeElements(head,6)
	print "res:"
	print_list(head)