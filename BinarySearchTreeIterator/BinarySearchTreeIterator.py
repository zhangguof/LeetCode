#-*- coding:utf-8 -*-



# Definition for a  binary tree node
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator1(object):
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.ite = self.vised_tree(root)
        try:
            self.next_val = self.ite.next()
        except StopIteration:
            self.next_val = None   
        
    def vised_tree(self,node):
        #print "in vised tree...."
        if node and node.left != None:
            for val in self.vised_tree(node.left):
                yield val

        if node!=None:
            yield node.val

        if node and node.right!=None:
            for val in self.vised_tree(node.right):
                yield val



    def hasNext(self):
        """
        :rtype: bool
        """
        return self.next_val != None
        

    def next(self):
        """
        :rtype: int
        """
        t = self.next_val
        try:
            self.next_val = self.ite.next()
        except StopIteration:
            self.next_val = None
        return t


class BSTIterator(object):
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        class Stack:
            def __init__(self):
                self.data = [None] * 2
                self.cur_idx = 0
            def is_empty(self):
                return self.cur_idx == 0

            def push(self,val):
                if self.cur_idx >= len(self.data):
                    self.data.extend([None]*len(self.data))
                self.data[self.cur_idx] = val
                self.cur_idx += 1
            def pop(self):
                if not self.is_empty():
                    val = self.data[self.cur_idx-1]
                    self.cur_idx -= 1
                    return val
            def top(self):
                if not self.is_empty():
                    return self.data[self.cur_idx-1]

        self.stack = Stack()
        if root:
            self.stack.push(root)
        self.stack2 = Stack()

    def vised_tree(self,node):
        while 1:
            if self.stack.is_empty() and not self.stack2.is_empty():
                top_node = self.stack2.pop()
                yield top_node.val
                if top_node.right:
                    self.stack.push(top_node.right)


            top_node = self.stack.pop()

            while top_node and top_node.left:
                self.stack2.push(top_node) #
                top_node = top_node.left

            if top_node.right:
                self.stack.push(top_node.right)

            yield top_node.val

            if self.stack.is_empty() and self.stack2.is_empty():
                break
            # if cnt == 2:
            #     break


        



    def hasNext(self):
        """
        :rtype: bool
        """
        return not (self.stack.is_empty() and self.stack2.is_empty())
        

    def next(self):
        """
        :rtype: int
        """
        if self.stack.is_empty() and not self.stack2.is_empty():
            top_node = self.stack2.pop()
            if top_node.right:
                self.stack.push(top_node.right)
            return top_node.val

        top_node = self.stack.pop()

        while  top_node and top_node.left:
            self.stack2.push(top_node)
            top_node = top_node.left

        if top_node.right:
            self.stack.push(top_node.right)

        return top_node.val


# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())

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

    def test(case):
        print "======Test Case======"
        root = build_tree(case,0)
        BSTIterator(root)
        i,v = BSTIterator(root), []
        while  i.hasNext():
            v.append(i.next())
        print v
    # test([2,1,3])
    # test([1,None,3])
    # test([3,1,4,None,2])
    test([])


