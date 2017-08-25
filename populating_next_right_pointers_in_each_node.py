#-*- coding:utf-8 -*-

#problem

# Given a binary tree

#	 struct TreeLinkNode {
#	   TreeLinkNode *left;
#	   TreeLinkNode *right;
#	   TreeLinkNode *next;
#	 }
# Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

# Initially, all next pointers are set to NULL.

# Note:

# You may only use constant extra space.
# You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
# For example,
# Given the following perfect binary tree,
#		  1
#		/  \
#	   2	3
#	  / \  / \
#	 4  5  6  7
# After calling your function, the tree should look like:
#		  1 -> NULL
#		/  \
#	   2 -> 3 -> NULL
#	  / \  / \
#	 4->5->6->7 -> NULL


# Definition for binary tree with next pointer.
# class TreeLinkNode:
#	 def __init__(self, x):
#		 self.val = x
#		 self.left = None
#		 self.right = None
#		 self.next = None

class Solution:
	# @param root, a tree link node
	# @return nothing
	def connect(self, root):
		p1 = root
		#print "root:%s"%str(root.val),root.left
		while p1:
			#print p1.val
			p2 = p1.next
			if p1.left and p1.right:
				p1.left.next = p1.right
			if p2:
				p1.right.next = p2.left
				p2.left.next = p2.right
			# if p1.right and p2 and p2.left:
			# 	p1.right.next = p2.left
			# if p2 and p2.left and p2.right:
			# 	p2.left.next = p2.right
			p1 = p2
		if root and root.left and root.left.left:
			self.connect(root.left)

			
		# left = root.left
		# right = root.right
		# if left and right:
		# 	left.next = right
		# 	# if left.right and right.left:
		# 	# 	left.right.next = right.left

		# 	p1, p2 = left, left.next
		# 	while p2:
		# 		if p1.right and p2.left:
		# 			p1.right.next = p2.left
		# 		p1 = p2
		# 		p2 = p2.next

		# if left and left.right and right and right.left:
		# 	left.right.next = right.left

		# if left:
		# 	self.connect(left)
		# if right:
		# 	self.connect(right)


if __name__=="__main__":
	class TreeNode:
		def __init__(self, x):
			self.val = x
			self.left = None
			self.right = None
			self.next = None

	def make_tree(node,val,limit):
		#node.val = val
		if 2*val <= limit:
			node.left = TreeNode(2*val)
			make_tree(node.left,2*val,limit)

		if 2*val + 1 <= limit:
			node.right = TreeNode(2*val + 1)
			make_tree(node.right,2*val+1,limit)


	def print_tree(node):
		if not node:
			return ""
		return str(node.val) + " " + str(print_tree(node.left)) + str(print_tree(node.right))+" "

	def print_link(node):
		head = node
		msg = []
		while head:
			msg.append(str(head.val))
			head = head.next
		print "->".join(msg)

	def print_left(node):
		if not node:
			return
		print_link(node)
		print_left(node.left)


			

	root = TreeNode(1)
	make_tree(root,1,1)
	print print_tree(root)
	print "============"
	sol = Solution()
	sol.connect(root)
	print_left(root)
