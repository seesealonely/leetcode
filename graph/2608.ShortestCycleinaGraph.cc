/*
   There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1. The edges in the graph are represented by a given 2D integer array edges, where edges[i] = [ui, vi] denotes an edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

   Return the length of the shortest cycle in the graph. If no cycle exists, return -1.

   A cycle is a path that starts and ends at the same node, and each edge in the path is used only once.



   Example 1:

Input: n = 7, edges = [[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]
Output: 3
Explanation: The cycle with the smallest length is : 0 -> 1 -> 2 -> 0

Example 2:

Input: n = 4, edges = [[0,1],[0,2]]
Output: -1
Explanation: There are no cycles in this graph.



Constraints:

2 <= n <= 1000
1 <= edges.length <= 1000
edges[i].length == 2
0 <= ui, vi < n
ui != vi
There are no repeated edges.

*/


#include"head.h"
class Solution {
	public:
		int findShortestCycle(int n, vector<vector<int>>& edges) {
		vector<vector<int>> g(n);
		for(int i=0;i<edges.size();i++)
		{
			int x=edges[i][0],y=edges[i][1];
			g[x].push_back(y);
			g[y].push_back(x);
		}

		int res=INT_MAX;
		for(int i=0;i<n;i++)
		res=min(res,bfs(g,i));

		return res==INT_MAX?-1:res;
		}
		int bfs(vector<vector<int>> &g,int i)
		{
			vector<int> dist(g.size(),INT_MAX);
			dist[i]=0;
			queue<int> q;q.push(i);
			while(!q.empty())
			{
				int u=q.front();q.pop();
				for(int i=0;i<g[u].size();i++)
				{
					int v=g[u][i];
					if(dist[v]==INT_MAX)
					{
						dist[v]=dist[u]+1;
						q.push(v);
					}
					else if(dist[v]+1!=dist[u])
					{
						return dist[u]+dist[v]+1;
					}
				}
			}
			return INT_MAX;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> v={{0,1},{1,2},{2,0},{3,4},{4,5},{5,6},{6,3}};
	cout<<s.findShortestCycle(7,v)<<endl;
	v.clear();v={{0,1},{0,2}};
	cout<<s.findShortestCycle(4,v)<<endl;
	return 0;
}
