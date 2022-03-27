/*
   Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

   answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
   answer[1] is a list of all distinct integers in nums2 which are not present in nums1.

   Note that the integers in the lists may be returned in any order.



   Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].

Example 2:

Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].



Constraints:

1 <= nums1.length, nums2.length <= 1000
-1000 <= nums1[i], nums2[i] <= 1000

*/

#define c11
#include"head.h"
class Solution {
    public:
        vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> h1,h2;
        const int n1=nums1.size(),n2=nums2.size();
        for(int i=0;i<n1;i++)
            h1[nums1[i]]++;
        for(int i=0;i<n2;i++)
            h2[nums2[i]]++;

        vector<vector<int>> res;
        vector<int> cur;
        for(unordered_map<int,int>::iterator it=h1.begin();it!=h1.end();it++)
            if(h2.count(it->first)==0)
                cur.push_back(it->first);

        res.push_back(cur),cur.clear();

        for(unordered_map<int,int>::iterator it=h2.begin();it!=h2.end();it++)
            if(h1.count(it->first)==0)
                cur.push_back(it->first);
        res.push_back(cur);

        return res;
        }
};


int main() 
{
    Solution s;
    vector<int> v1={1,2,3},v2={2,4,6};
    show(s.findDifference(v1,v2));
    v1.clear();v1={1,2,3,3};
    v2.clear();v2={1,1,2,2};
    show(s.findDifference(v1,v2));
    return 0;
}
