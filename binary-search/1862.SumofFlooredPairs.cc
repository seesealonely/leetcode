/*
   Given an integer array nums, return the sum of floor(nums[i] / nums[j]) for all pairs of indices 0 <= i, j < nums.length in the array. Since the answer may be too large, return it modulo 109 + 7.

   The floor() function returns the integer part of the division.



   Example 1:

Input: nums = [2,5,9]
Output: 10
Explanation:
floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
floor(5 / 2) = 2
floor(9 / 2) = 4
floor(9 / 5) = 1
We calculate the floor of the division for every pair of indices in the array then sum them up.

Example 2:

Input: nums = [7,7,7,7,7,7,7]
Output: 49



Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105

*/


#include"head.h"
class Solution {
    public:
        int sumOfFlooredPairs(vector<int>& nums) {
            return binary_search(nums);
        }
        int binary_search(vector<int>& nums) {
            const int mod=1e9+7,n=nums.size();
            sort(nums.begin(),nums.end());
            int res=0;
            for(int i=0;i<n;i++)
            {
                int s=0;
                while(s<n)
                {
                int div=nums[s]/nums[i],target=(div+1)*nums[i];
                int e=lower_bound(nums.begin()+s,nums.end(),target)-nums.begin();
                res=(res+(e-s)*div)%mod;
                s=e;
                }
            }
            return res;
        }

};


int main() 
{
    Solution s;
    vector<int> v={2,5,9};
    cout<<s.sumOfFlooredPairs(v)<<endl;
    v.clear();v={7,7,7,7,7,7,7};
    cout<<s.sumOfFlooredPairs(v)<<endl;
    return 0;
}
