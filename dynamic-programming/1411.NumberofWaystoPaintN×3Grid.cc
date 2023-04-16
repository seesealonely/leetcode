/*
   You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).

   Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 109 + 7.



   Example 1:

Input: n = 1
Output: 12
Explanation: There are 12 possible way to paint the grid as shown.

Example 2:

Input: n = 5000
Output: 30228214



Constraints:

n == grid.length
1 <= n <= 5000

*/


#include"head.h"
class Solution {
	public:
		int numOfWays(int n) {
		const int mod=1e9+7;
		vector<bool> row(27);

		for(int i=0;i<27;i++)
			row[i]=check_row(i);

		vector<vector<bool>>  v(27,vector<bool>(27,false));
		for(int i=0;i<27;i++)
			if(row[i])
				for(int j=0;j<27;j++)
					if(row[j])
						v[i][j]=check_col(i,j);
		
		vector<vector<int>>  dp(n,vector<int>(27,0));
		for(int i=0;i<27;i++)
			dp[0][i]=row[i];

		for(int i=1;i<n;i++)
			for(int j=0;j<27;j++)
				if(row[j])
					for(int k=0;k<27;k++)
						if(row[k]&&v[j][k])
							dp[i][k]=(dp[i][k]+dp[i-1][j])%mod;
						
		int res=0;
		for(int i=0;i<27;i++)
			res=(res+dp[n-1][i])%mod;

		return res;

		}
		bool check_row(int x)
		{
			vector<int> row(3);
			for(int i=0;i<3;i++)
			{
				row[i]=x%3;
				x/=3;
			}
			for(int i=0;i<2;i++)
				if(row[i]==row[i+1])
					return false;
			return true;
		}
		bool check_col(int x,int y)
		{
			vector<int> r0(3),r1(3);
			for(int i=0;i<3;i++)
			{
				r0[i]=x%3;
				x/=3;
				r1[i]=y%3;
				y/=3;
			}

			for(int i=0;i<3;i++)
				if(r0[i]==r1[i])
					return false;
			return true;
		}
};


int main() 
{
	Solution s;
	cout<<s.numOfWays(1)<<endl;
	cout<<s.numOfWays(5000)<<endl;
	return 0;
}
