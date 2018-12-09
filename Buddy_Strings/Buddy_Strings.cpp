// 859. Buddy Strings
// Easy

// Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

 

// Example 1:

// Input: A = "ab", B = "ba"
// Output: true
// Example 2:

// Input: A = "ab", B = "ab"
// Output: false
// Example 3:

// Input: A = "aa", B = "aa"
// Output: true
// Example 4:

// Input: A = "aaaaaaabc", B = "aaaaaaacb"
// Output: true
// Example 5:

// Input: A = "", B = "aa"
// Output: false
 

// Note:

// 0 <= A.length <= 20000
// 0 <= B.length <= 20000
// A and B consist only of lowercase letters.

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;


class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size()!=B.size()) return false;
        std::vector<int> L(256,0);
        int n = A.size();
        bool swap_flag = false;
        int first_diff = -1;
        bool has_same = false;
        int i=0;
        while(i<n)
        {
        	if(!has_same)
        	{
        		int ord = int(A[i]);
        		L[ord]++;
        		if(L[ord]>1)
        		{
        			has_same = true;
        		}
        	}
        	if(A[i] != B[i])
        	{
        		if(swap_flag) return false;
        		
        		if(first_diff==-1)
        		{
        			first_diff = i;
        			++i;
        		}
        		else if(A[first_diff]==B[i] && A[i]==B[first_diff])
        		{
        			++i;
        			swap_flag = true;
        		}
        		else
        		{
        			return false;
        		}
        	}
        	else 
        	{
        		++i;
        	}
        	
        }
        if(!swap_flag && first_diff==-1 && has_same) return true;
        return first_diff!=-1;
    }
};


int main()
{
	// string a = "abab";
	// string b = "abab";
	string a = "acccccb";
	string b = "bccccca";
	// string a = "abcd";
	// string b = "badc";
	Solution sol;
	printf("%d\n",sol.buddyStrings(a,b));

	return 0;
}



