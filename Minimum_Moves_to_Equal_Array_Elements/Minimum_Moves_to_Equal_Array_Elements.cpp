// Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

// Example:

// Input:
// [1,2,3]

// Output:
// 3

// Explanation:
// Only three moves are needed (remember each move increments two elements):

// [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]


#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;


class Solution {
public:
    int minMoves(vector<int>& nums) {
        return 0;
    }
};

int main()
{
	Solution sol;
	int a[3] = {1,2,3}; 
	vector<int> nums(a,a+sizeof(a)/sizeof(int));
	int r = sol.minMoves(nums);
	printf("%d\n",r);
	return 0;
}