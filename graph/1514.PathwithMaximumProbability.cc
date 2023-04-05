/*
   You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

   Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

   If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.



   Example 1:

Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.

Example 2:

Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000

Example 3:

Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.



Constraints:

2 <= n <= 10^4
0 <= start, end < n
start != end
0 <= a, b < n
a != b
0 <= succProb.length == edges.length <= 2*10^4
0 <= succProb[i] <= 1
There is at most one edge between every two nodes.

*/


#include"head.h"
class Solution {
	public:
		double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
		vector<vector<pair<int,double>>> g(n);

		for(int i=0;i<edges.size();i++)
		{
			int x=edges[i][0],y=edges[i][1];
			double l=succProb[i];
			g[x].push_back({y,l});
			g[y].push_back({x,l});
		}

		priority_queue<pair<double,int>> q;
		vector<double> dis(n,0);
		vector<bool> vis(n,false);

		dis[start]=1.0;
		q.push({1.0,start});
		while(!q.empty())
		{
			pair<double,int> cur=q.top();
			q.pop();

			if(cur.second==end)
				return dis[cur.second];

			if(vis[cur.second]) continue;
			vis[cur.second]=true;

			for(int i=0;i<g[cur.second].size();i++)
			{
				pair<int,double> p=g[cur.second][i];
				if(dis[p.first]<cur.first*p.second)
				{
					dis[p.first]=cur.first*p.second;
					q.push({dis[p.first],p.first});
				}
			}
		}
		return dis[end];
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> e={{0,1},{1,2},{0,2}};
	vector<double> su={0.5,0.5,0.2};
	cout<<s.maxProbability(3,e,su,0,2)<<endl;
	su.clear();su={0.5,0.5,0.3};
	cout<<s.maxProbability(3,e,su,0,2)<<endl;
	e.clear();e={{0,1}};
	su.clear();su={0.5};
	cout<<s.maxProbability(3,e,su,0,2)<<endl;
	return 0;
}
