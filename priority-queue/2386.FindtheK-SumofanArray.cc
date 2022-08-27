/*
   You are given an integer array nums and a positive integer k. You can choose any subsequence of the array and sum all of its elements together.

   We define the K-Sum of the array as the kth largest subsequence sum that can be obtained (not necessarily distinct).

   Return the K-Sum of the array.

   A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

   Note that the empty subsequence is considered to have a sum of 0.



   Example 1:

Input: nums = [2,4,-2], k = 5
Output: 2
Explanation: All the possible subsequence sums that we can obtain are the following sorted in decreasing order:
- 6, 4, 4, 2, 2, 0, 0, -2.
The 5-Sum of the array is 2.

Example 2:

Input: nums = [1,-2,3,4,-10,12], k = 16
Output: 10
Explanation: The 16-Sum of the array is 10.



Constraints:

n == nums.length
1 <= n <= 105
-109 <= nums[i] <= 109
1 <= k <= min(2000, 2n)

*/


#include"head.h"
class Solution {
    public:
        #define ll long long 
        long long kSum(vector<int>& nums, int k) {
        ll n=nums.size(),sum=0LL;
        for(int i=0;i<n;i++)
            if(nums[i]>0)
                sum+=nums[i];
            else
                nums[i]=-nums[i];

        sort(nums.begin(),nums.end());

        priority_queue<pair<ll,int>> q;q.push({sum,0});
        while(--k)
        {
            pair<ll,int> p=q.top(); q.pop();
            ll sum=p.first; int i=p.second;
            
            if(i==n)
                continue;

            if(i>0)
                q.push({sum-nums[i]+nums[i-1],i+1});
            q.push({sum-nums[i],i+1});
        }

        return q.top().first;

        }
};


int main() 
{
    Solution s;
    vector<int> v={2,4,-2};
    cout<<s.kSum(v,5)<<endl;
    v.clear();v={1,-2,3,4,-10,12};
    cout<<s.kSum(v,16)<<endl;
    return 0;
}
