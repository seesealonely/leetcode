/*
   We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

   Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.



   Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4] and group2 [2,3].

Example 2:

Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false

Example 3:

Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false



Constraints:

1 <= n <= 2000
0 <= dislikes.length <= 104
dislikes[i].length == 2
1 <= dislikes[i][j] <= n
ai < bi
All the pairs of dislikes are unique.

*/

#include"head.h"
class Solution {
	public:
		bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
		vector< vector<bool> > graph(n,vector<bool>(n,false));
		vector<int> colors(n,0);
		for(int i=0;i<dislikes.size();i++)
		graph[dislikes[i][0]-1][dislikes[i][1]-1]=graph[dislikes[i][1]-1][dislikes[i][0]-1]=true;
		for(int i=0;i<n;i++)
		if(colors[i]==0&&!dfs(graph,colors,i,1))
			return false;
		return true;
		}
		bool dfs(vector<vector<bool> > &graph,vector<int> &colors,int index,int color)
		{
			if(colors[index])
				return colors[index]==color;
			colors[index]=color;
			for(int i=0;i<colors.size();i++)
			if(graph[index][i]&&!dfs(graph,colors,i,-color))
					return false;
			return true;
		}
};
