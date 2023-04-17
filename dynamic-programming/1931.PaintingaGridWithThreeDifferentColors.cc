/*
   You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.

   Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.



   Example 1:

Input: m = 1, n = 1
Output: 3
Explanation: The three possible colorings are shown in the image above.

Example 2:

Input: m = 1, n = 2
Output: 6
Explanation: The six possible colorings are shown in the image above.

Example 3:

Input: m = 5, n = 5
Output: 580986



Constraints:

1 <= m <= 5
1 <= n <= 1000

*/


#include"head.h"
class Solution {
	public:
		int colorTheGrid(int m, int n) {
		const int mod=1e9+7;
		int pow=1;
		for(int i=0;i<m;i++)
			pow*=3;

		vector<int> num;
		for(int i=0;i<pow;i++)
			if(getCol(i,m))
				num.push_back(i);

		const int len=num.size();
		vector<vector<int>> v(len);
		for(int i=0;i<len;i++)
			for(int j=i+1;j<len;j++)
				if(check(num[i],num[j],m))
				{
					v[j].push_back(i);
					v[i].push_back(j);
				}

		vector<vector<int>> dp(n,vector<int>(len,0));
		for(int i=0;i<len;i++)
			dp[0][i]=1;

		for(int i=1;i<n;i++)
			for(int x=0;x<len;x++)
				for(int y=0;y<v[x].size();y++)
				{
					int c=v[x][y];
					dp[i][c]=(dp[i][c]+dp[i-1][x])%mod;
				}

		int res=0;
		for(int i=0;i<len;i++)
			res=(res+dp[n-1][i])%mod;
		return res;
		}

		bool getCol(int s,int c)
		{
			int pre=INT_MIN;
			for(int i=0;i<c;i++)
			{
				if(pre==s%3)
					return false;
				pre=s%3;
				s/=3;
			}
			return true;
		}
		bool check(int s1,int s2,int c)
		{
			for(int i=0;i<c;i++)
			{
				if(s1%3==s2%3)
					return false;
				s1/=3;
				s2/=3;
			}
			return true;
		}
};


int main() 
{
	Solution s;
	cout<<s.colorTheGrid(1,1)<<endl;
	cout<<s.colorTheGrid(1,2)<<endl;
	cout<<s.colorTheGrid(5,5)<<endl;
	return 0;
}
