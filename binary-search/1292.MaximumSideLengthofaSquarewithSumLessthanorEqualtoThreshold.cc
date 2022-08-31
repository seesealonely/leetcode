/*
   Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.



   Example 1:

Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
Output: 2
Explanation: The maximum side length of square with sum less than 4 is 2 as shown.

Example 2:

Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
Output: 0



Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 300
0 <= mat[i][j] <= 104
0 <= threshold <= 105

*/


#include"head.h"
class Solution {
    public:
        int maxSideLength(vector<vector<int>>& mat, int threshold) {
            const int r=mat.size(),c=mat[0].size();
            vector<vector<int>> sum(r+1,vector<int>(c+1,0));

            for(int i=1;i<=r;i++)
                for(int j=1;j<=c;j++)
                    sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mat[i-1][j-1];

            int l=0,ri=min(r,c);
            while(l<ri)
            {
                int mid=(l+ri+1)>>1;
                if(check(sum,r,c,mid,threshold))
                    l=mid;
                else
                    ri=mid-1;
            }
            return l;
        }
        bool check(vector<vector<int>> &sum,int r,int c,int mid,int threshold)
        {
            for(int i=0;i<=r-mid;i++)
                for(int j=0;j<=c-mid;j++)
                {
                    int x=i+mid,y=j+mid;
                    if(sum[x][y]-sum[x][j]-sum[i][y]+sum[i][j]<=threshold)
                        return true;
                }

            return false;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{1,1,3,2,4,3,2},{1,1,3,2,4,3,2},{1,1,3,2,4,3,2}};
    cout<<s.maxSideLength(v,4)<<endl;
    v.clear();v={{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2}};
    cout<<s.maxSideLength(v,1)<<endl;
    return 0;
}
