/*
   You are given an m x n binary matrix matrix.

   You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa).

   Return the maximum number of rows that have all values equal after some number of flips.



   Example 1:

Input: matrix = [[0,1],[1,1]]
Output: 1
Explanation: After flipping no values, 1 row has all values equal.

Example 2:

Input: matrix = [[0,1],[1,0]]
Output: 2
Explanation: After flipping values in the first column, both rows have equal values.

Example 3:

Input: matrix = [[0,0,0],[0,0,1],[1,1,0]]
Output: 2
Explanation: After flipping values in the first two columns, the last two rows have equal values.



Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is either 0 or 1.

*/

#define c11
#include"head.h"
class Solution {
    public:
        int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
            const int r=matrix.size(),c=matrix[0].size();
            unordered_map<string,int> fre;

            int res=0;
            for(int i=0;i<r;i++)
            {
                string key;
                for(int j=0;j<matrix[i].size();j++)
                {
                    if(matrix[i][0]==0)
                        key+=to_string(matrix[i][j]);
                    else
                        key+=to_string(matrix[i][j]^1);
                }
                res=max(res,++fre[key]);
            }
            return res;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{0,1},{1,1}};
    cout<<s.maxEqualRowsAfterFlips(v)<<endl;
    v.clear();v={{0,1},{1,0}};
    cout<<s.maxEqualRowsAfterFlips(v)<<endl;
    v.clear();v={{0,0,0},{0,0,1},{1,1,0}};
    cout<<s.maxEqualRowsAfterFlips(v)<<endl;
    return 0;
}
