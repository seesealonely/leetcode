/*
   There is a strange printer with the following two special requirements:

   On each turn, the printer will print a solid rectangular pattern of a single color on the grid. This will cover up the existing colors in the rectangle.
   Once the printer has used a color for the above operation, the same color cannot be used again.

   You are given a m x n matrix targetGrid, where targetGrid[row][col] is the color in the position (row, col) of the grid.

   Return true if it is possible to print the matrix targetGrid, otherwise, return false.



   Example 1:

Input: targetGrid = [[1,1,1,1],[1,2,2,1],[1,2,2,1],[1,1,1,1]]
Output: true

Example 2:

Input: targetGrid = [[1,1,1,1],[1,1,3,3],[1,1,3,4],[5,5,1,4]]
Output: true

Example 3:

Input: targetGrid = [[1,2,1],[2,1,2],[1,2,1]]
Output: false
Explanation: It is impossible to form targetGrid because it is not allowed to print the same color in different turns.



Constraints:

m == targetGrid.length
n == targetGrid[i].length
1 <= m, n <= 60
1 <= targetGrid[row][col] <= 60

*/


#include"head.h"
class Solution {
	public:
		int r,c,total;
		bool isPrintable(vector<vector<int>>& targetGrid) {
		r=targetGrid.size(),c=targetGrid.back().size();
		total=60;
		vector<vector<int>> g(total+1);
		vector<int> degree(total+1,0);

		for(int i=1;i<total+1;i++)
			getGraph(i,targetGrid,g,degree);

		queue<int> q;
		for(int i=1;i<total+1;i++)
			if(degree[i]==0)
				q.push(i);

		int tot=0;
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			tot++;
			for(int i=0;i<g[u].size();i++)
			{
				int v=g[u][i];
				if(--degree[v]==0)
					q.push(v);
			}
		}

		return tot==total;
		}
		void getGraph(int u,const vector<vector<int>> &targetGrid,
				vector<vector<int>> &g,vector<int> &degree)
		{
			int x1=INT_MAX,y1=INT_MAX,x2=INT_MIN,y2=INT_MIN;
			for(int i=0;i<r;i++)
				for(int j=0;j<c;j++)
					if(targetGrid[i][j]==u)
					{
						x1=min(x1,i),y1=min(y1,j);
						x2=max(x2,i),y2=max(y2,j);
					}

			if(x1==INT_MAX)
				return ;

			vector<bool> vis(c+1,false);
			vis[u]=true;

			for(int i=x1;i<=x2;i++)
				for(int j=y1;j<=y2;j++)
				{
					int v=targetGrid[i][j];
					if(vis[v]) continue;
					vis[v]=true;
					g[u].push_back(v);
					degree[v]++;
				}
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> targetGrid = {{1,1,1,1},{1,2,2,1},{1,2,2,1},{1,1,1,1}};
	cout<<s.isPrintable(targetGrid)<<endl;
	targetGrid.clear();targetGrid = {{1,1,1,1},{1,1,3,3},{1,1,3,4},{5,5,1,4}};
	cout<<s.isPrintable(targetGrid)<<endl;
	targetGrid.clear();targetGrid = {{1,2,1},{2,1,2},{1,2,1}};
	cout<<s.isPrintable(targetGrid)<<endl;
	return 0;
}
