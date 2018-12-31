// Longest Increasing Subsequence
//   Go to Discuss
// Given an unsorted array of integers, find the length of longest increasing subsequence.

// Example:

// Input: [10,9,2,5,3,7,101,18]
// Output: 4 
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
// Note:

// There may be more than one LIS combination, it is only necessary for you to return the length.
// Your algorithm should run in O(n2) complexity.
// Follow up: Could you improve it to O(n log n) time complexity?
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int f[n];
        f[0] = 1;
        for(int i=1;i<n;++i)
        {
        	int max_val = 1;
        	for(int j=i-1;j>=0;--j)
        	{
        		if(nums[j]<nums[i])
        		{
        			int len = f[j]  +1;
        			if(max_val<len)
        			{
        				max_val = len;
        			}
        		}
        	}
        	f[i]=max_val;
        }
        int max_val = 1;
        for(int i=0;i<n;++i)
        {
        	if(f[i]>max_val)
        	{
        		max_val = f[i];
        	}
        }
        return max_val;
    }
};

int main()
{
	vector<int> nums = {
		10,9,2,5,3,7,101,18
	};
	Solution sol;
	printf("%d\n",sol.lengthOfLIS(nums));


	return 0;
}
