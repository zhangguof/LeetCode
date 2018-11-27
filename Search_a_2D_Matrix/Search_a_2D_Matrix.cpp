// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// Example 1:

// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true
// Example 2:

// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
	int low_find(int a[],int n,int lo,int hi,int target)
	{
		// printf("find ");
		// for(int i=0;i<n;++i)
		// {
		// 	printf("%d ",a[i]);
		// }
		// printf("\n");

		if(lo==hi)
		{
			if(a[lo]<=target) return lo;
			return -1;
		}
		// printf("lo:%d,hi:%d\n",lo,hi);
		int m = (lo+hi)/2;
		if(a[m]==target)
		{
			return m;
		}
		else if(a[m]>target)
		{
			if(m-1>=lo)
			{
				return low_find(a,n,lo,m-1,target);
			}
			return -1;
		}
		else
		{
			if(m+1<=hi)
			{
				int r = low_find(a,n,m+1,hi,target);
				if(r!=-1)
					return r;
				else
					return m;
			}
			return m;
		}
	}
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        //find col
        int m = matrix.size();
        if(m==0) return false;
        int n = matrix[0].size();
        if(n==0) return false;
        vector<int> col(m);
        for(int i=0;i<m;++i)
        {
        	col[i] = matrix[i][0];
        }
        int row_idx = low_find(col.data(),m,0,m-1,target);
        // printf("row:%d\n",row_idx);
        if(row_idx==-1) return false;
        int val = col[row_idx];
        if(val == target) return true;
        int col_idx = low_find(matrix[row_idx].data(),n,0,n-1,target);
        // printf("col:%d\n",col_idx);
        if(col_idx==-1) return false;
        val = matrix[row_idx][col_idx];
        if(val!=target) return false;
        return true;
    }
};

int main()
{
	//3*4
	int m = 3;
	int n = 4;
	int a[][4] = {
		{1,3,5,7},
		{10,11,16,20},
		{23,30,34,50}
	};
	// int a[][2] = {
	// 	{1},{3}
	// };
	int target = 11;
	vector<vector<int> > matrix(m);
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			matrix[i].push_back(a[i][j]);
		}
	}
	Solution sol;
	bool r = sol.searchMatrix(matrix,target);
	cout<<r<<endl;


	return 0;
}