/*
   Given an integer array nums and an integer k, return the number of good subarrays of nums.

   A subarray arr is good if it there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].

   A subarray is a contiguous non-empty sequence of elements within an array.

    

   Example 1:

Input: nums = [1,1,1,1,1], k = 10
Output: 1
Explanation: The only good subarray is the array nums itself.

Example 2:

Input: nums = [3,1,4,3,2,2,4], k = 2
Output: 4
Explanation: There are 4 different good subarrays:
- [3,1,4,3,2,2] that has 2 pairs.
- [3,1,4,3,2,2,4] that has 3 pairs.
- [1,4,3,2,2,4] that has 2 pairs.
- [4,3,2,2,4] that has 2 pairs.

 

Constraints:

1 <= nums.length <= 105
1 <= nums[i], k <= 109

*/

#define c11
#include"head.h"
class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            long long res=0;

            unordered_map<int,int> cnt;
            int l=0,pairs=0,n=nums.size();
            for(int r=0;r<n;r++)
            {
                pairs+=cnt[nums[r]]++;
                while(pairs-cnt[nums[l]]+1>=k)
                    pairs-=--cnt[nums[l++]];
                if(pairs>=k) res+=l+1;
            }

            return res;
        }
};


int main() 
{
    Solution s;
    vector<int> v={1,1,1,1,1};
    cout<<s.countGood(v,10)<<endl;
    v.clear();v={3,1,4,3,2,2,4};
    cout<<s.countGood(v,2)<<endl;
    return 0;
}
