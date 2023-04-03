/*
   There exists an undirected and unrooted tree with n nodes indexed from 0 to n - 1. You are given an integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. You are also given an array coins of size n where coins[i] can be either 0 or 1, where 1 indicates the presence of a coin in the vertex i.

   Initially, you choose to start at any vertex in the tree. Then, you can perform the following operations any number of times:

   Collect all the coins that are at a distance of at most 2 from the current vertex, or
   Move to any adjacent vertex in the tree.

   Find the minimum number of edges you need to go through to collect all the coins and go back to the initial vertex.

   Note that if you pass an edge several times, you need to count it into the answer several times.



   Example 1:

Input: coins = [1,0,0,0,0,1], edges = [[0,1],[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: Start at vertex 2, collect the coin at vertex 0, move to vertex 3, collect the coin at vertex 5 then move back to vertex 2.

Example 2:

Input: coins = [0,0,0,1,1,0,0,1], edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[5,6],[5,7]]
Output: 2
Explanation: Start at vertex 0, collect the coins at vertices 4 and 3, move to vertex 2, collect the coin at vertex 7, then move back to vertex 0.



Constraints:

n == coins.length
1 <= n <= 3 2115.FindAllPossibleRecipesfromGivenSupplies.cc 2603.CollectCoinsinaTree.cc 851.LoudandRich.cc head.cc head.h head.o l.sh makefile 104
0 <= coins[i] <= 1
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
edges represents a valid tree.

*/


#include"head.h"
class Solution {
	public:
		int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
		const int n=coins.size();
		vector<vector<int>> g(n);
		vector<int> degree(n);
		for(int i=0;i<edges.size();i++)
		{
			int x=edges[i][0],y=edges[i][1];
			g[x].push_back(y);
			g[y].push_back(x);
			degree[x]++;
			degree[y]++;
		}

		queue<int> q;
		for(int i=0;i<n;i++)
			if(degree[i]==1&&coins[i]==0)
				q.push(i);

		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			for(int i=0;i<g[x].size();i++)
			{
				int y=g[x][i];
				if(--degree[y]==1&&coins[y]==0)
					q.push(y);
			}
		}

		vector<int> time(n,0);
		for(int i=0;i<n;i++)
			if(degree[i]==1&&coins[i])
				q.push(i);

		if(q.size()<=1) return 0;

		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			for(int i=0;i<g[x].size();i++)
			{
				int y=g[x][i];
				if(--degree[y]==1)
				{
					time[y]=time[x]+1;
					q.push(y);
				}
			}
		}

		int res=0;
		for(int i=0;i<edges.size();i++)
			if(time[edges[i][0]]>=2&&time[edges[i][1]]>=2)
				res+=2;

		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> c={1,0,0,0,0,1};
	vector<vector<int> > e={{0,1},{1,2},{2,3},{3,4},{4,5}};
	cout<<s.collectTheCoins(c,e)<<endl;
	c.clear();c={0,0,0,1,1,0,0,1};
	e.clear();e={{0,1},{0,2},{1,3},{1,4},{2,5},{5,6},{5,7}};
	cout<<s.collectTheCoins(c,e)<<endl;
	return 0;
}
