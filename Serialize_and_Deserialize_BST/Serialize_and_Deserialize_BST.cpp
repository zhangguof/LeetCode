// 449. Serialize and Deserialize BST
// Medium

// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

// The encoded string should be as compact as possible.

// Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

#include <iostream>
#include <fstream>
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

class Codec {
public:

    // Encodes a tree to a single string.
    void build_str(vector<string>& v,TreeNode* root)
    {
    	char buf[20];

    	if(!root) return;

    	
    	queue<TreeNode*> Q;
    	Q.push(root);
    	sprintf(buf,"%d",root->val);
    	v.push_back(string(buf));
    	// printf("do push:%d\n",root->val);
    	while(!Q.empty())
    	{
    		TreeNode* cur = Q.front();
    		Q.pop();
    		if(cur->left)
    		{
    			Q.push(cur->left);
    			sprintf(buf,"%d",cur->left->val);
    			v.push_back(string(buf));
    			// printf("do push left:%d\n",cur->left->val);
    		}
    		else
    		{
    			v.push_back(string(""));
    			// printf("push left null\n");
    		}
    		if(cur->right)
    		{
    			Q.push(cur->right);
    			sprintf(buf,"%d",cur->right->val);
    			v.push_back(string(buf));
    			// printf("do push right:%d\n",cur->right->val);
    		}
    		else
    		{
    			v.push_back(string(""));
    			// printf("push right null\n");
    		}

    	}

    }

    string serialize(TreeNode* root) {
        if(!root) return "";
        vector<string> s;
        build_str(s,root);
        
        int new_size = s.size()-1;
        for(;new_size>=0;--new_size)
        {
        	if(s[new_size]!="") break;	
        }
        s.resize(new_size+1);
        int len = 0;
        for(auto it:s)
        {
        	len += it.size();
        }
        len += new_size+4;
        // printf("len:%d\n",len);
        char* buf = new char[len];
        char* p = buf;
        copy(s[0].begin(),s[0].end(),p);
        p+=s[0].size();
        for(int i=1;i<s.size();++i)
        {
        	*(p++) = ',';
        	if(s[i]!="")
        	{
        		copy(s[i].begin(),s[i].end(),p);
        		p+=s[i].size();
        	}
        }
        *p = '\0';
        string r = buf;
        delete[] buf;
        // printf("size:%d\n",s.size());
        return r;

    }

    // Decodes your encoded data to tree.
    TreeNode* build_tree(vector<string>& v)
    {
		TreeNode * root = new TreeNode(atoi(v[0].c_str()));
		queue<TreeNode*> Q;
		Q.push(root);

		for(int i=1;i<v.size();)
		{
			if(Q.empty()) break;
			auto cur = Q.front();
			Q.pop();
			// printf("cur:%d,%d,%s\n",cur->val,v.size(),v[i].c_str());
			if(v[i]!="")
			{
				cur->left = new TreeNode(atoi(v[i].c_str()));
				Q.push(cur->left);
				// printf("add left:%s\n",v[i].c_str());
			}
			++i;
			if(i>=v.size()) break;
			if(v[i]!="")
			{
				cur->right = new TreeNode(atoi(v[i].c_str()));
				Q.push(cur->right);
				// printf("add right:%s,%d\n",v[i].c_str(),atoi(v[i].c_str()));
				
			}
			++i;
		}
		return root;
    }
    TreeNode* deserialize(string data) {
    	if(data == "")
    	{
    		return NULL;
    	}

    	vector<string> s;
    	const char* p = data.c_str();
    	const char* q = p;

    	//split ","
    	while(*p)
    	{
    		if(*p == ',')
    		{
    			s.push_back(string(q,p));
    			++p;
    			q = p;	
    		}
    		else
    		{
    			++p;
    		}
    	}
    	if(q!=p)
    	{
    		s.push_back(string(q,p));
    	}

        TreeNode* root =  build_tree(s);

        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));



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

int main()
{
	
	Codec codec;
	string t = "1,,2,3";
	// string filename = "in.txt";
	// std::ifstream istrm(filename,std::ios::binary);
	// string t;
	// istrm>>t;

	// string t = "1,2,,4";
	// auto root = build_case_tree(t.c_str());

	// auto root = codec.deserialize(t);
	
	auto ret = codec.deserialize(t);
	print_tree(ret);
	string tt = codec.serialize(ret);
	cout<<tt<<endl;
	// printf("%d\n",codec.max_i);

	

	return 0;
}
