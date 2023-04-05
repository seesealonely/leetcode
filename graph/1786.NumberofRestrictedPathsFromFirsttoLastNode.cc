/*
   There is an undirected weighted connected graph. You are given a positive integer n which denotes that the graph has n nodes labeled from 1 to n, and an array edges where each edges[i] = [ui, vi, weighti] denotes that there is an edge between nodes ui and vi with weight equal to weighti.

   A path from node start to node end is a sequence of nodes [z0, z1, z2, ..., zk] such that z0 = start and zk = end and there is an edge between zi and zi+1 where 0 <= i <= k-1.

   The distance of a path is the sum of the weights on the edges of the path. Let distanceToLastNode(x) denote the shortest distance of a path between node n and node x. A restricted path is a path that also satisfies that distanceToLastNode(zi) > distanceToLastNode(zi+1) where 0 <= i <= k-1.

   Return the number of restricted paths from node 1 to node n. Since that number may be too large, return it modulo 109 + 7.



   Example 1:

Input: n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
Output: 3
Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The three restricted paths are:
1) 1 --> 2 --> 5
2) 1 --> 2 --> 3 --> 5
3) 1 --> 3 --> 5

Example 2:

Input: n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]
Output: 1
Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The only restricted path is 1 --> 3 --> 7.



Constraints:

1 <= n <= 2 * 104
n - 1 <= edges.length <= 4 * 104
edges[i].length == 3
1 <= ui, vi <= n
ui != vi
1 <= weighti <= 105
There is at most one edge between any two nodes.
There is at least one path between any two nodes.

*/


#include"head.h"
class Solution {
	public:
		static const int mod=1e9+7;
		class node
		{
			public:
				int u,w;
			node(int uu,int ww):u(uu),w(ww){}
			bool operator <(const node &p) const 
			{
				return w>p.w;
			}
		};
		int countRestrictedPaths(int n, vector<vector<int>>& edges) {
		vector<vector<pair<int,int>>> g(n);

		for(int i=0;i<edges.size();i++)
		{
			int x=edges[i][0]-1,y=edges[i][1]-1,w=edges[i][2];
			g[x].push_back({y,w});
			g[y].push_back({x,w});
		}

		vector<int> dis(n,INT_MAX);
		priority_queue<node> q;

		dis[n-1]=0;
		q.push(node(n-1,0));

		while(!q.empty())
		{
			node u=q.top();
			q.pop();

			for(int i=0;i<g[u.u].size();i++)
			{
				int v=g[u.u][i].first,w=g[u.u][i].second;
				if(dis[v]>dis[u.u]+w)
				{
					dis[v]=dis[u.u]+w;
					q.push(node(v,dis[v]));
				}
			}
		}

		vector<int> f(n,-1);

		return dfs(0,n,f,dis,g);
		}
		int dfs(int u,int n,vector<int>&f,const vector<int> &dis,const vector<vector<pair<int,int>>> &g)
		{
			if(f[u]!=-1)
				return f[u];

			if(u==n-1)
				return f[u]=1;

			f[u]=0;
			for(int i=0;i<g[u].size();i++)
			{
				int v=g[u][i].first;
				if(dis[v]<dis[u])
					f[u]=(f[u]+dfs(v,n,f,dis,g))%mod;
			}
			return f[u];
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> e={{1,2,3},{1,3,3},{2,3,1},{1,4,2},{5,2,2},{3,5,1},{5,4,10}};
	cout<<s.countRestrictedPaths(5,e)<<endl;
	e.clear();e={{1,3,1},{4,1,2},{7,3,4},{2,5,3},{5,6,1},{6,7,2},{7,5,3},{2,6,4}};
	cout<<s.countRestrictedPaths(7,e)<<endl;
	return 0;
}
