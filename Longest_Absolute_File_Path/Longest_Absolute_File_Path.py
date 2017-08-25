# -*- coding:utf8 -*-

# Suppose we abstract our file system by a string in the following manner:
#
# The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
#
# dir
#     subdir1
#     subdir2
#         file.ext
# The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.
#
# The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:
#
# dir
#     subdir1
#         file1.ext
#         subsubdir1
#     subdir2
#         subsubdir2
#             file2.ext
# The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.
#
# We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).
#
# Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.
#






class Node:
	def __init__(self, s,is_root=False):
		self.str = s
		self.tabs = s.rfind("\t") + 1
		self.s_len = len(s) - self.tabs + 1 if not is_root else len(s) -self.tabs
		self.is_file = True if s.find(".") > 0 else False
		self.max_len = self.s_len if self.is_file else 0
		self.files = []
		self.dirs = []

	def add_node(self, node):
		if node.is_file:
			self.files.append(node)
			new_len = self.s_len + node.s_len
			if new_len > self.max_len:
				self.max_len = new_len

		else:
			self.dirs.append(node)
			if node.max_len > 0:
				new_len = node.max_len + self.s_len
				if new_len > self.max_len:
					self.max_len = new_len



def build_tree(nodes,idx):
	cur_node = nodes[idx]
	n_idx = idx+1
	

	while 1:
		if n_idx >= len(nodes) or n_idx<0:
			return -1
		n_node = nodes[n_idx]
		if n_node.tabs == cur_node.tabs + 1:
			if n_node.is_file:
				cur_node.add_node(n_node)
				n_idx += 1
			else:
				n_idx = build_tree(nodes,n_idx)
				cur_node.add_node(n_node)
		else:
			return n_idx








class Solution(object):
	def lengthLongestPath(self, input):
		"""
		:type input: str
		:rtype: int
		"""
		nodes = input.split("\n")
		self.nodes = [Node(nodes[0],True)]
		self.nodes.extend([Node(n) for n in nodes[1:]])
		# print nodes
		self.nodes_count = len(nodes)
		build_tree(self.nodes,0)

		return  self.nodes[0].max_len






if __name__ == "__main__":
	sol = Solution()
	print sol.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext")
	print sol.lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext")
	print sol.lengthLongestPath("dir\n\t\t\t\tfile.txt")


