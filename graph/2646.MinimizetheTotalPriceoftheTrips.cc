/*
   There exists an undirected and unrooted tree with n nodes indexed from 0 to n - 1. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

   Each node has an associated price. You are given an integer array price, where price[i] is the price of the ith node.

   The price sum of a given path is the sum of the prices of all nodes lying on that path.

   Additionally, you are given a 2D integer array trips, where trips[i] = [starti, endi] indicates that you start the ith trip from the node starti and travel to the node endi by any path you like.

   Before performing your first trip, you can choose some non-adjacent nodes and halve the prices.

   Return the minimum total price sum to perform all the given trips.



   Example 1:

Input: n = 4, edges = [[0,1],[1,2],[1,3]], price = [2,2,10,6], trips = [[0,3],[2,1],[2,3]]
Output: 23
Explanation: The diagram above denotes the tree after rooting it at node 2. The first part shows the initial tree and the second part shows the tree after choosing nodes 0, 2, and 3, and making their price half.
For the 1st trip, we choose path [0,1,3]. The price sum of that path is 1 + 2 + 3 = 6.
For the 2nd trip, we choose path [2,1]. The price sum of that path is 2 + 5 = 7.
For the 3rd trip, we choose path [2,1,3]. The price sum of that path is 5 + 2 + 3 = 10.
The total price sum of all trips is 6 + 7 + 10 = 23.
It can be proven, that 23 is the minimum answer that we can achieve.

Example 2:

Input: n = 2, edges = [[0,1]], price = [2,2], trips = [[0,0]]
Output: 1
Explanation: The diagram above denotes the tree after rooting it at node 0. The first part shows the initial tree and the second part shows the tree after choosing node 0, and making its price half.
For the 1st trip, we choose path [0]. The price sum of that path is 1.
The total price sum of all trips is 1. It can be proven, that 1 is the minimum answer that we can achieve.



Constraints:

1 <= n <= 50
edges.length == n - 1
0 <= ai, bi <= n - 1
edges represents a valid tree.
price.length == n
price[i] is an even integer.
1 <= price[i] <= 1000
1 <= trips.length <= 100
0 <= starti, endi <= n - 1

*/


#include"head.h"
class Solution {
	public:
		int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
			vector<vector<int>> g(n);
			for(int i=0;i<edges.size();i++)
			{
				int x=edges[i][0],y=edges[i][1];
				g[x].push_back(y);
				g[y].push_back(x);
			}
			vector<int> cnt(n,0);
			vector<vector<int>> dp(n,vector<int>(2,0));
			for(int i=0;i<trips.size();i++)
				dfs(trips[i][0],-1,trips[i][1],g,cnt);

			dfs1(0,-1,price,cnt,dp,g);
			return min(dp[0][0],dp[0][1]);
		}
		bool dfs(int u,int pa,int v,vector<vector<int>> &g,vector<int> &cnt)
		{
			if(u==v)
			{
				cnt[u]++;
				return true;
			}
			for(int i=0;i<g[u].size();i++)
			{
				int uson=g[u][i];
				if(pa==uson)
					continue;
				if(dfs(uson,u,v,g,cnt))
				{
					cnt[u]++;
					return true;
				}
			}
			return false;
		}
		void dfs1(int u,int pa,const vector<int>&p,const vector<int>&cnt,vector<vector<int>> &dp,vector<vector<int>> &g)
		{
			dp[u][1]=(cnt[u]*p[u])/2;
			dp[u][0]=cnt[u]*p[u];

			for(int i=0;i<g[u].size();i++)
			{
				int v=g[u][i];
				if(v==pa) continue;
				dfs1(v,u,p,cnt,dp,g);
				dp[u][1]+=dp[v][0];
				dp[u][0]+=min(dp[v][0],dp[v][1]);
			}
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> e={{0,1},{1,2},{1,3}},t={{0,3},{2,1},{2,3}};
	vector<int> p={2,2,10,6};
	cout<<s.minimumTotalPrice(4,e,p,t)<<endl;
	e.clear();e={{0,1}};
	p.clear();p={2,2};
	t.clear();t={{0,0}};
	cout<<s.minimumTotalPrice(2,e,p,t)<<endl;
	return 0;
}
