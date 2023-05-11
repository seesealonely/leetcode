/*
   There are n cities numbered from 1 to n. You are given an array edges of size n-1, where edges[i] = [ui, vi] represents a bidirectional edge between cities ui and vi. There exists a unique path between each pair of cities. In other words, the cities form a tree.

   A subtree is a subset of cities where every city is reachable from every other city in the subset, where the path between each pair passes through only the cities from the subset. Two subtrees are different if there is a city in one subtree that is not present in the other.

   For each d from 1 to n-1, find the number of subtrees in which the maximum distance between any two cities in the subtree is equal to d.

   Return an array of size n-1 where the dth element (1-indexed) is the number of subtrees in which the maximum distance between any two cities is equal to d.

   Notice that the distance between the two cities is the number of edges in the path between them.



   Example 1:

Input: n = 4, edges = [[1,2],[2,3],[2,4]]
Output: [3,4,0]
Explanation:
The subtrees with subsets {1,2}, {2,3} and {2,4} have a max distance of 1.
The subtrees with subsets {1,2,3}, {1,2,4}, {2,3,4} and {1,2,3,4} have a max distance of 2.
No subtree has two nodes where the max distance between them is 3.

Example 2:

Input: n = 2, edges = [[1,2]]
Output: [1]

Example 3:

Input: n = 3, edges = [[1,2],[2,3]]
Output: [2,1]



Constraints:

2 <= n <= 15
edges.length == n-1
edges[i].length == 2
1 <= ui, vi <= n
All pairs (ui, vi) are distinct.
*/


#include"head.h"
class Solution {
	public:
		vector<int> dis;
		vector<vector<int>> g;
		int maxDis;
		vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
		vector<int> res(n-1,0);
		g.resize(n);
		dis.resize(n);

		for(int mask=1;mask<(1<<(n-1));mask++)
		{
			int cntEdges=0,cntVertices=0;
			for(int i=0;i<n;i++)
				g[i].clear();

			for(int i=0;i<n-1;i++)
				if(mask&(1<<i))
				{
					int u=edges[i][0]-1,v=edges[i][1]-1;
					g[u].push_back(v);
					g[v].push_back(u);
					cntEdges++;
				}
			int startVertice=-1;
			for(int i=0;i<n;i++)
				if(g[i].size()>0)
				{
					cntVertices++;
					dis[i]=0;
					startVertice=i;
				}

			if(cntEdges!=cntVertices-1)
				continue;

			maxDis=0;
			dfs(startVertice,-1);
			res[maxDis-1]++;
		}

		return res;
		}
		void dfs(int u,int pa)
		{
			int m1=0,m2=0;
			for(int i=0;i<g[u].size();i++)
			{
				int v=g[u][i];
				if(v==pa) continue;

				dfs(v,u);
				dis[u]=max(dis[u],dis[v]+1);

				if(m1<dis[v]+1)
					m2=m1,m1=dis[v]+1;
				else if(m2<dis[v]+1)
					m2=dis[v]+1;
			}
			maxDis=max(maxDis,m1+m2);
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> edges = {{1,2},{2,3},{2,4}};
	show(s.countSubgraphsForEachDiameter(4,edges));
	edges.clear();edges={{1,2}};
	show(s.countSubgraphsForEachDiameter(2,edges));
	edges.push_back({2,3});
	show(s.countSubgraphsForEachDiameter(3,edges));
	return 0;
}
