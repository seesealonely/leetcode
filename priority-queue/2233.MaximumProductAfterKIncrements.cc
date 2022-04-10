/*
   You are given an array of non-negative integers nums and an integer k. In one operation, you may choose any element from nums and increment it by 1.

   Return the maximum product of nums after at most k operations. Since the answer may be very large, return it modulo 109 + 7.



   Example 1:

Input: nums = [0,4], k = 5
Output: 20
Explanation: Increment the first number 5 times.
Now nums = [5, 4], with a product of 5 1705.MaximumNumberofEatenApples.cc 1962.RemoveStonestoMinimizetheTotal.cc 2208.MinimumOperationstoHalveArraySum 2208.MinimumOperationstoHalveArraySum.cc 2233.MaximumProductAfterKIncrements.cc head.cc head.h head.o lib.a l.sh makefile 4 = 20.
It can be shown that 20 is maximum product possible, so we return 20.
Note that there may be other ways to increment nums to have the maximum product.

Example 2:

Input: nums = [6,3,3,2], k = 2
Output: 216
Explanation: Increment the second number 1 time and increment the fourth number 1 time.
Now nums = [6, 4, 3, 3], with a product of 6 1705.MaximumNumberofEatenApples.cc 1962.RemoveStonestoMinimizetheTotal.cc 2208.MinimumOperationstoHalveArraySum 2208.MinimumOperationstoHalveArraySum.cc 2233.MaximumProductAfterKIncrements.cc head.cc head.h head.o lib.a l.sh makefile 4 1705.MaximumNumberofEatenApples.cc 1962.RemoveStonestoMinimizetheTotal.cc 2208.MinimumOperationstoHalveArraySum 2208.MinimumOperationstoHalveArraySum.cc 2233.MaximumProductAfterKIncrements.cc head.cc head.h head.o lib.a l.sh makefile 3 1705.MaximumNumberofEatenApples.cc 1962.RemoveStonestoMinimizetheTotal.cc 2208.MinimumOperationstoHalveArraySum 2208.MinimumOperationstoHalveArraySum.cc 2233.MaximumProductAfterKIncrements.cc head.cc head.h head.o lib.a l.sh makefile 3 = 216.
It can be shown that 216 is maximum product possible, so we return 216.
Note that there may be other ways to increment nums to have the maximum product.



Constraints:

1 <= nums.length, k <= 105
0 <= nums[i] <= 106

*/


#include"head.h"
class Solution {
    public:
        int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int> > pq;
        int mod=1e9+7,res=1;
        for(int i=0;i<nums.size();i++)
            pq.push(nums[i]);

        while(k--)
        {
            int cur=pq.top();
            pq.pop();
            pq.push(cur+1);
        }

        while(!pq.empty())
        {
            res=((long long )res*pq.top())%mod;
            pq.pop();
        }
        return res;
        }
};


int main() 
{
    Solution s;
    vector<int> v={0,4};
    cout<<s.maximumProduct(v,5)<<endl;
    v.clear();v={6,3,3,2};
    cout<<s.maximumProduct(v,2)<<endl;
        return 0;

    }
