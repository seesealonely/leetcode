/*
   You are asked to cut off all the trees in a forest for a golf event. The forest is represented as an m x n matrix. In this matrix:

   0 means the cell cannot be walked through.
   1 represents an empty cell that can be walked through.
   A number greater than 1 represents a tree in a cell that can be walked through, and this number is the tree's height.

   In one step, you can walk in any of the four directions: north, east, south, and west. If you are standing in a cell with a tree, you can choose whether to cut it off.

   You must cut off the trees in order from shortest to tallest. When you cut off a tree, the value at its cell becomes 1 (an empty cell).

   Starting from the point (0, 0), return the minimum steps you need to walk to cut off all the trees. If you cannot cut off all the trees, return -1.

Note: The input is generated such that no two trees have the same height, and there is at least one tree needs to be cut off.



Example 1:

Input: forest = [[1,2,3],[0,0,4],[7,6,5]]
Output: 6
Explanation: Following the path above allows you to cut off the trees from shortest to tallest in 6 steps.

Example 2:

Input: forest = [[1,2,3],[0,0,0],[7,6,5]]
Output: -1
Explanation: The trees in the bottom row cannot be accessed as the middle row is blocked.

Example 3:

Input: forest = [[2,3,4],[0,0,5],[8,7,6]]
Output: 6
Explanation: You can follow the same path as Example 1 to cut off all the trees.
Note that you can cut off the first tree at (0, 0) before making any steps.



Constraints:

m == forest.length
n == forest[i].length
1 <= m, n <= 50
0 <= forest[i][j] <= 109
Heights of all trees are distinct.

*/


#include"head.h"
class Solution {
	public:
		int cutOffTree(vector<vector<int>>& forest) {
		const int r=forest.size(),c=forest[0].size();
		vector<pair<int,pair<int,int>>> trees;

		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if(forest[i][j]>1)
				trees.push_back(make_pair(forest[i][j],make_pair(i,j)));

		trees.push_back(make_pair(0,make_pair(0,0)));
		sort(trees.begin(),trees.end());
		int t=trees.size(),res=0;
		for(int i=1;i<t;i++)
		{
			int d=bfs(trees[i-1].second,trees[i].second,r,c,forest);
			if(d==-1)
				return -1;
			res+=d;
		}
		return res;
		}
		int bfs(const pair<int,int> &s,const pair<int,int> &t,int r, int c,const vector<vector<int>> &forest)
		{
			const  vector<vector<int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
			vector<vector<int>> dist(r,vector<int>(c,-1));
			queue<pair<int,int>> q;
			dist[s.first][s.second]=0;
			q.push(s);
			while(!q.empty())
			{
				pair<int,int> cur=q.front();
				q.pop();
				if(cur.first==t.first&&cur.second==t.second)
					return dist[t.first][t.second];
				for(int i=0;i<4;i++)
				{
					int x=cur.first+dirs[i][0],y=cur.second+dirs[i][1];
					if(x>=r||x<0||y>=c||y<0||forest[x][y]==0)
						continue;
					if(dist[x][y]==-1)
					{
						dist[x][y]=dist[cur.first][cur.second]+1;
						q.push(make_pair(x,y));
					}
				}
			}

			return -1;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> forest = {{1,2,3},{0,0,4},{7,6,5}};
	cout<<s.cutOffTree(forest)<<endl;
	forest.clear();forest={{1,2,3},{0,0,0},{7,6,5}};
	cout<<s.cutOffTree(forest)<<endl;
	forest.clear();forest={{2,3,4},{0,0,5},{8,7,6}};
	cout<<s.cutOffTree(forest)<<endl;
	return 0;
}
