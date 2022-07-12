/*
   You are given an array of integers arr and an integer target.

   You have to find two non-overlapping sub-arrays of arr each with a sum equal target. There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is minimum.

   Return the minimum sum of the lengths of the two required sub-arrays, or return -1 if you cannot find such two sub-arrays.



   Example 1:

Input: arr = [3,2,2,4,3], target = 3
Output: 2
Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). The sum of their lengths is 2.

Example 2:

Input: arr = [7,3,4,7], target = 7
Output: 2
Explanation: Although we have three non-overlapping sub-arrays of sum = 7 ([7], [3,4] and [7]), but we will choose the first and third sub-arrays as the sum of their lengths is 2.

Example 3:

Input: arr = [4,3,2,6,2,3,4], target = 6
Output: -1
Explanation: We have only one sub-array of sum = 6.



Constraints:

1 <= arr.length <= 105
1 <= arr[i] <= 1000
1 <= target <= 108

*/


#include"head.h"
class Solution {
    public:
        int minSumOfLengths(vector<int>& arr, int target) {
            int n=arr.size(),sum=0,res=INT_MAX;
            vector<int> dp(n+1,0);
            dp[0]=n+1;
            for(int r=0,l=0;r<n;r++)
            {
               sum+=arr[r];
               while(sum>target&&l<=r)
                   sum-=arr[l++];
                
               if(sum==target)
               {
                   int len=r-l+1;
                   res=min(res,len+dp[l]);
                   dp[r+1]=min(dp[r],len);
               }
               else 
                   dp[r+1]=dp[r];
            }
            return res>n?-1:res;
        }
};


int main() 
{
    Solution s;
    vector<int> v={3,2,2,4,3};
    cout<<s.minSumOfLengths(v,3)<<endl;
    v.clear();v={7,3,4,7};
    cout<<s.minSumOfLengths(v,7)<<endl;
    v.clear();v={4,3,2,6,2,3,4};
    cout<<s.minSumOfLengths(v,6)<<endl;
    return 0;
}
