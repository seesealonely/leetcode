/*
   Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.

   Return the positive integer k. If there is no such integer, return -1.



   Example 1:

Input: nums = [-1,2,-3,3]
Output: 3
Explanation: 3 is the only valid k we can find in the array.

Example 2:

Input: nums = [-1,10,6,7,-7,1]
Output: 7
Explanation: Both 1 and 7 have their corresponding negative values in the array. 7 has a larger value.

Example 3:

Input: nums = [-10,8,6,7,-2,-3]
Output: -1
Explanation: There is no a single valid k, we return -1.



Constraints:

1 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
nums[i] != 0

*/

#define c11
#include"head.h"
class Solution {
    public:
        int findMaxK(vector<int>& nums) {
        unordered_map<int,bool> cnt;
        for(int i=0;i<nums.size();i++)
            if(nums[i]<=0)
                cnt[abs(nums[i])]=true;

        int res=INT_MIN;
        for(int i=0;i<nums.size();i++)
            if(nums[i]>=0&&cnt[nums[i]])
                res=max(res,nums[i]);
        return res==INT_MIN?-1:res; 
        }
};


int main() 
{
    Solution s;
    vector<int> v={-1,2,-3,3};
    cout<<s.findMaxK(v)<<endl;
    v.clear();v={-1,10,6,7,-7,1};
    cout<<s.findMaxK(v)<<endl;
    v.clear();v={-10,8,6,7,-2,-3};
    cout<<s.findMaxK(v)<<endl;
    return 0;
}
