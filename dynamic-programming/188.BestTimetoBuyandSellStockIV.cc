/*
   You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

   Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.



Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000

*/


#include"head.h"
class Solution {
    public:
        int maxProfit(int k, vector<int>& prices) {
            const int n=prices.size();

            vector<vector<int>> dp(k+1,vector<int>(n,0));

            for(int i=1;i<=k;i++)
            {
                int mx=dp[i-1][0]-prices[0];
                for(int j=1;j<n;j++)
                {
                    //                dp[i][j]=max(dp[i][j-1],dp[i-1][m]+prices[j]-prices[m]);
                    dp[i][j]=max(dp[i][j-1],mx+prices[j]);
                    mx=max(mx,dp[i-1][j]-prices[j]);
                }
            }
            return dp[k][n-1];

        }
};


int main() 
{
    Solution s;
    vector<int> v={2,4,1};
    cout<<s.maxProfit(2,v)<<endl;
    v.clear();v={3,2,6,5,0,3};
    cout<<s.maxProfit(2,v)<<endl;
    return 0;
}
