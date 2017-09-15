#-*- coding:utf-8 -*- 

# Given preorder and inorder traversal of a tree, construct the binary tree.

# Note:
# You may assume that duplicates do not exist in the tree.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
	def buildTree(self, inorder, postorder):
		"""
		:type inorder: List[int]
		:type postorder: List[int]
		:rtype: TreeNode
		"""
		def _build_tree(inorder,postorder):
			if not inorder:
				return None
			node = TreeNode(postorder[-1])
			#print "nodes:",inorder,postorder
			idx = inorder.index(postorder[-1])
			
			L_inorder = inorder[:idx]
			L_post = postorder[:len(L_inorder)]

			R_inorder = inorder[idx+1:]
			R_post = postorder[len(L_inorder):-1]

			if len(L_post) == 0:
				L = None
			else:
				L = _build_tree(L_inorder,L_post)
			
			if len(R_post) == 0:
				R = None
			else:
				R = _build_tree(R_inorder,R_post)
			node.left = L
			node.right = R
			return node
		return _build_tree(inorder,postorder)



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

	def print_inord(head,L):
		if head is not None:
			print_inord(head.left,L)
			L.append(head.val)
			print_inord(head.right,L)
	


	head = sol.buildTree([1,3,2],[3,2,1])
	L = []
	print_pre(head,L)
	L = []
	print_inord(head,L)
	print L




