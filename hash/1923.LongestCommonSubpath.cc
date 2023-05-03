/*
   There is a country of n cities numbered from 0 to n - 1. In this country, there is a road connecting every pair of cities.

   There are m friends numbered from 0 to m - 1 who are traveling through the country. Each one of them will take a path consisting of some cities. Each path is represented by an integer array that contains the visited cities in order. The path may contain a city more than once, but the same city will not be listed consecutively.

   Given an integer n and a 2D integer array paths where paths[i] is an integer array representing the path of the ith friend, return the length of the longest common subpath that is shared by every friend's path, or 0 if there is no common subpath at all.

   A subpath of a path is a contiguous sequence of cities within that path.



   Example 1:

Input: n = 5, paths = [[0,1,2,3,4],
[2,3,4],
[4,0,1,2,3]]
Output: 2
Explanation: The longest common subpath is [2,3].

Example 2:

Input: n = 3, paths = [[0],[1],[2]]
Output: 0
Explanation: There is no common subpath shared by the three paths.

Example 3:

Input: n = 5, paths = [[0,1,2,3,4],
[4,3,2,1,0]]
Output: 1
Explanation: The possible longest common subpaths are [0], [1], [2], [3], and [4]. All have a length of 1.



Constraints:

1 <= n <= 105
m == paths.length
2 <= m <= 105
sum(paths[i].length) <= 105
0 <= paths[i][j] < n
The same city is not listed multiple times consecutively in paths[i].

*/

#define c11
#include"head.h"
const int b[]={2,101,131};
class Solution {
	public:
		typedef unsigned long long int ull;
		vector<vector<ull>> p;
		int m;
		vector<vector<int>> paths;

		bool check(int mid)
		{
			if(mid==0)
				return true;
			unordered_map<ull,int> cnt;

			for(int i=0;i<paths.size();i++)
			{
				int n=paths[i].size();
				ull h[3]={0};

				for(int j=0;j<mid-1;j++)
					for(int k=0;k<3;k++)
						h[k]=h[k]*b[k]+paths[i][j];

				unordered_set<ull> set;
				for(int j=mid-1;j<n;j++)
				{
					for(int k=0;k<3;k++)
						h[k]=h[k]*b[k]+paths[i][j];
					set.insert(h[0]*h[1]*h[2]);

					for(int k=0;k<3;k++)
						h[k]=h[k]-(ull)paths[i][j-mid+1]*p[k][mid-1];
				}
				for(unordered_set<ull>::iterator it=set.begin();it!=set.end();it++)
					cnt[*it]++;
			}

			for(unordered_map<ull,int>::iterator it=cnt.begin();it!=cnt.end();it++)
				if(it->second==m)
					return true;

			return false;
		}

		int longestCommonSubpath(int n, vector<vector<int>>& paths) {
			this->paths=paths;
			int l=0,r=paths[0].size(),N=0;
			m=paths.size();

			for(int i=0;i<paths.size();i++)
			{
				r=min(r,(int)paths[i].size());
				N=max(N,(int)paths[i].size());
			}

			p.resize(3,vector<ull>(N+1,0));
			for(int k=0;k<3;k++)
			{
				p[k][0]=1;
				for(int j=1;j<=N;j++)
					p[k][j]=p[k][j-1]*b[k];
			}

			while(l<r)
			{
				int mid=l+r+1>>1;
				if(check(mid)) l=mid;
				else r=mid-1;
			}

			return l;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> v={{0,1,2,3,4},
		{2,3,4},
		{4,0,1,2,3}};
	cout<<s.longestCommonSubpath(5,v)<<endl;
	v.clear();v={{0},{1},{2}};
	cout<<s.longestCommonSubpath(3,v)<<endl;
	v.clear();v={{0,1,2,3,4},
		{4,3,2,1,0}};
	cout<<s.longestCommonSubpath(5,v)<<endl;
	return 0;
}
