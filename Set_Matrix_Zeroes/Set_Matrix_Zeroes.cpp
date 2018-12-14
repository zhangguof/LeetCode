// 73. Set Matrix Zeroes
// Medium

// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

// Example 1:

// Input: 
// [
//   [1,1,1],
//   [1,0,1],
//   [1,1,1]
// ]
// Output: 
// [
//   [1,0,1],
//   [0,0,0],
//   [1,0,1]
// ]
// Example 2:

// Input: 
// [
//   [0,1,2,0],
//   [3,4,5,2],
//   [1,3,1,5]
// ]
// Output: 
// [
//   [0,0,0,0],
//   [0,4,5,0],
//   [0,3,1,0]
// ]
// Follow up:

// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
    	int n = matrix.size();
    	int m = matrix[0].size();
    	vector<bool> r_zero(n,false);
    	vector<bool> c_zero(m,false);
    	for(int i=0;i<n;++i)
    	{
    		// if(r_zero[i]) continue;
    		for(int j=0;j<m;++j)
    		{
    			// if(c_zero[j]) continue;
    			if(matrix[i][j] == 0)
    			{
    				r_zero[i] = c_zero[j] = true;
    			}
    		}
    	}

    	for(int i=0;i<n;++i)
    	{
    		for(int j=0;j<m;++j)
    		{
    			if(r_zero[i] || c_zero[j])
    			{
    				matrix[i][j] = 0;
    			}
    		}
    	}
        
    }
};

int main()
{
	vector<vector<int> > m = 
	{
	  // {0,1,2,0},
	  // {3,4,5,2},
	  // {1,3,1,5}
	  {0,0,0,5},
	  {4,3,1,4},
	  {0,1,1,4},
	  {1,2,1,3},
	  {0,0,1,1}
	};
	Solution sol;
	sol.setZeroes(m);
	for(auto r:m)
	{
		for(auto c:r)
		{
			printf("%d ",c);
		}
		printf("\n");
	}

	return 0;
}
