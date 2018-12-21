
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    void do_dfs(vector<vector<char>>& g,int r0,int c0,int n,int m)
    {
        // int n = g.size();
        // int m = g[0].size();
        if(g[r0][c0]=='0') return;
        
        g[r0][c0] = '0';
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        for(int i=0;i<4;++i)
        {
          int r = r0+dy[i];
          int c = c0+dx[i];
          if(r>=0 && r<n && c>=0 && c<m)
          {
              do_dfs(g,r,c,n,m);
          }
        }
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n==0) return 0;
        int m = grid[0].size();
        int cnt = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]=='0') continue;
                
                cnt++;
                do_dfs(grid,i,j,n,m);
            }
        }
        return cnt;
        
    }
};

int main()
{
	Solution sol;
	vector<vector<char> > g = {
	{'1','1','1','1','0'},
	{'1','1','0','1','0'},
	{'1','1','0','0','0'},
	{'0','0','0','0','0'}
	};
	printf("%d\n",sol.numIslands(g));

	return 0;
}
