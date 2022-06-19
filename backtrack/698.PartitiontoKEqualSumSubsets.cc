/*
   Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.



   Example 1:

Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

Example 2:

Input: nums = [1,2,3,4], k = 3
Output: false



Constraints:

1 <= k <= nums.length <= 16
1 <= nums[i] <= 104
The frequency of each element is in the range [1, 4].

*/


#include"head.h"
class Solution {
    public:
        bool canPartitionKSubsets(vector<int>& nums, int k) {
            int n=nums.size(),bn=(1<<n);
            int sum=accumulate(nums.begin(),nums.end(),0),t=sum/k;
            sort(nums.rbegin(),nums.rend());

            if(sum%k||nums[0]>t) return false;
            vector<bool> tag(nums.size(),false);
            return solve(0,0,sum%k,k-1,nums,tag);
        }
        bool solve(int cur,int start,int sum,int cnt,vector<int>&nums,vector<bool> &tag)
        {
            if(!cnt) return true;
            if(cur>sum) return false;
            if(cur==sum) return solve(0,0,sum,cnt-1,nums,tag);

            for(int i=start;i<nums.size();i++)
            {
                if(!tag[i])
                {
                    if(cur>sum) return false;
                    tag[i]=true;
                    if(solve(cur+nums[i],i+1,sum,cnt,nums,tag))
                        return true;
                    tag[i]=false;
                }
            } 
            return false;
        }
};


int main() 
{
    Solution s;
    vector<int> v={4,3,2,3,5,2,1};
    cout<<s.canPartitionKSubsets(v,4)<<endl;
    v.clear();v={1,2,3,4};
    cout<<s.canPartitionKSubsets(v,3)<<endl;
    return 0;
}
