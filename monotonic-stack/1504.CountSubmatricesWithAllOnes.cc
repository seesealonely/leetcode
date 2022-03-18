/*
   Given an m x n binary matrix mat, return the number of submatrices that have all ones.



   Example 1:

Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
Output: 13
Explanation:
There are 6 rectangles of side 1x1.
There are 2 rectangles of side 1x2.
There are 3 rectangles of side 2x1.
There is 1 rectangle of side 2x2.
There is 1 rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.

Example 2:

Input: mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
Output: 24
Explanation:
There are 8 rectangles of side 1x1.
There are 5 rectangles of side 1x2.
There are 2 rectangles of side 1x3.
There are 4 rectangles of side 2x1.
There are 2 rectangles of side 2x2.
There are 2 rectangles of side 3x1.
There is 1 rectangle of side 3x2.
Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.



Constraints:

1 <= m, n <= 150
mat[i][j] is either 0 or 1.

*/
#include"head.h"
class Solution {
    public:
        int numSubmat(vector<vector<int>>& mat) {
            int r=mat.size(),c=mat[0].size(),res=0;
            vector<int> subsum(c,0);

            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                subsum[j]=(mat[i][j]==0?0:subsum[j]+1);                
                res+=countSubRow(subsum);
            }
            return res;
        }
        int countSubRow(vector<int> &s)
        {
            const int n=s.size();
            vector<int> sum(n,0);
            stack<int> st;

            for(int i=0;i<n;i++)
            {
                while(!st.empty()&&s[st.top()]>=s[i]) st.pop();

                if(!st.empty())
                {
                       sum[i]=sum[st.top()];
                       sum[i]+=s[i]*(i-st.top());
                }
                else
                    sum[i]=s[i]*(i+1);
                st.push(i);
            }

            int res=0;
            for(int i=0;i<n;i++)
                res+=sum[i];
            return res;
        }
};
int main() 
{
    Solution s;
    vector<vector<int> > v={{1,0,1},{1,1,0},{1,1,0}};
    cout<<s.numSubmat(v)<<endl;
    v.clear();v={{0,1,1,0},{0,1,1,1},{1,1,1,0}};
    cout<<s.numSubmat(v)<<endl;
    v.clear();v={{1,1,1,1,0,1,0},{1,1,1,0,0,0,1},{0,1,1,1,1,0,0},{1,1,0,1,1,0,1},{1,0,0,0,0,0,1},{1,1,0,1,1,1,1},{1,1,0,0,1,1,1}};
    cout<<s.numSubmat(v)<<endl;
    return 0;
}
