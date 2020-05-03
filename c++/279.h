#include<iostream>
#include<algorithm>
#include<limits.h>
#include<vector>
using namespace std;

class Solution {
	public:
		int numSquares(int n) {
			if(n<=0) return 0;
			vector<int> dp(n+1,INT_MAX); 
			dp[0]=0;
			int m=INT_MAX;
			for(int i=1;i<n+1;++i)
			{
				m=INT_MAX;
				for(int j=1;j*j<=i;j++)
					m=min(m,dp[i-j*j]+1);	
				dp[i]=m;
			cout<<m<<" ";
			}
			cout<<endl;
			return dp[n];
		}
};
