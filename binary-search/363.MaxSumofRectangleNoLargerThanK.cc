/*
   Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.

   It is guaranteed that there will be a rectangle with a sum no larger than k.



   Example 1:

Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2
Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).

Example 2:

Input: matrix = [[2,2,-1]], k = 3
Output: 3



Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-100 <= matrix[i][j] <= 100
-105 <= k <= 105



Follow up: What if the number of rows is much larger than the number of columns?
*/


#include"head.h"
class Solution {
    public:
        int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
            int r=matrix.size(),c=matrix[0].size(),res=INT_MIN;

            for(int le=0;le<c;le++)
            {
                vector<int> row(r,0);
                for(int ri=le;ri<c;ri++)
                {
                    set<int> presum;
                    presum.insert(0);
                    int sum=0;
                    for(int i=0;i<r;i++)
                    {
                        row[i]+=matrix[i][ri];
                        sum+=row[i];
                        set<int>::iterator it=presum.lower_bound(sum-k);
                        if(it!=presum.end())
                            res=max(res,sum-*it);
                        presum.insert(sum);
                    }
                }
            }

            return res;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{1,0,1},{0,-2,3}};
    cout<<s.maxSumSubmatrix(v,2)<<endl;
    return 0;
}
