/*
   There exist two undirected trees with n and m nodes, numbered from 0 to n - 1 and from 0 to m - 1, respectively. You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.

   You must connect one node from the first tree with another node from the second tree with an edge.

   Return the minimum possible diameter of the resulting tree.

   The diameter of a tree is the length of the longest path between any two nodes in the tree.



   Example 1:

Input: edges1 = [[0,1],[0,2],[0,3]], edges2 = [[0,1]]

Output: 3

Explanation:

We can obtain a tree of diameter 3 by connecting node 0 from the first tree with any node from the second tree.

Example 2:

Input: edges1 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]], edges2 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]

Output: 5

Explanation:

We can obtain a tree of diameter 5 by connecting node 0 from the first tree with node 0 from the second tree.



Constraints:

1 <= n, m <= 105
edges1.length == n - 1
edges2.length == m - 1
edges1[i].length == edges2[i].length == 2
edges1[i] = [ai, bi]
0 <= ai, bi < n
edges2[i] = [ui, vi]
0 <= ui, vi < m
The input is generated such that edges1 and edges2 represent valid trees.

*/


#include"head.h"
class Solution {
	public:
		int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
		int d1=getDiameter(edges1);
		int d2=getDiameter(edges2);
		return max({d1,d2,(d1+1)/2+(d2+1)/2+1});
		}
		int getDiameter(vector<vector<int>> &edges)
		{
			vector<vector<int>> g(edges.size()+1);
			for(int i=0;i<edges.size();i++)
			{
				int u=edges[i][0],v=edges[i][1];
				g[u].push_back(v);
				g[v].push_back(u);
			}
			int res=0;
			dfs(g,0,-1,res);
			return res;
		}
		int dfs(vector<vector<int>> &g,int u,int pa,int &res)
		{
			int mx=0;
			for(int i=0;i<g[u].size();i++)
			if(g[u][i]!=pa)
			{
				int cur=dfs(g,g[u][i],u,res)+1;
				res=max(res,mx+cur);
				mx=max(mx,cur);
			}
			return mx;
		}
};


int main() 
{
	Solution s;
vector<vector<int>> edges1 = {{0,1},{0,2},{0,3}}, edges2 = {{0,1}};	
	cout<<s.minimumDiameterAfterMerge(edges1,edges2)<<endl;
	edges1.clear();edges2.clear();
	edges1 = {{0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7}}, edges2 = {{0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7}};
	cout<<s.minimumDiameterAfterMerge(edges1,edges2)<<endl;
	return 0;
}
