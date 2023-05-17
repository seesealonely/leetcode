/*
   There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

   A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

   Return all critical connections in the network in any order.



   Example 1:

Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.

Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]



Constraints:

2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.

*/


#include"head.h"
class Solution {
	public:
		vector<int> dfn,low;
		vector<vector<int>> res;
		vector<vector<int>> g;
		int count;
		void tarjan(int x,int pa)
		{
			dfn[x]=low[x]=++count;

			bool flag=false;

			for(int i=0;i<g[x].size();i++)
			{
				int y=g[x][i];
				if(!dfn[y]){
					tarjan(y,x);
					low[x]=min(low[x],low[y]);
					if(dfn[x]<low[y])
						res.push_back({x,y});
				}
				else
				{
					if(y==pa)
					{
						if(flag)
							low[x]=min(low[x],dfn[y]);
						flag=true;
					}
					else
						low[x]=min(low[x],dfn[y]);
				}
			}
		}
		vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
		g.resize(n);

		for(int i=0;i<connections.size();i++)
		{
			int x=connections[i][0],y=connections[i][1];
			g[x].push_back(y);
			g[y].push_back(x);
		}

		dfn.resize(n,0);
		low.resize(n,0);

		count=0;
		for(int i=0;i<n;i++)
			if(!dfn[i])
				tarjan(i,-1);
		return res;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
	show(s.criticalConnections(4,connections));
	connections.clear();connections={{0,1}};
	show(s.criticalConnections(2,connections));
	return 0;
}
