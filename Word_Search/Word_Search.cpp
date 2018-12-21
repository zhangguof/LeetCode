// Word Search
//   Go to Discuss
// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

// Example:

// board =
// {
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]

// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
	bool dfs_search(vector<vector<char> >& board, int i0,int j0,
					string& word,int ich,
					vector<bool>& mark)
	{
		int n = board.size();
		int m = board[0].size();
		// if(ich == word.size()) return true;

		int di[] = {0,1,0,-1};//row
		int dj[] = {1,0,-1,0};//col
		if(board[i0][j0] != word[ich])
		{
			return false;
		}
		mark[i0*m+j0] = true;
		if(ich == word.size()-1)
		{
			// printf("%d,%d,%d\n",i0,j0,ich);
			return true;
		}
		for(int k=0;k<4;++k)
		{
			int i = i0+di[k];
			int j = j0+dj[k];
			if(i<0 || i>=n || j<0 || j>=m || mark[i*m+j]) continue;
			auto ret = dfs_search(board,i,j,word,ich+1,mark);
			if(ret) return true;
			mark[i*m+j] = false;
		}
		return false;
	}
    bool exist(vector<vector<char> >& board, string word) {
        bool ret =false;
        int n = board.size();
        if(n == 0) return false;
        int m = board[0].size();
        vector<bool> mark(n*m,false);
        for(int i=0;i<n;++i)
        {
        	for(int j=0;j<m;++j)
        	{
        		auto m = mark;
        		ret = dfs_search(board,i,j,word,0,m);
        		if(ret) return true;
        	}
        }
        return false;
    }
};

int main()
{
	vector<vector<char> > b = {
		// {'A','B','C','E'},
		// {'S','F','C','S'},
		// {'A','D','E','E'}
		{'A','B','C','E'},
		{'S','F','E','S'},
		{'A','D','E','E'}

	};
	// string w = "ABCEFSADEESE";
	string w = "SFED";
	Solution sol;
	printf("%d\n",sol.exist(b,w));

	return 0;
}
