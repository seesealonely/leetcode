/*
   Given a rectangular pizza represented as a rows x cols matrix containing the following characters: 'A' (an apple) and '.' (empty cell) and given the integer k. You have to cut the pizza into k pieces using k-1 cuts.

   For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.

   Return the number of ways of cutting the pizza such that each piece contains at least one apple. Since the answer can be a huge number, return this modulo 10^9 + 7.



   Example 1:

Input: pizza = ["A..","AAA","..."], k = 3
Output: 3
Explanation: The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.

Example 2:

Input: pizza = ["A..","AA.","..."], k = 3
Output: 1

Example 3:

Input: pizza = ["A..","A..","..."], k = 1
Output: 1



Constraints:

1 <= rows, cols <= 50
rows == pizza.length
cols == pizza[i].length
1 <= k <= 10
pizza consists of characters 'A' and '.' only.
*/


#include"head.h"
class Solution {
    public:
        int ways(vector<string>& pizza, int k) {
        const int r=pizza.size(),c=pizza[0].size(),mod=1e9+7;

        vector<vector<vector<int>>> dp(k,vector<vector<int>>(r,vector<int>(c,0)));
        vector<vector<int>> sum(r+1,vector<int>(c+1,0));

        for(int i=r-1;i>=0;i--)
            for(int j=c-1;j>=0;j--)
                sum[i][j]=(int)(pizza[i][j]=='A')+sum[i+1][j]+sum[i][j+1]-sum[i+1][j+1];

        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                dp[0][i][j]=sum[i][j]>0;

        for(int f=0;f<k-1;f++)
            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                {
                    for(int cut=i+1;cut<r;cut++)
                        if(check(i,j,cut-1,c-1,sum))
                            dp[f+1][i][j]=(dp[f+1][i][j]+dp[f][cut][j])%mod;

                    for(int cut=j+1;cut<c;cut++)
                        if(check(i,j,r-1,cut-1,sum))
                            dp[f+1][i][j]=(dp[f+1][i][j]+dp[f][i][cut])%mod;
                }

        return dp[k-1][0][0];
        }
        bool check(int i,int j,int x,int y,vector<vector<int>> &s)
        {
            return s[i][j]-s[x+1][j]-s[i][y+1]+s[x+1][y+1]>0;
        }
};


int main() 
{
    Solution s;
    vector<string> v={"A..","AAA","..."};
    cout<<s.ways(v,3)<<endl;
    v.clear();v={"A..","AA.","..."};
    cout<<s.ways(v,3)<<endl;
    v.clear();v={"A..","A..","..."};
    cout<<s.ways(v,1)<<endl;
    return 0;
}
