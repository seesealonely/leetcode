/*
   Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

   Return the running sum of nums.



   Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

Example 2:

Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].

Example 3:

Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]



Constraints:

1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6
*/
#include"head.h"
class Solution {
    public:
        vector<int> runningSum(vector<int>& nums) {
        const int n=nums.size();
        vector<int> res(n,0);
        res[0]=nums[0];
        for(int i=1;i<n;i++)
            res[i]+=res[i-1]+nums[i];

        return res;
        }
};
int main() 
{
    Solution s;
    vector<int> v={1,2,3,4};
    show(s.runningSum(v));
    v.clear();v={1,1,1,1,1};
    show(s.runningSum(v));
    v.clear();v={3,1,2,10,1};
    show(s.runningSum(v));
    return 0;
}
