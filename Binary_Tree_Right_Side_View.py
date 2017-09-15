#-*- coding:utf-8 -*-
# Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

# For example:
# Given the following binary tree,
#    1            <---
#  /   \
# 2     3         <---
#  \     \
#   5     4       <---
# You should return [1, 3, 4].

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
	def rightSideView(self, root):
		"""
		:type root: TreeNode
		:rtype: List[int]
		"""
		if root is None:
			return []
		R = []
		rr = []
		rl = []
		R.append(root.val)
		if root.right is not None:
			rr = self.rightSideView(root.right)
		if root.left is not None:
			rl = self.rightSideView(root.left)
		R.extend(rr)
		if len(rl)>len(rr):
			R.extend(rl[len(rr):])

		return R




if __name__ == "__main__":
	sol = Solution()
	class TreeNode(object):
		def __init__(self, x):
			self.val = x
			self.left = None
			self.right = None
	nodes = []
	def make_tree(a,nodes):
		for n in a:
			if n is None:
				new_node = None
			else:
				new_node = TreeNode(n)
			nodes.append(new_node)
		for idx, node in enumerate(nodes):
			L = idx*2+1
			R = idx*2 + 2
			if L < len(nodes):
				node.left = nodes[L]
			if R < len(nodes):
				node.right = nodes[R]

	def print_pre(head,L):
		if head is not None:
			L.append(head.val)
			print_pre(head.left,L)
			print_pre(head.right,L)
			return L

	def print_inord(head,L):
		if head is not None:
			print_inord(head.left,L)
			L.append(head.val)
			print_inord(head.right,L)
			return L
	make_tree([4,3,6,1,None,5,None,None,2],nodes)
	head = nodes[0]
	print sol.rightSideView(head)

