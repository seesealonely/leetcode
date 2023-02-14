/*
   There is a row of m houses in a small city, each house must be painted with one of the n colors (labeled from 1 to n), some houses that have been painted last summer should not be painted again.

   A neighborhood is a maximal group of continuous houses that are painted with the same color.

   For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods [{1}, {2,2}, {3,3}, {2}, {1,1}].

   Given an array houses, an m x n matrix cost and an integer target where:

   houses[i]: is the color of the house i, and 0 if the house is not painted yet.
   cost[i][j]: is the cost of paint the house i with the color j + 1.

   Return the minimum cost of painting all the remaining houses in such a way that there are exactly target neighborhoods. If it is not possible, return -1.



   Example 1:

Input: houses = [0,0,0,0,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
Output: 9
Explanation: Paint houses of this way [1,2,2,1,1]
This array contains target = 3 neighborhoods, [{1}, {2,2}, {1,1}].
Cost of paint all houses (1 + 1 + 1 + 1 + 5) = 9.

Example 2:

Input: houses = [0,2,1,2,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
Output: 11
Explanation: Some houses are already painted, Paint the houses of this way [2,2,1,2,2]
This array contains target = 3 neighborhoods, [{2,2}, {1}, {2,2}].
Cost of paint the first and last house (10 + 1) = 11.

Example 3:

Input: houses = [3,1,2,3], cost = [[1,1,1],[1,1,1],[1,1,1],[1,1,1]], m = 4, n = 3, target = 3
Output: -1
Explanation: Houses are already painted with a total of 4 neighborhoods [{3},{1},{2},{3}] different of target = 3.



Constraints:

m == houses.length == cost.length
n == cost[i].length
1 <= m <= 100
1 <= n <= 20
1 <= target <= m
0 <= houses[i] <= n
1 <= cost[i][j] <= 104

*/


#include"head.h"
class Solution {
    public:
        int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
#define mx 1e9+7
            vector<vector<vector<int>>> dp(m,vector<vector<int>>(target+1,vector<int>(n+1,mx)));

            if(houses[0]) dp[0][1][houses[0]]=0;
            else
                for(int i=1;i<=n;i++)
                    dp[0][1][i]=cost[0][i-1];

            for(int i=1;i<m;i++)
                for(int j=1;j<=target;j++)
                {
                    if(houses[i])
                    {
                        int v=houses[i];
                        for(int u=1;u<=n;u++)
                        {
                            if(u==v)
                                dp[i][j][v]=min(dp[i][j][v],dp[i-1][j][u]);
                            else
                                dp[i][j][v]=min(dp[i][j][v],dp[i-1][j-1][u]);
                        }
                    }
                    else
                    {
                        for(int v=1;v<=n;v++)
                            for(int u=1;u<=n;u++)
                            {
                                if(v==u)
                                    dp[i][j][v]=min(dp[i][j][v],dp[i-1][j][u]+cost[i][v-1]);
                                else
                                    dp[i][j][v]=min(dp[i][j][v],dp[i-1][j-1][u]+cost[i][v-1]);
                            }
                    }
                }

            int res=*min_element(dp[m-1][target].begin(),dp[m-1][target].end());

            return res==mx?-1:res;
        }
};


int main() 
{
    Solution s;
    vector<int> h={0,0,0,0,0};
    vector<vector<int>> c={{1,10},{10,1},{10,1},{1,10},{5,1}};
    cout<<s.minCost(h,c,5,2,3)<<endl;
    h.clear();h={0,2,1,2,0};
    cout<<s.minCost(h,c,5,2,3)<<endl;
    h.clear();h={0,0,0,0,0};
    c.clear();c={{1,10},{10,1},{1,10},{10,1},{1,10}};
    cout<<s.minCost(h,c,5,2,5)<<endl;
    return 0;
}
