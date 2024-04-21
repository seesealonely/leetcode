/*
   You are given an undirected weighted graph of n nodes numbered from 0 to n - 1. The graph consists of m edges represented by a 2D array edges, where edges[i] = [ai, bi, wi] indicates that there is an edge between nodes ai and bi with weight wi.

   Consider all the shortest paths from node 0 to node n - 1 in the graph. You need to find a boolean array answer where answer[i] is true if the edge edges[i] is part of at least one shortest path. Otherwise, answer[i] is false.

   Return the array answer.

   Note that the graph may not be connected.



   Example 1:

Input: n = 6, edges = [[0,1,4],[0,2,1],[1,3,2],[1,4,3],[1,5,1],[2,3,1],[3,5,3],[4,5,2]]

Output: [true,true,true,false,true,true,true,false]

Explanation:

The following are all the shortest paths between nodes 0 and 5:

The path 0 -> 1 -> 5: The sum of weights is 4 + 1 = 5.
The path 0 -> 2 -> 3 -> 5: The sum of weights is 1 + 1 + 3 = 5.
The path 0 -> 2 -> 3 -> 1 -> 5: The sum of weights is 1 + 1 + 2 + 1 = 5.

Example 2:

Input: n = 4, edges = [[2,0,1],[0,1,1],[0,3,4],[3,2,2]]

Output: [true,false,false,true]

Explanation:

There is one shortest path between nodes 0 and 3, which is the path 0 -> 2 -> 3 with the sum of weights 1 + 2 = 3.



Constraints:

2 <= n <= 5 * 104
m == edges.length
1 <= m <= min(5 * 104, n * (n - 1) / 2)
0 <= ai, bi < n
ai != bi
1 <= wi <= 105
There are no repeated edges.

*/


#include"head.h"
class Solution {
	public:
		vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
			const int m=edges.size();
			vector<int> d1,d2;
			vector<vector<pair<int,int>>> g(n);
			for(int i=0;i<m;i++)
			{
				int x=edges[i][0],y=edges[i][1],w=edges[i][2];
				g[x].push_back({y,w});
				g[y].push_back({x,w});
			}

			dijkstra(0,n,d1,g);
			dijkstra(n-1,n,d2,g);

			vector<bool> res(m,false);
			if(d1[n-1]==INT_MAX)
				return res;

			for(int i=0;i<m;i++)
			{
				int u=edges[i][0],v=edges[i][1],w=edges[i][2];
				if((long long)d1[u]+w+d2[v]==d1[n-1]||(long long)d1[v]+w+d2[u]==d1[n-1])
					res[i]=true;
			}
			return res;
		}
		void dijkstra(int i,int n,vector<int> &dis,const vector<vector<pair<int,int>>> &g)
		{
			priority_queue<pair<int,int>> q;
			q.push({i,0});

			dis.resize(n,INT_MAX);
			dis[i]=0;

			while(!q.empty())
			{
				pair<int,int> t=q.top();q.pop();
				int u=t.first,d=-t.second;
				if(d>dis[u])
					continue;

				for(int i=0;i<g[u].size();i++)
				{
					int v=g[u][i].first,w=g[u][i].second;

					if(dis[v]>dis[u]+w)
					{
						dis[v]=dis[u]+w;
						q.push({v,-dis[v]});
					}
				}
			}
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> edges = {{0,1,4},{0,2,1},{1,3,2},{1,4,3},{1,5,1},{2,3,1},{3,5,3},{4,5,2}};
	show(s.findAnswer(6,edges));
	edges.clear();
	edges = {{2,0,1},{0,1,1},{0,3,4},{3,2,2}};
	show(s.findAnswer(4,edges));
	return 0;
}
