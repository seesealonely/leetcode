/*
   Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

   Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.



   Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4]
Output: 2
Explanation: The smallest element common to both arrays is 2, so we return 2.

Example 2:

Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
Output: 2
Explanation: There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is returned.



Constraints:

1 <= nums1.length, nums2.length <= 105
1 <= nums1[i], nums2[j] <= 109
Both nums1 and nums2 are sorted in non-decreasing order.

*/

#define c11
#include"head.h"
class Solution {
    public:
        int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> cnt;
        const int n1=nums1.size(),n2=nums2.size();
        for(int i=0;i<n1;i++)
            cnt[nums1[i]]++;

        for(int i=0;i<n2;i++)
            if(cnt.count(nums2[i]))
                return nums2[i];

        return -1;
        }
};


int main() 
{
    Solution s;
    vector<int> v1={1,2,3},v2={2,4};
    cout<<s.getCommon(v1,v2)<<endl;
    v1.clear();v1={1,2,3,6};
    v2.clear();v2={2,3,4,5};
    cout<<s.getCommon(v1,v2)<<endl;
    return 0;
}
