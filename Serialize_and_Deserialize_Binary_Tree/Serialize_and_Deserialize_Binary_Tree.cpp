//  Serialize and Deserialize Binary Tree
//   Go to Discuss
// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

// Example: 

// You may serialize the following tree:

//     1
//    / \
//   2   3
//      / \
//     4   5

// as "[1,2,3,null,null,4,5]"
// Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

// Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.


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

void print_tree(TreeNode* root)
{
	printf("%d\n",root->val);
	if(root->left) print_tree(root->left);
	if(root->right) print_tree(root->right);
}



class Codec {
public:

	static string itoa(int v)
	{
		char buf[10];
		sprintf(buf,"%d",v);
		return string(buf);
	}

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    	if(root==NULL) return "null";

    	vector<string> v;
    	queue<TreeNode*> Q;
    	Q.push(root);
    	v.push_back(itoa(root->val));
    	while(!Q.empty())
    	{
    		auto top = Q.front();
    		Q.pop();
    		// v.push_back(itoa(top->val));
    		if(top->left)
    		{
    			v.push_back(itoa(top->left->val));
    			Q.push(top->left);
    		}
    		else
    		{
    			v.push_back("null");
    		}
    		if(top->right)
    		{
    			v.push_back(itoa(top->right->val));
    			Q.push(top->right);
    		}
    		else
    		{
    			v.push_back("null");
    		}
    	}
    	int tail = v.size()-1;
    	for(;tail>=0;--tail)
    	{
    		if(v[tail]!="null") break;
    	}
    	string ret = v[0];
    	for(int i=1;i<=tail;++i)
    	{
    		ret.append(",");
    		ret.append(v[i]);
    	}
    	return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	if(data=="null") return NULL;
        vector<string> v;
        int n = data.size();
        int s = 0;
        for(int i=0;i<n;++i)
        {
        	if(data[i]==',')
        	{
        		v.push_back(data.substr(s,i-s));
        		s = i+1;
        	}
        }
        v.push_back(data.substr(s,n-s));
        std::queue<TreeNode*> Q;
        TreeNode* root = new TreeNode(atoi(v[0].c_str()));
        Q.push(root);
        int cur = 1;
        while(cur<v.size())
        {
        	if(Q.empty()) break;
        	auto top = Q.front();
        	Q.pop();
        	if(v[cur] != "null")
        	{
        		top->left = new TreeNode(atoi(v[cur].c_str()));
        		Q.push(top->left);
        		
        	}
        	cur++;
        	if(cur>=v.size()) break;
        	if(v[cur]!="null")
        	{
        		top->right = new TreeNode(atoi(v[cur].c_str()));
        		Q.push(top->right);	
        	}
        	cur++;
        }
        return root;
        // for(auto i:v)
        // {
        // 	cout<<i<<endl;
        // }
        // return NULL;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{
	Codec codec;
	string data = "null";
	TreeNode* root = codec.deserialize(data);
	// print_tree(root);
	auto ret = codec.serialize(root);
	cout<<ret<<endl;

	return 0;
}
