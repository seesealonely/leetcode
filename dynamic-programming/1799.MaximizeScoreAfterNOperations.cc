/*
   You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.

   In the ith operation (1-indexed), you will:

   Choose two elements, x and y.
   Receive a score of i * gcd(x, y).
   Remove x and y from nums.

   Return the maximum score you can receive after performing n operations.

   The function gcd(x, y) is the greatest common divisor of x and y.



   Example 1:

Input: nums = [1,2]
Output: 1
Explanation: The optimal choice of operations is:
(1 * gcd(1, 2)) = 1

Example 2:

Input: nums = [3,4,6,8]
Output: 11
Explanation: The optimal choice of operations is:
(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11

Example 3:

Input: nums = [1,2,3,4,5,6]
Output: 14
Explanation: The optimal choice of operations is:
(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14



Constraints:

1 <= n <= 7
nums.length == 2 * n
1 <= nums[i] <= 106

*/
#include"head.h"
class Solution {
    public:
        int maxScore(vector<int>& nums) {
            const int n=nums.size();
            vector<int> dp(1<<n,0);
            for(int i=0;i<n;i++)
                for(int j=i+1;j<n;j++)
                    dp[(1<<i)|(1<<j)]=gcd(nums[i],nums[j]);

            for(int i=1;i<(1<<n);i++)
            {
                    if(countBit(i)%2) continue;
                    for(int j=i;j;j=(j-1)&i)
                    {
                        if(countBit(i)-countBit(j)==2)
                            dp[i]=max(dp[i],countBit(i)/2*dp[i^j]+dp[j]);
                    }
            }
        return dp[(1<<n)-1];
        }
        int countBit(int n)
        {
            int res=0;
            while(n>0)
            {
                n=n&(n-1);
                res++;
            }
            return res;
        }
        int gcd(int a,int b)
        {
            while(b)
            {
                int tmp=b;
                b=a%b;
                a=tmp;
            }
            return a;
        }
};
int main() 
{
    Solution s;
    vector<int> v={1,2};
    cout<<s.maxScore(v)<<endl;
    v.clear();v={3,4,6,8};
    cout<<s.maxScore(v)<<endl;
    v.clear();v={1,2,3,4,5,6};
    cout<<s.maxScore(v)<<endl;
    return 0;
}
