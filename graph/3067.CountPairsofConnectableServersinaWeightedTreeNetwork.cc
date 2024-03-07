/*
   You are given an unrooted weighted tree with n vertices representing servers numbered from 0 to n - 1, an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional edge between vertices ai and bi of weight weighti. You are also given an integer signalSpeed.

   Two servers a and b are connectable through a server c if:

   a < b, a != c and b != c.
   The distance from c to a is divisible by signalSpeed.
   The distance from c to b is divisible by signalSpeed.
   The path from c to b and the path from c to a do not share any edges.

   Return an integer array count of length n where count[i] is the number of server pairs that are connectable through the server i.



   Example 1:

Input: edges = [[0,1,1],[1,2,5],[2,3,13],[3,4,9],[4,5,2]], signalSpeed = 1
Output: [0,4,6,6,4,0]
Explanation: Since signalSpeed is 1, count[c] is equal to the number of pairs of paths that start at c and do not share any edges.
In the case of the given path graph, count[c] is equal to the number of servers to the left of c multiplied by the servers to the right of c.

Example 2:

Input: edges = [[0,6,3],[6,5,3],[0,3,1],[3,2,7],[3,1,6],[3,4,2]], signalSpeed = 3
Output: [2,0,0,0,0,0,2]
Explanation: Through server 0, there are 2 pairs of connectable servers: (4, 5) and (4, 6).
Through server 6, there are 2 pairs of connectable servers: (4, 5) and (0, 5).
It can be shown that no two servers are connectable through servers other than 0 and 6.



Constraints:

2 <= n <= 1000
edges.length == n - 1
edges[i].length == 3
0 <= ai, bi < n
edges[i] = [ai, bi, weighti]
1 <= weighti <= 106
1 <= signalSpeed <= 106
The input is generated such that edges represents a valid tree.

*/


#include"head.h"
class Solution {
	public:
		vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
		vector<vector<pair<int,int>>> g;
		const int n=edges.size()+1;
		g.resize(n);
		for(int i=0;i<n-1;i++)
		{
			int u=edges[i][0],v=edges[i][1],w=edges[i][2];
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
		vector<int> res(n,0);
		for(int i=0;i<n;i++)
		{
			int sum=0;
			for(int j=0;j<g[i].size();j++)
			{
				int cnt=0;
				dfs(g,g[i][j].first,i,g[i][j].second,signalSpeed,cnt);
				res[i]+=sum*cnt;
				sum+=cnt;
			}
		}
		return res;
		}
		void dfs(vector<vector<pair<int,int>>>&g,int u,int pa,int w,int signalSpeed,int &cnt)
		{
			if(w%signalSpeed==0)
				++cnt;
			for(int i=0;i<g[u].size();i++)
			{
				if(g[u][i].first==pa)
					continue;
				dfs(g,g[u][i].first,u,w+g[u][i].second,signalSpeed,cnt);
			}
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> edges = {{0,1,1},{1,2,5},{2,3,13},{3,4,9},{4,5,2}};
	show(s.countPairsOfConnectableServers(edges,1));
	edges.clear();edges = {{0,6,3},{6,5,3},{0,3,1},{3,2,7},{3,1,6},{3,4,2}};
	show(s.countPairsOfConnectableServers(edges,3));
	return 0;
}
