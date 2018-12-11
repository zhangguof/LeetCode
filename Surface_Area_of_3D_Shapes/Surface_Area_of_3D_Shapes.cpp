// 892. Surface Area of 3D Shapes
// Easy
// 101
// 107


// On a N * N grid, we place some 1 * 1 * 1 cubes.

// Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).

// Return the total surface area of the resulting shapes.

 

// Example 1:

// Input: [[2]]
// Output: 10
// Example 2:

// Input: [[1,2],[3,4]]
// Output: 34
// Example 3:

// Input: [[1,0],[0,2]]
// Output: 16
// Example 4:

// Input: [[1,1,1],[1,0,1],[1,1,1]]
// Output: 32
// Example 5:

// Input: [[2,2,2],[2,1,2],[2,2,2]]
// Output: 46
 

// Note:

// 1 <= N <= 50
// 0 <= grid[i][j] <= 50


#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
	int get_cube_area(vector<vector<int> >& grid,int i, int j, int k)
	{
		int n = grid[0].size();
		//at most 6 face;
		int face = 0;
		if(k==grid[i][j]) face++;
		if(k==1) face++;
		
		if(j==0 || (j>0&&k>grid[i][j-1])) face++;
		if(j==n-1 || (j<n-1 && k>grid[i][j+1])) face++;

		if(i==0 || (i>0 && k>grid[i-1][j])) face++;
		if(i==n-1 || (i<n-1 && k>grid[i+1][j])) face++;
		// printf("%d,%d,%d=%d\n",i,j,k,face);
		return face;

	}
    int surfaceArea(vector<vector<int> >& grid) {
       int n = grid[0].size();
       int ans = 0;
       // int s = 0;
       vector<int> row_h(n,0);
       vector<int> col_h(n,0);
       // int h = 0;
       for(int i=0;i<n;++i)
       {
	       for(int j=0;j<n;++j)
	       {
	       		int v = grid[i][j];
	       		for(int k = 1; k<v+1;++k)
	       		{
	       			int s = get_cube_area(grid,i,j,k);
	       			ans += s;

	       		}
	       }
   	   }
       return ans;
    }
};

int main()
{
	Solution sol;
	std::vector<std::vector<int> > g = 
	// {
	// 	{1,1},
	// 	{1,0},
	// };//3*2 + 2*2 + 2*2=14
		// {
		// 	{1,2},
		// 	{3,4}
		// };
		// {
		// 	{1,1,1},
		// 	{1,0,1},
		// 	{1,1,1}
		// };
	{
		{2,2,2},
		{2,1,2},
		{2,2,2}
	};
	printf("%d\n",sol.surfaceArea(g));
	return 0;
}



