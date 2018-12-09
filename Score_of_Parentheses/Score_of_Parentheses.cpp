// 856. Score of Parentheses
// Medium


// Given a balanced parentheses string S, compute the score of the string based on the following rule:

// () has score 1
// AB has score A + B, where A and B are balanced parentheses strings.
// (A) has score 2 * A, where A is a balanced parentheses string.
 

// Example 1:

// Input: "()"
// Output: 1
// Example 2:

// Input: "(())"
// Output: 2
// Example 3:

// Input: "()()"
// Output: 2
// Example 4:

// Input: "(()(()))"
// Output: 6
 

// Note:

// S is a balanced parentheses string, containing only ( and ).
// 2 <= S.length <= 50
#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>

using namespace std;
//a->'()'
//exp->'(exp)' | exp exp| e

class Solution {
public:
	// int do_score(const char* p,int i,int j)
	// {
	// 	// like "()"
	// 	if(i+1 == j && p[i]=='(' && p[j]==')')
	// 		return 1;
	// 	if(p[i]=='(' && p[i+1]==')')
	// 	{
	// 		return 1+do_score(p,i+2,j);
	// 	}


	// }
	// struct Node
	// {
	// 	char ch;
	// 	int val;
	// 	Node(int c,int v):ch(c),val(v){}
	// };
    int scoreOfParentheses(string S) {
    	// std::stack<Node> st;
    	// st.push(Node('#',0));
    	std::stack<int> st;
    	st.push(0);
    	const char* p = S.c_str();
    	while(*p)
    	{
    		if(*p=='(')
    		{
    			// st.push(Node('(',0));
    			st.push(0);
    		}
    		else
    		{
    			// Node& n0 = st.top();
    			int n0 = st.top();
    			if(n0 == 0)
    			{
    				st.pop();
    				int& n1 = st.top();
    				n1 += 1;
    			}
    			else
    			{
    				st.pop();
    				int& n1 = st.top();
    				n1 += 2 * n0;
    			}
    		}
    		p++;
    	}
    	// const char* p = S.c_str();
    	// int ans = do_score(p,0,S.size()-1);
        return st.top();
    }
};

int main()
{
	string a = "(()(()))";
	// string a = "(())(()())";
	Solution sol;
	printf("%d\n",sol.scoreOfParentheses(a));

	return 0;
}



