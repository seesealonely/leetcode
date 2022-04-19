/*
   You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:

   nums.length == n
   nums[i] is a positive integer where 0 <= i < n.
   abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
   The sum of all the elements of nums does not exceed maxSum.
   nums[index] is maximized.

   Return nums[index] of the constructed array.

   Note that abs(x) equals x if x >= 0, and -x otherwise.



   Example 1:

Input: n = 4, index = 2, maxSum = 6
Output: 2
Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].

Example 2:

Input: n = 6, index = 1, maxSum = 10
Output: 3



Constraints:

1 <= n <= maxSum <= 109
0 <= index < n

*/


#include"head.h"
class Solution {
    public:
        int maxValue(int n, int index, int maxSum) {
            int l=0,r=maxSum;
            maxSum-=n;
            while(l<r)
            {
                int m=l+r+1>>1;
                if(getSum(n,index,m)>maxSum)
                    r=m-1;
                else
                    l=m;
            }
            return l+1;
        }
        long long getSum(int n,int i,int m)
        {
            long long  res=0,mn=0;
            mn=max(m-i,0);
            res=(long long)(m+mn)*(m-mn+1)>>1;
            mn=max(m-(n-1-i),0);
            res+=(long long)(m+mn)*(m-mn+1)>>1;
            return res-m;
        }
};


int main() 
{
    Solution s;
    cout<<s.maxValue(4,2,6)<<endl;
    cout<<s.maxValue(6,1,10)<<endl;
    return 0;
}
