/*
   There is a street with n * 2 plots, where there are n plots on each side of the street. The plots on each side are numbered from 1 to n. On each plot, a house can be placed.

   Return the number of ways houses can be placed such that no two houses are adjacent to each other on the same side of the street. Since the answer may be very large, return it modulo 109 + 7.

   Note that if a house is placed on the ith plot on one side of the street, a house can also be placed on the ith plot on the other side of the street.



   Example 1:

Input: n = 1
Output: 4
Explanation: 
Possible arrangements:
1. All plots are empty.
2. A house is placed on one side of the street.
3. A house is placed on the other side of the street.
4. Two houses are placed, one on each side of the street.

Example 2:

Input: n = 2
Output: 9
Explanation: The 9 possible arrangements are shown in the diagram above.



Constraints:

1 <= n <= 104

*/


#include"head.h"
class Solution {
    public:
        int countHousePlacements(int n) {
        vector<int> dp(n+1,0);
        const int mod=1e9+7;
        dp[0]=1,dp[1]=2;
        if(n==1) return dp[1]*dp[1];
        dp[2]=3;
        if(n==2) return dp[2]*dp[2];

        for(int i=3;i<=n;i++)
            dp[i]=((long)dp[i-1]+dp[i-2])%mod;

        return (long)dp[n]*dp[n]%mod;
        }
};


int main() 
{
    Solution s;
    cout<<s.countHousePlacements(1)<<endl;
    cout<<s.countHousePlacements(2)<<endl;
    cout<<s.countHousePlacements(5)<<endl;
    return 0;
}
