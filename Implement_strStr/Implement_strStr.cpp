// Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:

// Input: haystack = "hello", needle = "ll"
// Output: 2
// Example 2:

// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
// Clarification:

// What should we return when needle is an empty string? This is a great question to ask during an interview.

// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
	int kmp_find(string t,string p)
	{
		if(p == "") return 0;
		int n = t.size();
		int m = p.size();
		int next[m];
		//p[0..next[j]] is suffix of p[0..j]
		//next[j] = max{k:k<j && p[0..k] is suffix of p[0..j]}
		next[0] = -1;
		// int j = -1;
		for(int i=1;i<m;++i)
		{
			int j = next[i-1];
			while(j+1>0 && p[i]!=p[j+1])
			{
				j = next[j];
			}
			if(p[i]==p[j+1])
			{
				j++;
			}
			next[i] = j;
		}
		for(auto i:next)
		{
			printf("%d,",i);
		}
		printf("\n");

		int j=-1;
		for(int i=0;i<n;++i)
		{
			while(j+1>0 && t[i]!=p[j+1])
			{
				j = next[j];
			}
			printf("cmp:%d,%d,%c,%c\n",i,j,t[i],p[j+1]);
			if(t[i] == p[j+1])
			{
				printf("%d,%d\n",i,j+1);
				j++;
			}
			if(j==m-1)
			{
				printf("acc:%d\n",j);
				return i-m+1;
			}
		}
		return -1;
	}


    int strStr(string haystack, string needle) {
    	return kmp_find(haystack,needle);
    }
    int strStr1(string haystack, string needle) {
        if(needle == "") return 0;
        int n = haystack.size();
        int m = needle.size();
        int i,j;
        i = j = 0;
        //i+J<n
        //i<n-j<=n-m-1
        while(i+m-1<n && j<m)
        {
        	if(haystack[i+j] == needle[j])
        	{
        		j++;
        		if(j==m) return i;
        	}
        	else
        	{
        		j=0;
        		++i;
        	}
        }
        return -1;
    }
};

int main()
{
	string t = "babba";
	string p = "bbb";
	Solution sol;
	printf("%d\n",sol.strStr(t,p));

	return 0;
}
