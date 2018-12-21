//  Permutations
//   Go to Discuss
// Given a collection of distinct integers, return all possible permutations.

// Example:

// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
	void gen_permute(vector<vector<int> >& ret,vector<int>& nums,vector<int> &ans,int i)
	{
		int n = nums.size();
		ans[i] = nums[i];
		if(i==n-1)
		{
			ret.push_back(ans);
		}
		else
		{
			gen_permute(ret,nums,ans,i+1);
		}

		for(int j=0;j<i;++j)
		{
			// swap(ans[j],ans[i]);
			auto new_ans = ans;
			new_ans[j] = ans[i];
			new_ans[i] = ans[j];
			if(i==n-1)
			{
				ret.push_back(new_ans);
			}
			else
			{
				gen_permute(ret,nums,new_ans,i+1);
			}
			}
	}
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > ret;
        int n = nums.size();
        vector<int> ans(n);
        gen_permute(ret,nums,ans,0);
        return ret;

    }
};

int main()
{
	Solution sol;
	vector<int> nums = {1,2,3};
	auto r = sol.permute(nums);
	for(auto i:r)
	{
		for(int j:i)
			printf("%d,",j);
		printf("\n");
	}
	// printf("\n");
	printf("%d\n",r.size());

	return 0;
}
