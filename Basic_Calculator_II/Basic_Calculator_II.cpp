// 227. Basic Calculator II
// Medium

// 501

// 77

// Favorite

// Share
// Implement a basic calculator to evaluate a simple expression string.

// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

// Example 1:

// Input: "3+2*2"
// Output: 7
// Example 2:

// Input: " 3/2 "
// Output: 1
// Example 3:

// Input: " 3+5 / 2 "
// Output: 5
// Note:

// You may assume that the given expression is always valid.
// Do not use the eval built-in library function.

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

//fac  -> fac (*|/) num | num | (exp)

//fac  -> num fac'
//fac' -> (*|/)num fac' | e

//exp  -> exp (+|-) fac

//exp  -> fac exp'
//exp' -> (+|-)fac exp' | e


class Solution {
public:
	int cal_fac(vector<string>& tokens,int& cur_pos)
	{
		string token = tokens[cur_pos++];
		int ret;
		if(token[0]=='(')
		{
			ret = cal_exp(tokens,cur_pos);
			// printf("ret %d\n",ret);
			token = tokens[cur_pos++];
			assert(token[0]==')');
			// return ret;
		}
		else
		{
			ret = atoi(token.c_str());
		}
		return _cal_fac(tokens,cur_pos,ret);

	}
	int _cal_fac(vector<string>& tokens,int& cur_pos,int val1)
	{
		if(cur_pos>=tokens.size()) return val1;
		string token = tokens[cur_pos];
		int ret = val1;
		while(token[0]=='*'||token[0]=='/')
		{
			char op = token[0];
			cur_pos++;
			token = tokens[cur_pos];
			int val2 = atoi(token.c_str());
			// int ret;
			if(op=='*')
			{
				ret = ret * val2;
			}
			else
			{
				ret = ret / val2;
			}
			cur_pos++;
			if(cur_pos>=tokens.size()) return ret;
			token = tokens[cur_pos];
			// return _cal_fac(tokens,cur_pos,ret);
		}

		return ret;
	}
	int cal_exp(vector<string>& tokens,int& cur_pos)
	{
		// string& token = tokens[cur_pos];
		int val1 = cal_fac(tokens,cur_pos);

		return _cal_exp(tokens,cur_pos,val1);
	}
	int _cal_exp(vector<string>& tokens,int& cur_pos,int val1)
	{
		if(cur_pos>=tokens.size()) return val1;
		string token = tokens[cur_pos];
		int ret = val1;
		while(token[0]=='+'||token[0]=='-')
		{
			char op = token[0];
			cur_pos++;
			int val2 = cal_fac(tokens,cur_pos);
			
			if(op=='+')
			{
				ret = ret + val2;
			}
			else
			{
				ret = ret - val2;
			}
			if(cur_pos>=tokens.size()) return ret;
			token = tokens[cur_pos];

		}
		// else
		{
			return ret;
		}
	}

	bool is_num(char ch)
	{
		return ch>='0' && ch<='9';
	}
	bool is_op(char ch)
	{
		return ch=='*'||ch=='/'||
			   ch=='+'||ch=='-'||
			   ch=='('||ch==')';
	}

    int calculate(string s) {
        vector<string> tokens;
        // int i = 0;
        int j = 0;
        int n =s.size();
        while(j<n)
        {
        	if(is_op(s[j]))
        	{
        		tokens.push_back(s.substr(j,1));
        		j++;
        	}
        	else if(is_num(s[j]))
        	{
        		int i = j;
        		while(is_num(s[j]) && j<n) j++;
        		tokens.push_back(s.substr(i,j-i));
        	}
        	else
        	{
        		j++;
        	}
        }

        int cur_pos = 0;
        int ret = cal_exp(tokens,cur_pos);

        return ret;


    }
};

int main()
{
	// string s = "1*2*3*4*5*6*7*8*9*10";
	string s = "(1+(4+5+2)-3)+(6+8)";
	Solution sol;
	printf("%d\n",sol.calculate(s));

	return 0;
}
