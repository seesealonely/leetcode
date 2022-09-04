/*
   You are given a 0-indexed m x n binary matrix mat and an integer cols, which denotes the number of columns you must choose.

   A row is covered by a set of columns if each cell in the row that has a value of 1 also lies in one of the columns of the chosen set.

   Return the maximum number of rows that can be covered by a set of cols columns.



   Example 1:

Input: mat = [[0,0,0],[1,0,1],[0,1,1],[0,0,1]], cols = 2
Output: 3
Explanation:
As shown in the diagram above, one possible way of covering 3 rows is by selecting the 0th and 2nd columns.
It can be shown that no more than 3 rows can be covered, so we return 3.

Example 2:

Input: mat = [[1],[0]], cols = 1
Output: 2
Explanation:
Selecting the only column will result in both rows being covered, since the entire matrix is selected.
Therefore, we return 2.



Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 12
mat[i][j] is either 0 or 1.
1 <= cols <= n

*/


#include"head.h"
class Solution {
    public:
        int maximumRows(vector<vector<int>>& mat, int cols) {
            int res=0;
            backTrace(mat,0,0,cols,res);

            return res;
        }
        int calc(int mask,vector<vector<int>> &mat)
        {
            int res=0,r=mat.size(),c=mat[0].size();
            for(int i=0;i<r;i++)
            {
                bool flag=true;
                for(int j=0;j<c;j++)
                    if(mat[i][j]==1&&((mask>>j)&1)==0)
                        flag=false;

                if(flag)
                    res++;
            }

            return res;
        }
        void backTrace(vector<vector<int>> &mat,int mask,int start,int cols,int &res)
        {
            if(start+cols>mat[0].size())
                return ;

            if(cols==0)
            {
                res=max(res,calc(mask,mat));
                return ;
            }

            backTrace(mat,mask|(1<<start),start+1,cols-1,res);
            backTrace(mat,mask,start+1,cols,res);
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{0,0,0},{1,0,1},{0,1,1},{0,0,1}};
    cout<<s.maximumRows(v,2)<<endl;
    v.clear();v={{1},{0}};
    cout<<s.maximumRows(v,1)<<endl;
    return 0;
}
