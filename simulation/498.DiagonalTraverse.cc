/*
   Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.



   Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]

Example 2:

Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]



Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
-105 <= mat[i][j] <= 105

*/


#include"head.h"
class Solution {
    public:
        vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
            int r=mat.size(),c=mat[0].size();
            bool rflag=false;
            vector<int> res;
            for(int i=0;i<=r+c-2;i++)
            {
                int rcur=0,ccur=0;
                if(rflag) 
                    ccur=i<c?i:c-1,rcur=i-ccur;
                else
                    rcur=i<r?i:r-1,ccur=i-rcur;
                while(rcur>=0&&rcur<r&&ccur>=0&&ccur<c)
                {
                    if(rflag)
                        res.push_back(mat[rcur++][ccur--]);
                    else
                        res.push_back(mat[rcur--][ccur++]);
                }
                rflag^=true;
            }
            return res;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{1,2,3},{4,5,6},{7,8,9}};
    show(s.findDiagonalOrder(v));
    v.clear();v={{1,2},{3,4}};
    show(s.findDiagonalOrder(v));
    return 0;
}
