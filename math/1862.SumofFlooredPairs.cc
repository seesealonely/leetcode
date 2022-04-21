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
            const int mx=*max_element(nums.begin(),nums.end()),mod=1e9+7;
            vector<int> count(mx+1,0),pre(mx+1,0);
            for(int i:nums)
                count[i]++;

           for(int i=1;i<=mx;i++)
               pre[i]=pre[i-1]+count[i];

           int res=0;
           for(int y=1;y<=mx;y++)
           {
                for(int d=1;d*y<=mx;d++)
                    res=(res+(long long)count[y]*d*(pre[min((d+1)*y-1,mx)]-pre[d*y-1]))%mod;
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
