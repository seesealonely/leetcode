/*
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

 

Example 1:

Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6

Example 2:

Input: n = 2, roads = [[1,0,10]]
Output: 1
Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.

 

Constraints:

    1 <= n <= 200
    n - 1 <= roads.length <= n * (n - 1) / 2
    roads[i].length == 3
    0 <= ui, vi <= n - 1
    1 <= timei <= 109
    ui != vi
    There is at most one road connecting any two intersections.
    You can reach any intersection from any other intersection.

*/


#include"head.h"
class Solution {
	public:
		int countPaths(int n, vector<vector<int>>& roads) {
		typedef long long ll;
		const int mod=1e9+7;
		vector<vector<pair<int,int>>> g(n);

		for(int i=0;i<roads.size();i++)
		{
			int x=roads[i][0],y=roads[i][1],z=roads[i][2];
			g[x].push_back({y,z});
			g[y].push_back({x,z});
		}

		vector<ll> d(n,INT64_MAX);
		vector<int> w(n,0);
		vector<bool> vis(n,false);
			
		d[0]=0;w[0]=1;
		for(int i=0;i<n;i++)
		{
			ll m=INT64_MAX;
			int mx=-1;
			for(int j=0;j<n;j++)
			{
				if(vis[j]) continue;

				if(m>d[j])
				{
					m=d[j];
					mx=j;
				}
			}

			vis[mx]=true;
			for(int i=0;i<g[mx].size();i++)
			{
				pair<int,int> p=g[mx][i];
				if(d[p.first]>d[mx]+p.second)
				{
					d[p.first]=d[mx]+p.second;
					w[p.first]=w[mx];
				}
				else if(d[p.first]==d[mx]+p.second)
					w[p.first]=(w[p.first]+w[mx])%mod;
			}
		}
		return w[n-1];
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> r={
    {0,6,7},
    {0,1,2},
    {1,2,3},
    {1,3,3},
    {6,3,3},
    {3,5,1},
    {6,5,1},
    {2,5,1},
    {0,4,5},
    {4,6,2}
};
	cout<<s.countPaths(7,r)<<endl;
	r.clear();r={{1,0,10}};
	cout<<s.countPaths(2,r)<<endl;
	return 0;
}
