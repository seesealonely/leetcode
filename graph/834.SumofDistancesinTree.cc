/*
   There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

   You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

   Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.



   Example 1:

Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]
Explanation: The tree is shown above.
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.
Hence, answer[0] = 8, and so on.

Example 2:

Input: n = 1, edges = []
Output: [0]

Example 3:

Input: n = 2, edges = [[1,0]]
Output: [1,1]



Constraints:

1 <= n <= 3 * 104
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
The given input represents a valid tree.

*/


#include"head.h"
class Solution {
	public:
		vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
		vector<vector<int>> g(n);
		for(int i=0;i<edges.size();i++)
		{
			int x=edges[i][0],y=edges[i][1];
			g[x].push_back(y);
			g[y].push_back(x);
		}

		vector<int> steps(n,0),res(n,0);
		dfs1(0,-1,g,steps,res);
		dfs2(0,-1,g,steps,res,n);
		return res;	
		}
		void dfs1(int u,int pa,const vector<vector<int>> &g,vector<int> &steps,vector<int> &res)
		{
			for(int i=0;i<g[u].size();i++)
			{
				int v=g[u][i];
				if(v!=pa)
				{
					dfs1(v,u,g,steps,res);
				steps[u]+=steps[v];
				res[u]+=res[v]+steps[v];
				}
			}
			steps[u]++;
		}
		void dfs2(int u,int pa,const vector<vector<int>> &g,const vector<int> &steps,vector<int> &res,int n)
		{
			for(int i=0;i<g[u].size();i++)
			{
				int v=g[u][i];
				if(v!=pa)
				{
					res[v]=res[u]-steps[v]+n-steps[v];
					dfs2(v,u,g,steps,res,n);
				}
			}
		}

};


int main() 
{
	Solution s;
	vector<vector<int>> e={{0,1},{0,2},{2,3},{2,4},{2,5}};
	show(s.sumOfDistancesInTree(6,e));
	return 0;
}
