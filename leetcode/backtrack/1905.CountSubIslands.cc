/*
   You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

   An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

   Return the number of islands in grid2 that are considered sub-islands.



   Example 1:

Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.

Example 2:

Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.



Constraints:

m == grid1.length == grid2.length
n == grid1[i].length == grid2[i].length
1 <= m, n <= 500
grid1[i][j] and grid2[i][j] are either 0 or 1.

*/
#include"head.h"
class Solution {
	public:
		int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
			int r=grid1.size(),c=grid1[0].size(),res=0;
			vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
			for(int i=0;i<r;i++)
				for(int j=0;j<c;j++)
					if(grid2[i][j])
						res+=backTrace(grid1,grid2,dir,i,j);
			return res;
		}
		bool backTrace(vector<vector<int> > &g1,vector<vector<int> > &g2,vector<vector<int> > &dir,int x,int y)
		{
			bool res=true;
			g2[x][y]=0;
			if(g1[x][y]==0)
	//				return false;
			res=false;
			for(int i=0;i<4;i++)
			{
				int cx=x+dir[i][0],cy=y+dir[i][1];
				if(cx<0||cy<0||cx>=g1.size()||cy>=g1[0].size()||g2[cx][cy]==0)
					continue;
				if(!backTrace(g1,g2,dir,cx,cy))
				//	return false;
				res=false;
			}
			return res;
		}
};
int main() 
{
	Solution s;
	vector<vector<int> > v1={{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}},v2={{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};
	cout<<s.countSubIslands(v1,v2)<<endl;
	v1.clear();v2.clear();v1={{1,0,1,0,1},{1,1,1,1,1},{0,0,0,0,0},{1,1,1,1,1},{1,0,1,0,1}};v2= {{0,0,0,0,0},{1,1,1,1,1},{0,1,0,1,0},{0,1,0,1,0},{1,0,0,0,1}};
	cout<<s.countSubIslands(v1,v2)<<endl;
	return 0;
}
