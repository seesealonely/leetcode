/*
   You are given an integer n. You have an n x n binary grid grid with all values initially 1's except for some indices given in the array mines. The ith element of the array mines is defined as mines[i] = [xi, yi] where grid[xi][yi] == 0.

   Return the order of the largest axis-aligned plus sign of 1's contained in grid. If there is none, return 0.

   An axis-aligned plus sign of 1's of order k has some center grid[r][c] == 1 along with four arms of length k - 1 going up, down, left, and right, and made of 1's. Note that there could be 0's or 1's beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1's.



   Example 1:

Input: n = 5, mines = [[4,2]]
Output: 2
Explanation: In the above grid, the largest plus sign can only be of order 2. One of them is shown.

Example 2:

Input: n = 1, mines = [[0,0]]
Output: 0
Explanation: There is no plus sign, so return 0.



Constraints:

1 <= n <= 500
1 <= mines.length <= 5000
0 <= xi, yi < n
All the pairs (xi, yi) are unique.

*/

#define c11
#include"head.h"
class Solution {
    public:
        int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> dp(n,vector<int>(n,0));
        unordered_set<int> s;
        const int r=mines.size();
        for(int i=0;i<r;i++)
                s.insert(mines[i][0]*n+mines[i][1]);

        for(int i=0;i<n;i++) //i express column
        {
            int cnt=0;
            for(int j=0;j<n;j++) //j express row up
            {
                cnt=s.count(n*j+i)?0:cnt+1;
                dp[j][i]=cnt;
            }

            cnt=0;
            for(int j=n-1;j>=0;j--) //j express row down
            {
                cnt=s.count(n*j+i)?0:cnt+1;
                dp[j][i]=min(dp[j][i],cnt);
            }
        }

        int res=0;
        for(int i=0;i<n;i++) //i express row 
        {
            int cnt=0;
            for(int j=0;j<n;j++) //j express colunm left
            {
                cnt=s.count(n*i+j)?0:cnt+1;
                dp[i][j]=min(dp[i][j],cnt);
            }

            cnt=0;
            for(int j=n-1;j>=0;j--)
            {
                cnt=s.count(n*i+j)?0:cnt+1;
                dp[i][j]=min(dp[i][j],cnt);
                res=max(dp[i][j],res);
            }
        }

        return res;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{4,2}};
    cout<<s.orderOfLargestPlusSign(5,v)<<endl;
    v.clear();v={{0,0}};
    cout<<s.orderOfLargestPlusSign(1,v)<<endl;
    return 0;
}
