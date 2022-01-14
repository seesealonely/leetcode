/*
   You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

   Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.



   Example 1:

Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]

Example 2:

Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]



Constraints:

n == graph.length
1 <= n <= 12
0 <= graph[i].length < n
graph[i] does not contain i.
If graph[a] contains b, then graph[b] contains a.
The input graph is always connected.

*/
#include"head.h"
class Solution {
	public:
		int shortestPathLength(vector<vector<int>>& graph) {
			const int n=graph.size(),end=(1<<n)-1;
			queue<pair<int,int>> q;
			for(int i=0;i<n;i++)
				q.push({i,1<<i});
			int level=0;
			vector<vector<bool> > visit(n,vector<bool>(1<<n,false));
			while(!q.empty())
			{
				const int qs=q.size();
				for(int k=0;k<qs;k++)
				{
					int index=q.front().first;
					int state=q.front().second;
					q.pop();
					if(state==end) return level;
					if(visit[index][state]) continue;
					visit[index][state]=true;
					for(int i=0;i<graph[index].size();i++)
							q.push({graph[index][i],state|1<<graph[index][i]});
				}
				level++;
			}
			return -1;
		}
};
int main() 
{
	Solution s;
	vector<vector<int> > v={{1,2,3},{0},{0},{0}};
	cout<<s.shortestPathLength(v)<<endl;
	v.clear();v={{1},{0,2,4},{1,3,4},{2},{1,2}};
	cout<<s.shortestPathLength(v)<<endl;
	return 0;
}
