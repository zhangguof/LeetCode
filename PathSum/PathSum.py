#-*- coding:utf-8 -*-

# 112. Path Sum   QuestionEditorial Solution  My Submissions
# Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

# For example:
# Given the below binary tree and sum = 22,
#               5
#              / \
#             4   8
#            /   / \
#           11  13  4
#          /  \      \
#         7    2      1
# return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if not root:
        	return False
        val = root.val
        left = root.left
        right = root.right

        if not left and not right and val == sum:
        	return True

        if left and self.hasPathSum(left,sum-val):
        	return True
        if right and self.hasPathSum(right,sum-val):
        	return True
        return False

        

if __name__ == "__main__":
    class TreeNode(object):
        def __init__(self, x):
            self.val = x
            self.left = None
            self.right = None


    def build_tree(a,i):
        if i >= len(a):
            return None
        node = TreeNode(a[i])
        if i*2+1 < len(a) and a[i*2+1]!=None:
            node.left = build_tree(a,i*2+1)
        if i*2+2 < len(a) and a[i*2+2]!=None:
            node.right = build_tree(a,i*2+2)
        return node

    def print_tree(root):
        if root:
            print root.val
            print_tree(root.left)
            print_tree(root.right)

    def test(case,sum):
        print "======Test Case======"
        root = build_tree(case,0)
        sol = Solution()
        print sol.hasPathSum(root,sum)
    # test([2,1,3])
    # test([1,None,3])
    # test([3,1,4,None,2])
    test([],1)
    test([5,4,8,11,None,13,4,7,2,None,None,None,1],22)
    test([1,2],1)