/*
   You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. There exists another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once).

   Return the bitwise XOR of all integers in nums3.

    

   Example 1:

Input: nums1 = [2,1,3], nums2 = [10,2,5,0]
Output: 13
Explanation:
A possible nums3 array is [8,0,7,2,11,3,4,1,9,1,6,3].
The bitwise XOR of all these numbers is 13, so we return 13.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 0
Explanation:
All possible pairs of bitwise XORs are nums1[0] ^ nums2[0], nums1[0] ^ nums2[1], nums1[1] ^ nums2[0],
and nums1[1] ^ nums2[1].
Thus, one possible nums3 array is [2,5,1,6].
2 ^ 5 ^ 1 ^ 6 = 0, so we return 0.

 

Constraints:

1 <= nums1.length, nums2.length <= 105
0 <= nums1[i], nums2[j] <= 109

*/


#include"head.h"
class Solution {
    public:
        int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res=0;
        for(int i=21;i>=0;i--)
        {
            int cnt11=0,cnt01=nums1.size()&1;
            for(int j=0;j<nums1.size();j++)
                if(nums1[j]>>i&1)
                {
                    cnt11^=1;
                    cnt01^=1;
                }

            int cnt12=0,cnt02=nums2.size()&1;
            for(int j=0;j<nums2.size();j++)
                if(nums2[j]>>i&1)
                {
                    cnt12^=1;
                    cnt02^=1;
                }
            res|=((cnt11&cnt02)^(cnt01&cnt12))<<i;
        }
        
        return res;
        }
};


int main() 
{
    Solution s;
    vector<int> v1={2,1,3},v2={10,2,5,0};
    cout<<s.xorAllNums(v1,v2)<<endl;
    v1.clear();v1={1,2};
    v2.clear();v2={3,4};
    cout<<s.xorAllNums(v1,v2)<<endl;
    return 0;
}
