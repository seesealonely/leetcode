/*
   Given two arrays of integers with equal lengths, return the maximum value of:

   |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|

   where the maximum is taken over all 0 <= i, j < arr1.length.

    

   Example 1:

Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
Output: 13

Example 2:

Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
Output: 20

 

Constraints:

2 <= arr1.length == arr2.length <= 40000
-10^6 <= arr1[i], arr2[i] <= 10^6

*/


#include"head.h"
class Solution {
    public:
        int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        return max(max(compute(1,1,arr1,arr2),compute(-1,1,arr1,arr2)),max(compute(1,-1,arr1,arr2),compute(-1,-1,arr1,arr2)));
        }
        int compute(int s1,int s2,const vector<int> &v1,const vector<int> &v2)
        {
            const int n=v1.size();
            int mn=s1*v1[0]+s2*v2[0];

            int res=0;
            for(int i=1;i<n;i++)
            {
                int cur=s1*v1[i]+s2*v2[i]+i;
                res=max(res,cur-mn);
                mn=min(mn,cur);
            }

            return res;
        }
};


int main() 
{
    Solution s;
    vector<int> v1={1,2,3,4},v2={-1,4,5,6};
    cout<<s.maxAbsValExpr(v1,v2)<<endl;
    v1.clear();v1={1,-2,-5,0,10};
    v2.clear();v2={0,-2,-1,-7,-4};
    cout<<s.maxAbsValExpr(v1,v2)<<endl;
    return 0;
}
