// 5. Longest Palindromic Substring
//   Go to Discuss
// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

// Example 1:

// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: "cbbd"
// Output: "bb"


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

//use dp
//p(i,j) = true or false
//p(i,j) = p(i+1,j-1) && s[i]==s[j]

class Solution {
public:
    string longestPalindrome(string s) {
    	int n = s.size();
    	bool p[n][n];
    	for(int i=0;i<n;++i)
    	for(int j=0;j<n;++j)
    	{
    		p[i][j] = false;
    	}
    	int max_i = 0;
    	int max_j = 0;
    	int max_l = 1;
    	for(int i=0;i<n;++i)
    	{
    		p[i][i] = true;
    		if(i+1<n)
    		{
    			p[i][i+1] = (s[i]==s[i+1]);
    			if(p[i][i+1] && max_l==1)
    			{
    				max_i = i;
    				max_j = i+1;
    				max_l = 2;
    			}
    		}
    	}
    	for(int i=2;i<n;++i)
    	{
    		for(int j=0;j<n-i;++j)
    		{
    			// p[i][j] = p[i+1][j-1]
    			p[j][i+j] = p[j+1][i+j-1] && (s[j]==s[i+j]);
    			if(p[j][i+j] && (i+1)>max_l)
    			{
    				max_i = j;
    				max_j = i+j;
    				max_l = i + 1;
    			}
    		}
    	}
    	// for(int i=0;i<n;++i)
    	// {
    	// 	for(int j=0;j<n;++j)
    	// 	{
    	// 		printf("%d,",p[i][j]);
    	// 	}
    	// 	printf("\n");
    	// }
    	// printf("%d,(%d,%d)\n",max_l,max_i,max_j);
    	return string(s,max_i,max_l);
   
    }
};

int main()
{
	// string s = "cbbd";
	string s = "babad";

	Solution sol;
	cout<<sol.longestPalindrome(s)<<endl;


	return 0;
}
