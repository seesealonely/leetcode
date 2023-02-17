/*
   You are given an array prices where prices[i] is the price of a given stock on the ith day.

   Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.



Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105

*/


#include"head.h"
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
        return cut(prices);
        }
        int cut(vector<int>& prices) {
        const int n=prices.size();
        vector<int> f(n,0),g(n,0);
        int mn=prices[0];
        for(int i=1;i<n;i++)
        {
            f[i]=max(f[i-1],prices[i]-mn);
            mn=min(prices[i],mn);
        }

        int mx=prices.back();
        for(int i=n-2;i>=0;i--)
        {
            g[i]=max(g[i+1],mx-prices[i]);
            mx=max(mx,prices[i]);
        }

        int res=0;
        for(int i=1;i<n;i++)
            res=max(res,f[i]+g[i]);
        return res;
        }
};


int main() 
{
    Solution s;
    vector<int> v={3,3,5,0,0,3,1,4};
    cout<<s.maxProfit(v)<<endl;
    v.clear();v={1,2,3,4,5};
    cout<<s.maxProfit(v)<<endl;
    v.clear();v={7,6,4,3,1};
    cout<<s.maxProfit(v)<<endl;
    return 0;
}
