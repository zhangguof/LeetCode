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
#include <vector>
#include <stdio.h>

using namespace std;

//2 4 6

class Solution {
public:
	//find first >= target
	int bin_find(int nums[],int n,int i,int j,int target)
	{
		// printf("find %d:%d,%d\n",target,i,j);
		if(i>j|| i<0 || j>=n) return -1;
		if(i==j && nums[i]<=target) return i;

		int m = (i+j)/2;
		if(nums[m]==target)
		{
			int r = bin_find(nums,n,0,m-1,target);//<=target
			if(r!=-1 && nums[r]==target)
			{
				return r;
			}
			return m;
		}
		else if(nums[m]<target)
		{
			int r = bin_find(nums,n,m+1,j,target);
			if(r!=-1)
			{
				return r;
			}

			return m;
		}
		else
		{
			int r = bin_find(nums,n,0,m-1,target);
			return r;
		}


		return -1;
	}
    vector<int> searchRange(vector<int>& nums, int target) {

    	vector<int> a(2);
        a[0] = a[1] = -1;
        int n = nums.size();
        if(n==0) return a;


    	int i = bin_find(nums.data(),n,0,n-1,target);
    	if(i==-1 || nums[i]!=target)
    	{
    		return a;
    	}
    	a[0] = a[1] = i;
    	// printf("find:%d\n",i);
    	int j = bin_find(nums.data(),n,0,n-1,target+1);
    	if(j>i)
    	{
    		if(nums[j]==target+1)
    		{
    			a[1] = j-1;
    		}
    		else
    		{
    			a[1] = j;
    		}
    	}
    	// printf("find:%d\n",j);

        return a;
    }
};

int main()
{
	Solution sol;
	int a[] = {5,7,7,8,8,10};
	int t = 8;
	// int a[] = {1};
	// int t = 1;
	vector<int> nums(a,a+sizeof(a)/sizeof(int));
	auto r = sol.searchRange(nums,t);
	printf("[%d,%d]\n",r[0],r[1]);

	return 0;
}