/*
   There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

   The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

   The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

   Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.



   Example 1:

Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean
[0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean
[1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
[1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
[2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean
[3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean
[3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean
[4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.

Example 2:

Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.



Constraints:

m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 105

*/


#include"head.h"
		static const int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
class Solution {
	public:
		vector<vector<int>> heights;
		void dfs(int row,int col,vector<vector<bool>> &ocean)
		{
			int r=ocean.size();
			int c=ocean[0].size();
			if(ocean[row][col])
				return ;

			ocean[row][col]=true;

			for(int i=0;i<4;i++)
			{
				int newr=row+dir[i][0],newc=col+dir[i][1];
				if(newr>=0&&newr<r&&newc>=0&&newc<c&&heights[newr][newc]>=heights[row][col])
					dfs(newr,newc,ocean);
			}
		}
		vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		this->heights=heights;
		int r=heights.size();
		int c=heights[0].size();

		vector<vector<bool>> pacific(r,vector<bool>(c,false));
		vector<vector<bool>> atlantic(r,vector<bool>(c,false));

		for(int i=0;i<r;i++)
			dfs(i,0,pacific);

		for(int j=1;j<c;j++)
			dfs(0,j,pacific);

		for(int i=0;i<r;i++)
			dfs(i,c-1,atlantic);

		for(int j=0;j<c-1;j++)
			dfs(r-1,j,atlantic);

		vector<vector<int>> res;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if(pacific[i][j]&&atlantic[i][j])
				{
					vector<int> cur;
					cur.push_back(i);
					cur.push_back(j);
					res.push_back(cur);
				}
		return res;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> heights= {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
	show(s.pacificAtlantic(heights));
	heights.clear();heights={{1}};
	show(s.pacificAtlantic(heights));
	return 0;
}
