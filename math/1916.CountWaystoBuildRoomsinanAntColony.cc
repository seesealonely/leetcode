/*
   You are an ant tasked with adding n new rooms numbered 0 to n-1 to your colony. You are given the expansion plan as a 0-indexed integer array of length n, prevRoom, where prevRoom[i] indicates that you must build room prevRoom[i] before building room i, and these two rooms must be connected directly. Room 0 is already built, so prevRoom[0] = -1. The expansion plan is given such that once all the rooms are built, every room will be reachable from room 0.

   You can only build one room at a time, and you can travel freely between rooms you have already built only if they are connected. You can choose to build any room as long as its previous room is already built.

   Return the number of different orders you can build all the rooms in. Since the answer may be large, return it modulo 109 + 7.



   Example 1:

Input: prevRoom = [-1,0,1]
Output: 1
Explanation: There is only one way to build the additional rooms: 0 → 1 → 2

Example 2:

Input: prevRoom = [-1,0,0,1,2]
Output: 6
Explanation:
The 6 ways are:
0 → 1 → 3 → 2 → 4
0 → 2 → 4 → 1 → 3
0 → 1 → 2 → 3 → 4
0 → 1 → 2 → 4 → 3
0 → 2 → 1 → 3 → 4
0 → 2 → 1 → 4 → 3



Constraints:

n == prevRoom.length
2 <= n <= 105
prevRoom[0] == -1
0 <= prevRoom[i] < n for all 1 <= i < n
Every room is reachable from room 0 once all the rooms are built.
*/


#include"head.h"
class Solution {
	public:
		typedef long long int ll;
		static const int mod=1e9+7;
		vector<vector<int>> g;
		vector<int> size;

		int waysToBuildRooms(vector<int>& prevRoom) {
			const int n=prevRoom.size();
			g.resize(n);

			for(int i=1;i<n;i++)
				g[prevRoom[i]].push_back(i);

			size.resize(n);
			getSize(0);

			ll res=1;
			for(int i=1;i<=n;i++)
				res=res*i%mod;

			for(int i=0;i<n;i++)
				res=res*power(size[i],mod-2)%mod;

			return res;
		}
		void getSize(int u)
		{
			size[u]=1;
			for(int i=0;i<g[u].size();i++)
			{
				int v=g[u][i];
				getSize(v);
				size[u]+=size[v];
			}
		}
		ll power(ll x,ll y)
		{
			ll tot=1,p=x;

			for(;y;y>>=1)
			{
				if(y&1)
					tot=tot*p%mod;
				p=p*p%mod;
			}
			return tot;
		}
};


int main() 
{
	Solution s;
	vector<int> prevRoom = {-1,0,1};
	cout<<s.waysToBuildRooms(prevRoom)<<endl;
	prevRoom.clear();prevRoom = {-1,0,0,1,2};
	cout<<s.waysToBuildRooms(prevRoom)<<endl;
	return 0;
}
