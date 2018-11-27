// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You may assume no duplicates in the array.

// Example 1:

// Input: [1,3,5,6], 5
// Output: 2
// Example 2:

// Input: [1,3,5,6], 2
// Output: 1
// Example 3:

// Input: [1,3,5,6], 7
// Output: 4
// Example 4:

// Input: [1,3,5,6], 0
// Output: 0

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
	int lower_find(int a[],int n,int lo,int hi,int target)
	{
		if(lo == hi)
		{
			if(a[lo]>=target) return lo;
			return lo+1;
		}
		int m = (lo+hi)/2;
		if(a[m]==target)
		{
			return m;
		}
		else if(a[m]>target)
		{
			//find in left
			if(m-1>=lo)
			{
				return lower_find(a,n,lo,m-1,target);
			}
			return m; //left has no element;
		}
		else
		{
			//a[m]<target
			//find in right
			if(m+1<=hi)
			{
				return lower_find(a,n,m+1,hi,target);
			}
			return m+1;
		}
	}
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return 0;
        // if(target<nums[0]) return 0;
        return lower_find(nums.data(),n,0,n-1,target);

    }
};

int main()
{
	Solution sol;
	int a[] = {1,3,5,6};
	int t = 0;
	vector<int> nums(a,a+sizeof(a)/sizeof(int));
	int r = sol.searchInsert(nums,t);
	printf("%d\n",r);

	return 0;
}


