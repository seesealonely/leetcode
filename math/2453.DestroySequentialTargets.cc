/*
   You are given a 0-indexed array nums consisting of positive integers, representing targets on a number line. You are also given an integer space.

   You have a machine which can destroy targets. Seeding the machine with some nums[i] allows it to destroy all targets with values that can be represented as nums[i] + c * space, where c is any non-negative integer. You want to destroy the maximum number of targets in nums.

   Return the minimum value of nums[i] you can seed the machine with to destroy the maximum number of targets.



   Example 1:

Input: nums = [3,7,8,1,1,5], space = 2
Output: 1
Explanation: If we seed the machine with nums[3], then we destroy all targets equal to 1,3,5,7,9,... 
In this case, we would destroy 5 total targets (all except for nums[2]). 
It is impossible to destroy more than 5 targets, so we return nums[3].

Example 2:

Input: nums = [1,3,5,2,4,6], space = 2
Output: 1
Explanation: Seeding the machine with nums[0], or nums[3] destroys 3 targets. 
It is not possible to destroy more than 3 targets.
Since nums[0] is the minimal integer that can destroy 3 targets, we return 1.

Example 3:

Input: nums = [6,2,5], space = 100
Output: 2
Explanation: Whatever initial seed we select, we can only destroy 1 target. The minimal seed is nums[1].



Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= space <= 109

*/

#define c11
#include"head.h"
class Solution {
    public:
        int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,int> fre;
        int mod=-1;
        for(int i=0;i<nums.size();i++)
            if(++fre[nums[i]%space]>mod)
                mod=fre[nums[i]%space];

        int res=INT_MAX;
        for(int i=0;i<nums.size();i++)
            if(fre[nums[i]%space]==mod)
                res=min(res,nums[i]);

        return res;
        }
};


int main() 
{
    Solution s;
    vector<int> v={3,7,8,1,1,5};
    cout<<s.destroyTargets(v,2)<<endl;
    v.clear();v={1,3,5,2,4,6};
    cout<<s.destroyTargets(v,2)<<endl;
    v.clear();v={6,2,5};
    cout<<s.destroyTargets(v,100)<<endl;
    return 0;
}
