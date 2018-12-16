// Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

// Formally the function should:

// Return true if there exists i, j, k 
// such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
// Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

// Example 1:

// Input: [1,2,3,4,5]
// Output: true
// Example 2:

// Input: [5,4,3,2,1]
// Output: false


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

    	const int MIN_VAL = std::numeric_limits<int>::min();

        vector<int> increasing_order(3,MIN_VAL);
        for(auto i:nums)
        {
        	for(int j=0;j<3;++j)
        	{
        		if(increasing_order[j] == i) break;
        		if(increasing_order[j]==MIN_VAL || i<increasing_order[j])
        		{

        			increasing_order[j] = i;
        			// for(auto x:increasing_order)
        			// {
        			// 	printf("%d,",x);
        			// }
        			// printf("\n");
        			if(j==2) return true;
        			break;
        		}
        	}
        }
        return false;
    }
};

int main()
{
	Solution sol;
	vector<int> a = {
	// 1,2,3,4,5,6
		// 8,1,7,2,6,3
		// 6,3,2,1
		1,1,1,1
};
	printf("%d\n",sol.increasingTriplet(a));

	return 0;
}
