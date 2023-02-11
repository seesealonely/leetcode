/*
   There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

   You will pick any pizza slice.
   Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
   Your friend Bob will pick the next slice in the clockwise direction of your pick.
   Repeat until there are no more slices of pizzas.

   Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.



   Example 1:

Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.

Example 2:

Input: slices = [8,9,8,6,1,1]
Output: 16
Explanation: Pick pizza slice of size 8 in each turn. If you pick slice with size 9 your partners will pick slices of size 8.



Constraints:

3 * n == slices.length
1 <= slices.length <= 500
1 <= slices[i] <= 1000

*/


#include"head.h"
class Solution {
    public:
        int maxSizeSlices(vector<int>& slices) {
        vector<int> s(slices);
        slices[0]=s.back()=INT_MIN;
        return max(solve(slices),solve(s));
        }
        int solve(vector<int>& s)
        {
            const int n=s.size();
            vector<vector<int>> dp(n+1,vector<int>(n/3+1,0));

            dp[1][1]=s[0];
            for(int i=2;i<=n;i++)
                for(int j=1;j<=n/3;j++)
                    dp[i][j]=max(dp[i-1][j],dp[i-2][j-1]+s[i-1]);

            return dp[n].back();
        }
};


int main() 
{
    Solution s;
    vector<int> v={1,2,3,4,5,6};
    cout<<s.maxSizeSlices(v)<<endl;
    v.clear();v={8,9,8,6,1,1};
    cout<<s.maxSizeSlices(v)<<endl;
    return 0;
}
