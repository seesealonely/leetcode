/*
   Given an integer array nums and an integer k, return the number of subarrays of nums where the least common multiple of the subarray's elements is k.

   A subarray is a contiguous non-empty sequence of elements within an array.

   The least common multiple of an array is the smallest positive integer that is divisible by all the array elements.



   Example 1:

Input: nums = [3,6,2,7,1], k = 6
Output: 4
Explanation: The subarrays of nums where 6 is the least common multiple of all the subarray's elements are:
- [3,6,2,7,1]
- [3,6,2,7,1]
- [3,6,2,7,1]
- [3,6,2,7,1]

Example 2:

Input: nums = [3], k = 2
Output: 0
Explanation: There are no subarrays of nums where 2 is the least common multiple of all the subarray's elements.



Constraints:

1 <= nums.length <= 1000
1 <= nums[i], k <= 1000

*/


#include"head.h"
class Solution {
    public:
        int subarrayLCM(vector<int>& nums, int k) {
            const int n=nums.size();
            int res=0;
            for(int i=0;i<n;i++)
            {
                int lcm=1;
                for(int j=i;j>=0;j--)
                {
                    lcm=lcm/__gcd(lcm,nums[j])*nums[j];
                if(lcm==k)
                    res++;
                if(lcm>k)
                    break;
                }
            }

            return res;
        }
};


int main() 
{
    Solution s;
    vector<int> v={3,6,2,7,1};
    cout<<s.subarrayLCM(v,6)<<endl;
    v.clear();v={3};
    cout<<s.subarrayLCM(v,2)<<endl;
    return 0;
}
