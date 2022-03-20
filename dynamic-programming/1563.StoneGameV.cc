/*
   There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

   In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.

   The game ends when there is only one stone remaining. Alice's is initially zero.

   Return the maximum score that Alice can obtain.



   Example 1:

Input: stoneValue = [6,2,3,4,5,5]
Output: 18
Explanation: In the first round, Alice divides the row to [6,2,3], [4,5,5]. The left row has the value 11 and the right row has value 14. Bob throws away the right row and Alice's score is now 11.
In the second round Alice divides the row to [6], [2,3]. This time Bob throws away the left row and Alice's score becomes 16 (11 + 5).
The last round Alice has only one choice to divide the row which is [2], [3]. Bob throws away the right row and Alice's score is now 18 (16 + 2). The game ends because only one stone is remaining in the row.

Example 2:

Input: stoneValue = [7,7,7,7,7,7,7]
Output: 28

Example 3:

Input: stoneValue = [4]
Output: 0



Constraints:

1 <= stoneValue.length <= 500
1 <= stoneValue[i] <= 106

*/


#include"head.h"
class Solution {
    public:
        int stoneGameV(vector<int>& stoneValue) {
            const int n=stoneValue.size();
            vector<vector<int>> dp(n,vector<int>(n,0));
            vector<int> presum(n+1,0);
            for(int i=1;i<=n;i++)
                presum[i]=presum[i-1]+stoneValue[i-1];
            return dfs(presum,dp,0,n-1);
        }
        int dfs(vector<int>&pre,vector<vector<int>>&dp,int l,int r)
        {
            if(l==r)
                return 0;
            if(dp[l][r])
                return dp[l][r];

            for(int i=l;i<r;i++)
            {
                int lsum=pre[i+1]-pre[l],rsum=pre[r+1]-pre[i+1];
                if(lsum>rsum)
                    dp[l][r]=max(dp[l][r],rsum+dfs(pre,dp,i+1,r));
                else if(lsum<rsum)
                    dp[l][r]=max(dp[l][r],lsum+dfs(pre,dp,l,i));
                else
                    dp[l][r]=max(dp[l][r],max(lsum+dfs(pre,dp,l,i),rsum+dfs(pre,dp,i+1,r)));
            }

            return dp[l][r];
        }
};


int main() 
{
    Solution s;
    vector<int> v={6,2,3,4,5,5};
    cout<<s.stoneGameV(v)<<endl;
    v.clear();v={7,7,7,7,7,7,7};
    cout<<s.stoneGameV(v)<<endl;
    v.clear();v={4};
    cout<<s.stoneGameV(v)<<endl;
    return 0;
}
