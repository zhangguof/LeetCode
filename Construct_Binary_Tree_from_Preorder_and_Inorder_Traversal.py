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
	def buildTree(self, preorder, inorder):
		"""
		:type preorder: List[int]
		:type inorder: List[int]
		:rtype: TreeNode
		"""
		def _build_tree(preorder,inorder):
			if not preorder:
				return None
			node = TreeNode(preorder[0])
			#print "nodes:",preorder,inorder
			idx = inorder.index(preorder[0])
			
			L_inorder = inorder[:idx]
			L_pre = preorder[1:len(L_inorder)+1]
			R_inorder = inorder[idx+1:]
			R_pre = preorder[len(L_inorder)+1:]

			if len(L_pre) == 0:
				L = None
			else:
				L = _build_tree(L_pre,L_inorder)
			
			if len(R_pre) == 0:
				R = None
			else:
				R = _build_tree(R_pre,R_inorder)
			node.left = L
			node.right = R
			return node
		return _build_tree(preorder,inorder)



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

	


	head = sol.buildTree([1,2,3],[1,2,3])
	L = []
	print_pre(head,L)
	L = []
	print_inord(head,L)
	print L




