/*
   You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.

   Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

   In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.



   Example 1:

Input: n = 3
Output: 5
Explanation: The five different ways are show above.

Example 2:

Input: n = 1
Output: 1



Constraints:

1 <= n <= 1000

*/


#include"head.h"
class Solution {
    public:
        int numTilings(int n) {
        vector<int> dp(1001,0);
        dp[0]=dp[1]=1,dp[2]=2,dp[3]=5;
        
        if(n<=3) return dp[n];
        for(int i=4;i<=n;i++)
            dp[i]=((long long)2*dp[i-1]+dp[i-3])%(int)(1e9+7);

        return dp[n];
        }
};


int main() 
{
    Solution s;
    cout<<s.numTilings(3)<<endl;
    cout<<s.numTilings(1)<<endl;
    return 0;
}
