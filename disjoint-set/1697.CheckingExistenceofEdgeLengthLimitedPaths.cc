/*
   An undirected graph of n nodes is defined by edgeList, where edgeList[i] = [ui, vi, disi] denotes an edge between nodes ui and vi with distance disi. Note that there may be multiple edges between two nodes.

   Given an array queries, where queries[j] = [pj, qj, limitj], your task is to determine for each queries[j] whether there is a path between pj and qj such that each edge on the path has a distance strictly less than limitj .

   Return a boolean array answer, where answer.length == queries.length and the jth value of answer is true if there is a path for queries[j] is true, and false otherwise.



   Example 1:

Input: n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
Output: [false,true]
Explanation: The above figure shows the given graph. Note that there are two overlapping edges between 0 and 1 with distances 2 and 16.
For the first query, between 0 and 1 there is no path where each distance is less than 2, thus we return false for this query.
For the second query, there is a path (0 -> 1 -> 2) of two edges with distances less than 5, thus we return true for this query.

Example 2:

Input: n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
Output: [true,false]
Exaplanation: The above figure shows the given graph.



Constraints:

2 <= n <= 105
1 <= edgeList.length, queries.length <= 105
edgeList[i].length == 3
queries[j].length == 3
0 <= ui, vi, pj, qj <= n - 1
ui != vi
pj != qj
1 <= disi, limitj <= 109
There may be multiple edges between two nodes.

*/


#include"head.h"
class Solution {
	public:
		class uf
		{
			public:
				vector<int> p,size;
				uf(int n)
				{
					p.resize(n);
					size.resize(n);
					for(int i=0;i<n;i++)
						p[i]=i,size[i]=1;
				}
				void merge(int x,int y)
				{
					int px=find(x),py=find(y);
					if(px==py) return;

					if(size[px]<size[py])
					{
						p[px]=py;
						size[py]+=size[px];
					}
					else
					{
						p[py]=px;
						size[px]+=size[py];
					}
				}
				int find(int x)
				{
					return p[x]=(x==p[x]?p[x]:find(p[x]));
				}
		};
		vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
			const int q=queries.size();
			for(int i=0;i<q;i++)
				queries[i].push_back(i);

			sort(edgeList.begin(),edgeList.end(),cmp);
			sort(queries.begin(),queries.end(),cmp);

			uf u(n);
			vector<bool> res(q);
			for(int i=0,j=0;i<q;i++)
			{
				while(j<edgeList.size()&&edgeList[j][2]<queries[i][2])
				{
					u.merge(edgeList[j][0],edgeList[j][1]);
					j++;
				}
				res[queries[i][3]]=u.find(queries[i][0])==u.find(queries[i][1]);
			}
			return res;
		}
		static bool cmp(vector<int> &x,vector<int> &y)
		{
			return x[2]<y[2];
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> e={{0,1,2},{1,2,4},{2,0,8},{1,0,16}},q={{0,1,2},{0,2,5}};
	show(s.distanceLimitedPathsExist(3,e,q));
	e.clear();e={{0,1,10},{1,2,5},{2,3,9},{3,4,13}};
	q.clear();q={{0,4,14},{1,4,13}};
	show(s.distanceLimitedPathsExist(5,e,q));
	return 0;
}
