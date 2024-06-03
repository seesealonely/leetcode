/*
   Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.

   Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.

   Note that you can return the indices of the edges in any order.



   Example 1:

Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
Output: [[0,1],[2,3,4,5]]
Explanation: The figure above describes the graph.
The following figure shows all the possible MSTs:

Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.

Example 2:

Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
Output: [[],[0,1,2,3]]
Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.



Constraints:

2 <= n <= 100
1 <= edges.length <= min(200, n * (n - 1) / 2)
edges[i].length == 3
0 <= ai < bi < n
1 <= weighti <= 1000
All pairs (ai, bi) are distinct.

*/


#include"head.h"
class Solution {
	public:
		vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
			const int m=edges.size();
			for(int i=0;i<m;i++)
			{
				swap(edges[i][0],edges[i][2]);
				edges[i].push_back(i);
			}

			sort(edges.begin(),edges.end());

			int min_cost=dfs1(n,edges,-1);
			vector<vector<int>> res(2);
			for(int i=0;i<m;i++)
				if(dfs1(n,edges,i)>min_cost) res[0].push_back(i);
				else if(dfs2(n,edges,i)==min_cost) res[1].push_back(i);

			return res;
		}
	private:
		int p[105];
		int find(int x)
		{
			return p[x]=p[x]!=x?find(p[x]):x;
		}

		int dfs1(int n,const vector<vector<int>> &edges,int k)
		{
			for(int i=0;i<n;i++)
				p[i]=i;
			int cost=0,cnt=0;
			for(int i=0;i<edges.size();i++)
			{
				if(edges[i].back()==k) continue;
				int p1=find(edges[i][1]),p2=find(edges[i][2]);
				if(p1!=p2)
				{
					cost+=edges[i][0];
					cnt++;
					if(cnt==n-1)
						break;
					p[p1]=p2;
				}
			}
			return cnt==n-1?cost:INT_MAX;
		}

		int dfs2(int n,const vector<vector<int>> &edges,int k)
		{
			for(int i=0;i<n;i++)
				p[i]=i;
			int cost=0,cnt=0;
			for(int i=0;i<edges.size();i++)
				if(edges[i][3]==k)
				{
					cost+=edges[i][0];
					cnt++;
					p[edges[i][1]]=edges[i][2];
					break;
				}

			for(int i=0;i<edges.size();i++)
			{
				int p1=find(edges[i][1]),p2=find(edges[i][2]);
				if(p1!=p2)
				{
					cost+=edges[i][0];
					cnt++;
					if(cnt==n-1)
						break;
					p[p1]=p2;
				}
			}
			return cnt==n-1?cost:INT_MAX;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>>  edges = {{0,1,1},{1,2,1},{2,3,2},{0,3,2},{0,4,3},{3,4,3},{1,4,6}};
	show(s.findCriticalAndPseudoCriticalEdges(5,edges));
	edges.clear();
	edges= {{0,1,1},{1,2,1},{2,3,1},{0,3,1}};
	show(s.findCriticalAndPseudoCriticalEdges(4,edges));
	return 0;
}
