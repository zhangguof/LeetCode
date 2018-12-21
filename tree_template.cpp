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