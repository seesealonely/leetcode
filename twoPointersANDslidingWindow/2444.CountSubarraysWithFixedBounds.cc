/*
   You are given an integer array nums and two integers minK and maxK.

   A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

   The minimum value in the subarray is equal to minK.
   The maximum value in the subarray is equal to maxK.

   Return the number of fixed-bound subarrays.

   A subarray is a contiguous part of an array.

    

   Example 1:

Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].

Example 2:

Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.

 

Constraints:

2 <= nums.length <= 105
1 <= nums[i], minK, maxK <= 106

*/


#include"head.h"
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        const int n=nums.size();
        int minIdx=-1,maxIdx=-1,startIdx=0;
        long long res=0LL;
        for(int i=0;i<n;i++)
        {
            
            if(nums[i]<minK||nums[i]>maxK)
            {
                minIdx=-1,maxIdx=-1,startIdx=i+1;
                continue;
            }
            if(nums[i]==minK) minIdx=i;
            if(nums[i]==maxK) maxIdx=i;

            res+=max(0,min(minIdx,maxIdx)-startIdx+1);
        }

        return res;
        }
};


int main() 
{
    Solution s;
    vector<int> v={1,3,5,2,7,5};
    cout<<s.countSubarrays(v,1,5)<<endl;
    v.clear();v={1,1,1,1};
    cout<<s.countSubarrays(v,1,1)<<endl;
    return 0;
}
