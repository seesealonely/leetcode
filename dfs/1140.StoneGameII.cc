/*
   Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. The objective of the game is to end with the most stones.

   Alice and Bob take turns, with Alice starting first. Initially, M = 1.

   On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X).

   The game continues until all the stones have been taken.

   Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.



   Example 1:

Input: piles = [2,7,9,4,4]
Output: 10
Explanation: If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger.

Example 2:

Input: piles = [1,2,3,4,5,100]
Output: 104



Constraints:

1 <= piles.length <= 100
1 <= piles[i] <= 104

*/


#include"head.h"
class Solution {
    public:
        int stoneGameII(vector<int>& piles) {
        const int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        vector<int> postsum(n+1,0);

//        postsum[n]=piles.back();
        for(int i=n-1;i>=0;i--)
            postsum[i]=postsum[i+1]+piles[i];

        return dfs(0,1,n,postsum,dp);
        }
        int dfs(int s,int M,int n,vector<int> &sum,vector<vector<int>> &dp)
        {
            if(s>=n)
                return 0;

            if(s+2*M>=n)
                return sum[s];

            if(dp[s][M]) return dp[s][M];
            int res=0;
            for(int i=1;i<=2*M;i++)
                res=max(res,sum[s]-dfs(s+i,max(i,M),n,sum,dp));

            return dp[s][M]=res;
        }
};


int main() 
{
    Solution s;
    vector<int> v={2,7,9,4,4};
    cout<<s.stoneGameII(v)<<endl;
    v.clear();v={1,2,3,4,5,100};
    cout<<s.stoneGameII(v)<<endl;
    return 0;
}
