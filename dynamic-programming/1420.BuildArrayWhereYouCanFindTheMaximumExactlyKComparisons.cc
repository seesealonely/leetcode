/*
   You are given three integers n, m and k. Consider the following algorithm to find the maximum element of an array of positive integers:

   You should build the array arr which has the following properties:

   arr has exactly n integers.
   1 <= arr[i] <= m where (0 <= i < n).
   After applying the mentioned algorithm to arr, the value search_cost is equal to k.

   Return the number of ways to build the array arr under the mentioned conditions. As the answer may grow large, the answer must be computed modulo 109 + 7.



   Example 1:

Input: n = 2, m = 3, k = 1
Output: 6
Explanation: The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]

Example 2:

Input: n = 5, m = 2, k = 3
Output: 0
Explanation: There are no possible arrays that satisify the mentioned conditions.

Example 3:

Input: n = 9, m = 1, k = 1
Output: 1
Explanation: The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]



Constraints:

1 <= n <= 50
1 <= m <= 100
0 <= k <= n

*/


#include"head.h"
class Solution {
	public:
		int numOfArrays(int n, int m, int k) {
		typedef long long ll;
		const int mod=1e9+7;
		vector<vector<vector<ll>>> f(n+1,vector<vector<ll>>(k+1,vector<ll>(m+1,0)));;
		vector<vector<vector<ll>>> g(n+1,vector<vector<ll>>(k+1,vector<ll>(m+1,0)));;

		for(int i=1;i<=m;i++)
		{
			f[1][1][i]=1;
			g[1][1][i]=i;
		}

		for(int i=2;i<=n;i++)
			for(int c=1;c<=k;c++)
				for(int j=1;j<=m;j++)
				{
					f[i][c][j]=(f[i-1][c][j]*j+g[i-1][c-1][j-1])%mod;
					g[i][c][j]=(g[i][c][j-1]+f[i][c][j])%mod;
				}

		return g[n][k][m];
		}
};


int main() 
{
	Solution s;
	cout<<s.numOfArrays(2,3,1)<<endl;
	cout<<s.numOfArrays(5,2,3)<<endl;
	cout<<s.numOfArrays(9,1,1)<<endl;
	return 0;
}
