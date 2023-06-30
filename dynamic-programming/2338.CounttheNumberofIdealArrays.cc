/*
   You are given two integers n and maxValue, which are used to describe an ideal array.

   A 0-indexed integer array arr of length n is considered ideal if the following conditions hold:

   Every arr[i] is a value from 1 to maxValue, for 0 <= i < n.
   Every arr[i] is divisible by arr[i - 1], for 0 < i < n.

   Return the number of distinct ideal arrays of length n. Since the answer may be very large, return it modulo 109 + 7.



   Example 1:

Input: n = 2, maxValue = 5
Output: 10
Explanation: The following are the possible ideal arrays:
- Arrays starting with the value 1 (5 arrays): [1,1], [1,2], [1,3], [1,4], [1,5]
- Arrays starting with the value 2 (2 arrays): [2,2], [2,4]
- Arrays starting with the value 3 (1 array): [3,3]
- Arrays starting with the value 4 (1 array): [4,4]
- Arrays starting with the value 5 (1 array): [5,5]
There are a total of 5 + 2 + 1 + 1 + 1 = 10 distinct ideal arrays.

Example 2:

Input: n = 5, maxValue = 3
Output: 11
Explanation: The following are the possible ideal arrays:
- Arrays starting with the value 1 (9 arrays):
- With no other distinct values (1 array): [1,1,1,1,1]
- With 2nd distinct value 2 (4 arrays): [1,1,1,1,2], [1,1,1,2,2], [1,1,2,2,2], [1,2,2,2,2]
- With 2nd distinct value 3 (4 arrays): [1,1,1,1,3], [1,1,1,3,3], [1,1,3,3,3], [1,3,3,3,3]
- Arrays starting with the value 2 (1 array): [2,2,2,2,2]
- Arrays starting with the value 3 (1 array): [3,3,3,3,3]
There are a total of 9 + 1 + 1 = 11 distinct ideal arrays.



Constraints:

2 <= n <= 104
1 <= maxValue <= 104

*/


const int N=10010;
const int mod=1e9+7;
#include"head.h"
class Solution {
	private: 
		typedef long long ll;
		int f[16],g[16][N];
	public:
		int idealArrays(int n, int maxValue) {
			memset(f,0,sizeof(f));
			f[1]=1;

			for(int i=2;i<=n;i++)
				for(int j=15;j>=1;j--)
					f[j]=(f[j]+f[j-1])%mod;

			memset(g,0,sizeof(g));
			for(int i=0;i<maxValue;i++)
				g[1][i]=1;

			int res=maxValue;
			for(int i=2;i<=14;i++)
				for(int j=1;j<=maxValue;j++)
				{
					for(int k=j+j;k<=maxValue;k+=j)
						g[i][k]=(g[i][k]+g[i-1][j])%mod;
					res=(res+(ll)f[i]*g[i][j])%mod;
				}
			return res;
		}
};


int main() 
{
	Solution s;
	cout<<s.idealArrays(2,5)<<endl;
	cout<<s.idealArrays(5,3)<<endl;
	return 0;
}
