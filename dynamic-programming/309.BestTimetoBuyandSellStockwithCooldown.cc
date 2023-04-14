/*
   You are given an array prices where prices[i] is the price of a given stock on the ith day.

   Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

   After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:

Input: prices = [1]
Output: 0



Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000

*/


#include"head.h"
class Solution {
	public:
		int maxProfit(vector<int>& prices) {
		const int n=prices.size();
		vector<vector<int>> dp(n,vector<int>(3,0));

		dp[0][0]=0;
		dp[0][1]=-prices[0];
		dp[0][2]=0;

		for(int i=1;i<n;i++)
		{
			dp[i][0]=max(dp[i-1][0],dp[i-1][2]);
			dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
			dp[i][2]=dp[i-1][1]+prices[i];
		}

		return max(dp.back()[0],dp.back()[2]);
		}
};


int main() 
{
	Solution s;
	vector<int> v={1,2,3,0,2};
      	cout<<s.maxProfit(v)<<endl;
	v.clear();v={1};
      	cout<<s.maxProfit(v)<<endl;
	return 0;
}
