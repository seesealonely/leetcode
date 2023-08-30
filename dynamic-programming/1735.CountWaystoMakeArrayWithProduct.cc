/*
   You are given a 2D integer array, queries. For each queries[i], where queries[i] = [ni, ki], find the number of different ways you can place positive integers into an array of size ni such that the product of the integers is ki. As the number of ways may be too large, the answer to the ith query is the number of ways modulo 109 + 7.

   Return an integer array answer where answer.length == queries.length, and answer[i] is the answer to the ith query.



   Example 1:

Input: queries = [[2,6],[5,1],[73,660]]
Output: [4,1,50734910]
Explanation: Each query is independent.
[2,6]: There are 4 ways to fill an array of size 2 that multiply to 6: [1,6], [2,3], [3,2], [6,1].
[5,1]: There is 1 way to fill an array of size 5 that multiply to 1: [1,1,1,1,1].
[73,660]: There are 1050734917 ways to fill an array of size 73 that multiply to 660. 1050734917 modulo 109 + 7 = 50734910.

Example 2:

Input: queries = [[1,1],[2,2],[3,3],[4,4],[5,5]]
Output: [1,2,3,10,5]



Constraints:

1 <= queries.length <= 104
1 <= ni, ki <= 104

*/


#include"head.h"
class Solution {
	public:
		typedef long long ll;
		const int mod=1e9+7;
		vector<int> waysToFillArray(vector<vector<int>>& queries) {
			vector<unordered_map<int,ll>> f(10001);
			f[0][1]=1;
			vector<ll> fac(10001);
			fac[0]=1;
			for(int i=1;i<=10000;i++)
				fac[i]=fac[i-1]*i%mod;

			int n=1,mx=1;
			for(int i=0;i<queries.size();i++)
			{
				n=max(n,queries[i][0]);
				mx=max(mx,queries[i][1]);
			}

			for(int i=1;i<=n;i++)
				for(unordered_map<int,ll>::iterator it=f[i-1].begin();it!=f[i-1].end();it++)
					for(int j=2;it->first*j<=mx;j++)
						f[i][it->first*j]=(f[i][it->first*j]+it->second)%mod;

			vector<int> res;
			for(int i=0;i<queries.size();i++)
			{
				ll cur=0,cnt=0;
				int q1=queries[i][1];
				for(int j=2;j*j<=q1;j++)
				while(q1%j==0)
				{
					q1/=j;
					cnt++;
				}
				if(q1>1) cnt++;
				for(int j=0;j<=queries[i][0]&&j<=cnt;j++)
				{
					cur=(cur+f[j][queries[i][1]]*fac[queries[i][0]]%mod*
					power(fac[j],mod-2)%mod*
					power(fac[queries[i][0]-j],mod-2)%mod)%mod;
				}
					res.push_back(cur);
			}
			return res;
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
	vector<vector<int>> queries = {{2,6},{5,1},{73,660}};
	show(s.waysToFillArray(queries));
	queries.clear();queries = {{1,1},{2,2},{3,3},{4,4},{5,5}};
	show(s.waysToFillArray(queries));
	return 0;
}
