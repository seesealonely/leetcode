/*
   There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

   You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.

   A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

   Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.



   Example 1:

Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
Output: 3
Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).

Example 2:

Input: colors = "a", edges = [[0,0]]
Output: -1
Explanation: There is a cycle from 0 to 0.



Constraints:

n == colors.length
m == edges.length
1 <= n <= 105
0 <= m <= 105
colors consists of lowercase English letters.
0 <= aj, bj < n
*/


#include"head.h"
class Solution {
	public:
		int largestPathValue(string colors, vector<vector<int>>& edges) {
		const int n=colors.size();
		vector<vector<int>> g(n);
		vector<int> indegree(n,0);
		for(int i=0;i<edges.size();i++)
		{
			int x=edges[i][0],y=edges[i][1];
			g[x].push_back(y);
			indegree[y]++;
		}

		queue<int> q;
		vector<vector<int>> hash(n,vector<int>(26,0));
		for(int i=0;i<n;i++)
			if(indegree[i]==0)
			{
				q.push(i);
				hash[i][colors[i]-'a']++;
			}

		int cnt=0,res=1;
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			cnt++;

			for(int i=0;i<g[u].size();i++)
			{
				int v=g[u][i];
				if(--indegree[v]==0)
					q.push(v);
				for(int j=0;j<26;j++)
				{
					hash[v][j]=max(hash[v][j],hash[u][j]+(colors[v]-'a'==j));
					res=max(res,hash[v][j]);
				}
			}
		}

		if(cnt<n)
			return -1;

		return res;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> e={{0,1},{0,2},{2,3},{3,4}};
	cout<<s.largestPathValue("abaca",e)<<endl;
	e.clear();e={{0,0}};
	cout<<s.largestPathValue("a",e)<<endl;
	return 0;
}
