#-*- coding:utf-8 -*-
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

#Problem
# Given a singly linked list L: L0→L1→…→Ln-1→Ln,
# reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

# You must do this in-place without altering the nodes' values.

# For example,
# Given {1,2,3,4}, reorder it to {1,4,2,3}.


# def print_list(head):
# 	msgs = []
# 	while head:
# 		msgs.append(str(head.val))
# 		head = head.next
# 	s = "->".join(msgs)
# 	print s

class Solution:
	# @param head, a ListNode
	# @return nothing
	def reorderList(self, head):
		if not head or not head.next:
			return
		mid = self.find_mid(head)
		# print "find mid."
		# print_list(mid)

		
		mid = self.revert(mid)
		# print "revert."
		# print_list(mid)

		# print "before merge."
		# print_list(head)
		# print_list(mid)

		self.merge(head,mid)

	def find_mid(self,head):
		p = head
		q = head
		last = None
		while q:
			q = q.next
			if q:
				last = p
				p = p.next
			else:
				break
			q = q.next
		if last:
			last.next = None
		return p
	def revert(self,head):
		p = head
		q = p.next
		while q:
			t = q.next
			q.next = p
			p = q
			q = t
		head.next = None
		return p

	def merge(self,head,mid):
		p = head
		q = mid
		while p and q:
			s = p.next
			t = q.next
			p.next = q
			if s:
				q.next = s
			p, q = s, t


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
	head = make_list([1,2,3,4,5,6,7])
	print_list(head)

	sol = Solution()
	sol.reorderList(head)
	print "res:"
	print_list(head)