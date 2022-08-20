/*
   You are given a map of a server center, represented as a m 1139.Largest1-BorderedSquare 1139.Largest1-BorderedSquare.cc 1222.QueensThatCanAttacktheKing 1222.QueensThatCanAttacktheKing.cc 1267.CountServersthatCommunicate.cc 2217.FindPalindromeWithFixedLength 2217.FindPalindromeWithFixedLength.cc 2373.LargestLocalValuesinaMatrix 2373.LargestLocalValuesinaMatrix.cc 963.MinimumAreaRectangleII 963.MinimumAreaRectangleII.cc 985.SumofEvenNumbersAfterQueries 985.SumofEvenNumbersAfterQueries.cc head.cc head.h head.o lib.a l.sh makefile n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

   Return the number of servers that communicate with any other server.



   Example 1:

Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.

Example 2:

Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.

Example 3:

Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.



Constraints:

m == grid.length
n == grid[i].length
1 <= m <= 250
1 <= n <= 250
grid[i][j] == 0 or 1

*/


#include"head.h"
class Solution {
    public:
        int countServers(vector<vector<int>>& grid) {
        int res=0,cnt=0,r=grid.size(),c=grid[0].size();
        for(int i=0;i<r;i++)
        {
            cnt=0;
            for(int j=0;j<c;j++)
                if(grid[i][j]==1)
                    cnt++;
            if(cnt>1)
                for(int j=0;j<c;j++)
                    if(grid[i][j]==1)
                        grid[i][j]=2;
        }

        for(int j=0;j<c;j++)
        {
            cnt=0;
            for(int i=0;i<r;i++)
                if(grid[i][j]==1||grid[i][j]==2)
                    cnt++;
            if(cnt>1)
                for(int i=0;i<r;i++)
                    if(grid[i][j]==1)
                        grid[i][j]=2;
        }

        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(grid[i][j]==2)
                    res++;

        return res;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{1,0},{0,1}};
    cout<<s.countServers(v)<<endl;
    v.clear();v={{1,0},{1,1}};
    cout<<s.countServers(v)<<endl;
    v.clear();v={{1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};
    cout<<s.countServers(v)<<endl;
    return 0;
}
