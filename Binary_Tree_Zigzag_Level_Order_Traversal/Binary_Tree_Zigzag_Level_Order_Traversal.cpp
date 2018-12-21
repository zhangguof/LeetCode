// Binary Tree Zigzag Level Order Traversal
//   Go to Discuss
// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <queue>

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
	void do_traval(TreeNode* root, vector<vector<int> > &ret,int l,bool is_left2right)
	{
		// queue<int> q;

	}
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        if(!root) return ret;
        // bool is_left2right = true;
        // int level = 0;
        // int is_left2right = true;
        // do_traval(root,ret,0,is_left2right);
        queue<std::pair<TreeNode*,int> > q;
        q.push(std::make_pair(root,0));
        while(!q.empty())
        {
        	auto top = q.front();
        	q.pop();
        	TreeNode* cur_node = top.first;
        	int l = top.second;
        	// printf("cur %d,%d\n",cur_node->val,l);
        	// if(q.empty()) printf("empty!!!\n");
        	if(l == ret.size())
        	{
        		ret.push_back(vector<int>());
        	}
        	ret[l].push_back(cur_node->val);
        	// if(l%2==0)
        	// {
        	// 	if(cur_node->right)
        	// 	{
        	// 		q.push(std::make_pair(cur_node->right,l+1));
        	// 	}
        	// 	if(cur_node->left)
        	// 	{
        	// 		q.push(std::make_pair(cur_node->left,l+1));
        	// 	}
        	// }
        	// else
        	{
        		if(cur_node->left)
        		{
        			q.push(std::make_pair(cur_node->left,l+1));
        		}
        		if(cur_node->right)
        		{
        			q.push(std::make_pair(cur_node->right,l+1));
        		}
        	}
        }
        int n = ret.size();
        for(int i=0;i<n;++i)
        {
        	// int m = ret[i].size();
        	if(i%2==0) continue;
        	int j = 0;
        	int k = ret[i].size()-1;
        	
        	while(j<k)
        	{
        		int t = ret[i][j];
        		ret[i][j] = ret[i][k];
        		ret[i][k] = t;
        		++j;
        		--k;
        	}
        }


        return ret;
    }
};

int main()
{
	// vector<int> v = {3,9,20,NULL,NULL,15,7};
	// string v = "3,9,20,null,null,15,7";
	string v = "1,2,3,4,5,6,7,8,9,10,11,12,13,14,15";
	Solution sol;
	auto root = build_case_tree(v.c_str());
	// print_tree(root);
	auto r = sol.zigzagLevelOrder(root);
	for(auto i:r)
	{
		for(auto j:i)
		{
			printf("%d,",j);
		}
		printf("\n");
	}

	return 0;
}
