/*
   You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.

   Create the maximum number of length k <= m + n from digits of the two numbers. The relative order of the digits from the same array must be preserved.

   Return an array of the k digits representing the answer.



   Example 1:

Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
Output: [9,8,6,5,3]

Example 2:

Input: nums1 = [6,7], nums2 = [6,0,4], k = 5
Output: [6,7,6,0,4]

Example 3:

Input: nums1 = [3,9], nums2 = [8,9], k = 3
Output: [9,8,9]



Constraints:

m == nums1.length
n == nums2.length
1 <= m, n <= 500
0 <= nums1[i], nums2[i] <= 9
1 <= k <= m + n

*/


#include"head.h"
class Solution {
    public:
        vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        const int n1=nums1.size(),n2=nums2.size();
        vector<int> res(k,0);
        for(int i=0;i<=min(k,n1);i++)
        {
            if(k-i>n2) continue;
            vector<int> cur=merge(select(nums1,i),select(nums2,k-i));
            res=max(res,cur);
        }

        return res;
        }
        vector<int> select(const vector<int> &nums,int k)
        {
            vector<int> res;
            const int n=nums.size();
            for(int i=0;i<n;i++)
            {
                while(!res.empty()&&res.back()<nums[i]&&res.size()+n-i>k)
                    res.pop_back();
                if(res.size()<k) res.push_back(nums[i]);
            }
            return res;
        }
        vector<int> merge(const vector<int> &a,const vector<int> &b)
        {
            vector<int> res;
            deque<int> qa(a.begin(),a.end()),qb(b.begin(),b.end());
            while(!qa.empty()&&!qb.empty())
            {
                if(qa>qb)
                    res.push_back(qa.front()),qa.pop_front();
                else
                    res.push_back(qb.front()),qb.pop_front();
            }
            while(!qa.empty()) res.push_back(qa.front()),qa.pop_front();
            while(!qb.empty()) res.push_back(qb.front()),qb.pop_front();
            return res;
        }
};


int main() 
{
    Solution s;
    vector<int> v1={3,4,6,5},v2={9,1,2,5,8,3};
    show(s.maxNumber(v1,v2,5));
    v1.clear();v1={6,7};
    v2.clear();v2={6,0,4};
    show(s.maxNumber(v1,v2,5));
    v1.clear();v1={3,9};
    v2.clear();v2={8,9};
    show(s.maxNumber(v1,v2,3));
    return 0;
}
