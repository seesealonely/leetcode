/*
   You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

   You are given two arrays redEdges and blueEdges where:

   redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
   blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.

   Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.



   Example 1:

Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
Output: [0,1,-1]

Example 2:

Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
Output: [0,1,-1]



Constraints:

1 <= n <= 100
0 <= redEdges.length, blueEdges.length <= 400
redEdges[i].length == blueEdges[j].length == 2
0 <= ai, bi, uj, vj < n

*/


#include"head.h"
class Solution {
	public:
		vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
		vector<vector<pair<int,int>>> g(n);

		for(int i=0;i<redEdges.size();i++)
		{
			int x=redEdges[i][0],y=redEdges[i][1];
			g[x].push_back({y,0});
		}

		for(int i=0;i<blueEdges.size();i++)
		{
			int x=blueEdges[i][0],y=blueEdges[i][1];
			g[x].push_back({y,1});
		}
		vector<vector<int>> dis(n,vector<int>(2,INT_MAX));

		bfs(g,dis);

		vector<int> res(n);
		for(int i=0;i<n;i++)
		{
			res[i]=min(dis[i][0],dis[i][1]);
			if(res[i]==INT_MAX)
				res[i]=-1;
		}

		return res;
		}
		void bfs(const vector<vector<pair<int,int>>> &g,vector<vector<int>> &dis)
		{
			queue<pair<int,int>> q;
			dis[0][0]=dis[0][1]=0;
			q.push({0,0});
			q.push({0,1});
			while(!q.empty())
			{
				pair<int,int> c=q.front();
				q.pop();
				int u=c.first,uc=c.second;
				for(int i=0;i<g[u].size();i++)
				{
					int v=g[u][i].first,vc=g[u][i].second;
					if(uc!=vc&&dis[v][vc]>dis[u][uc]+1)
					{
						dis[v][vc]=dis[u][uc]+1;
						q.push({v,vc});
					}
				}
			}
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> r={{0,1},{1,2}},b;
	show(s.shortestAlternatingPaths(3,r,b));
	r.clear();r={{0,1}};
	b.clear();b={{2,1}};
	show(s.shortestAlternatingPaths(3,r,b));
	r.clear();r={{1,0}};
	show(s.shortestAlternatingPaths(3,r,b));
	r.clear();r={{0,1}};
	b.clear();b={{1,2}};
	show(s.shortestAlternatingPaths(3,r,b));
	r.clear();r={{0,1},{0,2}};
	b.clear();b={{1,0}};
	show(s.shortestAlternatingPaths(3,r,b));
	return 0;
}
