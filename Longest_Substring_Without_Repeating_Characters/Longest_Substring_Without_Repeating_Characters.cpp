// 3. Longest Substring Without Repeating Characters
//   Go to Discuss
// Given a string, find the length of the longest substring without repeating characters.

// Example 1:

// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 
// Example 2:

// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
//              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int n = s.size();
    	if(n==0) return 0;
        vector<int> char_find(256,-1);
        // unordered_map<char,int> char_find;

        vector<int> str_rep(n,-1);
        for(int i=0;i<n;++i)
        {
        	// auto find_it = char_find.find(s[i]);
        	// if(find_it==char_find.end())
        	if(char_find[s[i]]==-1)
        	{   
        		char_find[s[i]] = i;
        		str_rep[i] = -1;
        	}
        	else
        	{
        		str_rep[i] = char_find[s[i]];
        		char_find[s[i]] = i;
        	}
        }
        // for(auto i:str_rep)
        // {
        // 	cout<<i<<",";
        // }
        // cout<<endl;
        int start = 0;
        int max_length = 0;

        int end = 0;
        while(end<n)
        {
        	if(str_rep[end]==-1 || str_rep[end]<start)
        	{
        		++end;
        		continue;
        	}
        	//str_rep[end]!=-1 && str_rep[end] >= start
        	if(end - start > max_length)
        	{
        		max_length = end - start;
        		// printf("%d,%d,%d\n",start,end,max_length);
        	}
        	start = str_rep[end] + 1;
        	++end;
        }
        if((str_rep[end-1]==-1 || str_rep[end-1]<start) &&( end - start > max_length))
        {
        	max_length = end - start;
        	// printf("%d,%d,%d\n",start,end,max_length);
        }


        return max_length;
    }
};

int main()
{
	Solution sol;
	// string s = "pwwkew";
	string s = "abcdab";
	// string s = "abcabcbb";
	printf("%d\n",sol.lengthOfLongestSubstring(s));

	return 0;
}
