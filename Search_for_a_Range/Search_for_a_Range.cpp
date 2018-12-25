// Search for a Range
//   Go to Discuss
// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
	int search_upper(vector<int> &nums,int l,int r, int val)
	{
		// if(l>r) return -1;

		if(l>=r) return l;
		// printf("search:%d,%d,%d\n",l,r,(l+r)/2);

		int mid = (l+r)/2;
		if(nums[mid] <= val)
		{
			int ret =  search_upper(nums,mid+1,r,val);
			if(nums[ret]<=val)
			{
				return ret;
			}
			//r==-1
			// if(nums[mid]==val)
			// {
			// 	return mid;
			// }
			// return -1;
			return mid;
		}
		else
		{
			return search_upper(nums,l,mid-1,val);	
		}
	}
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> a(2,-1);
        int n = nums.size();
        if(n==0) return a;
        int i = search_upper(nums,0,n-1,target);
        // printf("i:%d\n",i);
        if(nums[i]!=target) return a;
        // a[0] = i;
        int j = search_upper(nums,0,n-1,target-1);
        if(nums[j]!=target) j++;
        // a[1] = j;
        a[0] = j;
        a[1] = i;
        return a;
    }
};

int main()
{
	Solution sol;
	vector<int> nums = {5,7,7,8,8,10};
	auto r = sol.searchRange(nums,10);
	printf("%d,%d\n", r[0],r[1]);
	return 0;
}
