// Subsets
//   Go to Discuss
// Given a set of distinct integers, nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:

// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
	//i element in set
	//
	//c(n,m) = c(n-1,m)+c(n-1,m-1)
	void gen_combin(vector<vector<int> >&ret,vector<int>&nums)
	{
		int i=0;
		int n = nums.size();
		while(i<n)
		{
			int m = ret.size();
			for(int j=0;j<m;++j)
			{
				auto ans = ret[j];
				ans.push_back(nums[i]);
				ret.push_back(ans);
			}
			++i;
		}
		// if(i==nums.size()) return;
		// int m = ret.size();
		// for(int j=0;j<m;++j)
		// {
		// 	auto ans = ret[j];
		// 	ans.push_back(nums[i]);
		// 	ret.push_back(ans);
		// }
		// gen_combin(ret,nums,i+1);

	}

    vector<vector<int> > subsets(vector<int>& nums) {
    	vector<vector<int> > ret;
    	ret.push_back(vector<int>());
    	gen_combin(ret,nums);
    	return ret;
    }
};

int main()
{
	Solution sol;
	vector<int> nums = {1,2,3,4};
	auto ret = sol.subsets(nums);
	for(auto i:ret)
	{
		for(auto j:i)
		{
			printf("%d,",j);
		}
		printf("\n");
	}


	return 0;
}
