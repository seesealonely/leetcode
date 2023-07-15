/*
   In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

   The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), with one additional directed edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.

   The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, where ui is a parent of child vi.

   Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.



   Example 1:

Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]

Example 2:

Input: edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
Output: [4,1]



Constraints:

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ui, vi <= n
ui != vi

*/


#include"head.h"
class Solution {
	public:
		vector<int> p,father;
		int find(int x)
		{
			return x==p[x]?p[x]:find(p[x]);
		}
		vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		const int n=edges.size();
		for(int i=0;i<=n;i++)
		{
			p.push_back(i);
			father.push_back(0);
		}
		
		vector<int> res;
		for(int i=0;i<n;i++)
		{
			int x=edges[i][0],y=edges[i][1];
			int px=find(x),py=find(y);
			if(father[y])
			{
				if(res.empty()) res={x,y,father[y],y};
				else return {father[y],y};
			}
			else if(px==py)
			{
				if(res.empty()) res={x,y};
				else return {res[2],res[3]};
			}
			else
			{
				father[y]=x;
				p[y]=x;
			}
		}
		return {res[0],res[1]};
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
	show(s.findRedundantDirectedConnection(edges));
	edges.clear();edges = {{1,2},{2,3},{3,4},{4,1},{1,5}};
	show(s.findRedundantDirectedConnection(edges));
	return 0;
}
