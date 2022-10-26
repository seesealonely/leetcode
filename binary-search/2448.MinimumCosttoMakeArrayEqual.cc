/*
   You are given two 0-indexed arrays nums and cost consisting each of n positive integers.

   You can do the following operation any number of times:

   Increase or decrease any element of the array nums by 1.

   The cost of doing one operation on the ith element is cost[i].

   Return the minimum total cost such that all the elements of the array nums become equal.



   Example 1:

Input: nums = [1,3,5,2], cost = [2,3,1,14]
Output: 8
Explanation: We can make all the elements equal to 2 in the following way:
- Increase the 0th element one time. The cost is 2.
- Decrease the 1st element one time. The cost is 3.
- Decrease the 2nd element three times. The cost is 1 + 1 + 1 = 3.
The total cost is 2 + 3 + 3 = 8.
It can be shown that we cannot make the array equal with a smaller cost.

Example 2:

Input: nums = [2,2,2,2,2], cost = [4,2,8,1,3]
Output: 0
Explanation: All the elements are already equal, so no operations are needed.



Constraints:

n == nums.length == cost.length
1 <= n <= 105
1 <= nums[i], cost[i] <= 106

*/


#include"head.h"
class Solution {
    public:
        long long minCost(vector<int>& nums, vector<int>& cost) {
        int l=INT_MAX,r=INT_MIN,n=nums.size();
        for(int i=0;i<n;i++)
        {
            l=min(l,nums[i]);
            r=max(r,nums[i]);
        }

        while(l<r)
        {
            int mid=(l+r)>>1;
            if(check(mid,nums,cost)<=check(mid+1,nums,cost))
                r=mid;
            else
                l=mid+1;

        }

        return check(l,nums,cost);
        }
        long long check(int limit,vector<int>&nums,vector<int>&cost)
        {
            long long res=0,n=nums.size();
            for(int i=0;i<n;i++)
            {
                res+=(long long)cost[i]*abs(limit-nums[i]);
            }

            return res;
        }
};


int main() 
{
    Solution s;
    vector<int> v1={1,3,5,2},v2={2,3,1,14};
    cout<<s.minCost(v1,v2)<<endl;
    v1.clear();v1={2,2,2,2,2},v2={4,2,8,1,3};
    cout<<s.minCost(v1,v2)<<endl;
    return 0;
}
