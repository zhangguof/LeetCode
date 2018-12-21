// Construct Binary Tree from Preorder and Inorder Traversal
//   Go to Discuss
// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
// Return the following binary tree:

//     3
//    / \
//   9  20
//     /  \
//    15   7
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stdlib.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int print_tree(TreeNode* root)
{
	if(!root) return 0;
	printf("%d\n",root->val);
	int l = print_tree(root->left);
	int r = print_tree(root->right);
	// if(l>r) return l+1;
	return r+l+1;

}

TreeNode* build_case_tree(const char* s)
{
	if(*s == '\0') return NULL;

	vector<string> v;
	const char* p = s;
	const char* q = p;	
	while(*p)
	{
		if(*p==',')
		{
			v.push_back(string(q,p));
			q = ++p;
		}
		else ++p;
	}
	if(p!=q)
	{
		v.push_back(string(q,p));
	}

	TreeNode * root = new TreeNode(atoi(v[0].c_str()));
	queue<TreeNode*> Q;
	Q.push(root);

	for(int i=1;i<v.size();)
	{
		if(Q.empty()) break;
		auto cur = Q.front();
		Q.pop();
		if(v[i]!="null")
		{
			cur->left = new TreeNode(atoi(v[i].c_str()));
			Q.push(cur->left);
		}
		++i;
		if(i>=v.size()) break;
		if(v[i]!="null")
		{
			cur->right = new TreeNode(atoi(v[i].c_str()));
			Q.push(cur->right);
			
		}
		++i;

	}
	return root;
}


class Solution {
public:
	int find_it(vector<int>& a,int s,int e,int key)
	{
		for(int i=s;i<e;++i)
		{
			if(a[i]==key) return i;
		}
		return -1;
	}
    TreeNode* do_build(vector<int>& preorder, int s0,int e0,
    				   vector<int>& inorder,int s1,int e1)
    {
        TreeNode* node = new TreeNode(preorder[s0]);
        // printf("gen node %d\n",node->val);
        int inorder_idx = find_it(inorder,s1,e1,node->val);
        int n = inorder_idx - s1;
        // printf("%d,%d,%d,%d,%d\n",s0,e0,s1,e1,inorder_idx);
        if(s1<inorder_idx)
        {
        	auto left = do_build(preorder,s0+1,s0+n+1,inorder,s1,inorder_idx);
        	node->left = left;
        }
        if(inorder_idx<e1-1)
        {
        	auto right = do_build(preorder,s0+inorder_idx-s1+1,e1,
        						  inorder,inorder_idx+1,e1);
        	node->right = right;
        }
        return node;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	int n = preorder.size();
    	int m = inorder.size();
    	if(n==0) return NULL;
    	return do_build(preorder,0,n,inorder,0,m);
    }
};

int main()
{
	vector<int> preorder = {3,9,20,15,7};
	vector<int> inorder = {9,3,15,20,7};
	Solution sol;
	
	auto ret = sol.buildTree(preorder,inorder);
	print_tree(ret);

	return 0;
}
