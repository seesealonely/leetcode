/*
   You are installing a billboard and want it to have the largest height. The billboard will have two steel supports, one on each side. Each steel support must be an equal height.

   You are given a collection of rods that can be welded together. For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.

   Return the largest possible height of your billboard installation. If you cannot support the billboard, return 0.



   Example 1:

Input: rods = [1,2,3,6]
Output: 6
Explanation: We have two disjoint subsets {1,2,3} and {6}, which have the same sum = 6.

Example 2:

Input: rods = [1,2,3,4,5,6]
Output: 10
Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which have the same sum = 10.

Example 3:

Input: rods = [1,2]
Output: 0
Explanation: The billboard cannot be supported, so we return 0.



Constraints:

1 <= rods.length <= 20
1 <= rods[i] <= 1000
sum(rods[i]) <= 5000

*/


#include"head.h"
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
	int n=rods.size(),sum=0;
	vector<vector<int>> dp(n+1,vector<int>(5010,INT_MIN));

	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		sum+=rods[i-1];
		for(int j=0;j<=sum;j++)
		{
			dp[i][j]=max(dp[i-1][j],dp[i][j]);
			int x=rods[i-1];
			if(j+x<=sum)
				dp[i][j+x]=max(dp[i][j+x],dp[i-1][j]);
			if(x<=j)
				dp[i][j-x]=max(dp[i][j-x],dp[i-1][j]+x);
			else
				dp[i][x-j]=max(dp[i][x-j],dp[i-1][j]+j);
		}
	}
	return dp[n][0];
    }
};

int main() 
{
	Solution s;
	vector<int> v={1,2,3,6};
	cout<<s.tallestBillboard(v)<<endl;
	v.clear();v={1,2,3,4,5,6};
	cout<<s.tallestBillboard(v)<<endl;
	v.clear();v={1,2};
	cout<<s.tallestBillboard(v)<<endl;
	return 0;
}
