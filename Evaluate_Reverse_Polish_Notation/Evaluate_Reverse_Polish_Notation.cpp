// Evaluate Reverse Polish Notation
//   Go to Discuss
// Evaluate the value of an arithmetic expression in Reverse Polish Notation.

// Valid operators are +, -, *, /. Each operand may be an integer or another expression.

// Note:

// Division between two integers should truncate toward zero.
// The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
// Example 1:

// Input: ["2", "1", "+", "3", "*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
// Example 2:

// Input: ["4", "13", "5", "/", "+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6
// Example 3:

// Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
// Output: 22
// Explanation: 
//   ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
// = ((10 * (6 / (12 * -11))) + 17) + 5
// = ((10 * (6 / -132)) + 17) + 5
// = ((10 * 0) + 17) + 5
// = (0 + 17) + 5
// = 17 + 5
// = 22


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stack>

using namespace std;

class Solution {
public:
	bool is_op(string token)
	{
		return token=="*" || token=="/" || 
			   token=="+" || token=="-";
	}
	int do_op(int val1,int val2,char op)
	{
		// char ch = op;
		switch(op)
		{
		case '+':
			return val1+val2;
		case '-':
			return val1-val2;
		case '*':
			return val1*val2;
		case '/':
			return val1/val2;
		}
	}
    int evalRPN(vector<string>& tokens) {
    	std::stack<int> st;
    	for(auto token:tokens)
    	{
    		if(is_op(token))
    		{
    			int val2 = st.top();
    			st.pop();
    			int val1 = st.top();
    			st.pop();
    			int ret = do_op(val1,val2,token[0]);
    			st.push(ret);
    		}
    		else
    		{
    			st.push(atoi(token.c_str()));
    		}
    	}
    	return st.top();
    }
};

int main()
{
	vector<string> tokens = {
		// "2", "1", "+", "3", "*"
		"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"
	};
	Solution sol;
	printf("%d\n",sol.evalRPN(tokens));

	return 0;
}
