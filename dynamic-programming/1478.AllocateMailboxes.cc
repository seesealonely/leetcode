/*
   Given the array houses where houses[i] is the location of the ith house along a street and an integer k, allocate k mailboxes in the street.

   Return the minimum total distance between each house and its nearest mailbox.

   The test cases are generated so that the answer fits in a 32-bit integer.



   Example 1:

Input: houses = [1,4,8,10,20], k = 3
Output: 5
Explanation: Allocate mailboxes in position 3, 9 and 20.
Minimum total distance from each houses to nearest mailboxes is |3-1| + |4-3| + |9-8| + |10-9| + |20-20| = 5

Example 2:

Input: houses = [2,3,5,12,18], k = 2
Output: 9
Explanation: Allocate mailboxes in position 3 and 14.
Minimum total distance from each houses to nearest mailboxes is |2-3| + |3-3| + |5-3| + |12-14| + |18-14| = 9.



Constraints:

1 <= k <= houses.length <= 100
1 <= houses[i] <= 104
All the integers of houses are unique.

*/


#include"head.h"
class Solution {
    public:
        int minDistance(vector<int>& houses, int k) {
        const int MAX=1e9,n=houses.size();

        sort(houses.begin(),houses.end());

        vector<vector<int>> cost(n+1,vector<int>(n+1,0));

        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                cost[i][j]=calc(houses,i-1,j-1);

        vector<vector<int>> dp(n+1,vector<int>(k+1,MAX));

        dp[0][0]=0;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=k;j++)
                for(int m=i;m>=1;m--)
                    dp[i][j]=min(dp[i][j],dp[m-1][j-1]+cost[m][i]);

        return dp[n][k];
        }
        int calc(const vector<int> &houses,int l,int r)
        {
            int res=0;
            for(;l<r;l++,r--)
                res+=houses[r]-houses[l];
            return res;
        }
};


int main() 
{
    Solution s;
    vector<int> v={1,4,8,10,20};
    cout<<s.minDistance(v,3)<<endl;
    v.clear();v={2,3,5,12,18};
    cout<<s.minDistance(v,2)<<endl;
    return 0;
}
