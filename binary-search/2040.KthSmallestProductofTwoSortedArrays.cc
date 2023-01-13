/*
   Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based) smallest product of nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.

    

   Example 1:

Input: nums1 = [2,5], nums2 = [3,4], k = 2
Output: 8
Explanation: The 2 smallest products are:
- nums1[0] * nums2[0] = 2 * 3 = 6
- nums1[0] * nums2[1] = 2 * 4 = 8
The 2nd smallest product is 8.

Example 2:

Input: nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
Output: 0
Explanation: The 6 smallest products are:
- nums1[0] * nums2[1] = (-4) * 4 = -16
- nums1[0] * nums2[0] = (-4) * 2 = -8
- nums1[1] * nums2[1] = (-2) * 4 = -8
- nums1[1] * nums2[0] = (-2) * 2 = -4
- nums1[2] * nums2[0] = 0 * 2 = 0
- nums1[2] * nums2[1] = 0 * 4 = 0
The 6th smallest product is 0.

Example 3:

Input: nums1 = [-2,-1,0,1,2], nums2 = [-3,-1,2,4,5], k = 3
Output: -6
Explanation: The 3 smallest products are:
- nums1[0] * nums2[4] = (-2) * 5 = -10
- nums1[0] * nums2[3] = (-2) * 4 = -8
- nums1[4] * nums2[0] = 2 * (-3) = -6
The 3rd smallest product is -6.

 

Constraints:

1 <= nums1.length, nums2.length <= 5 * 104
-105 <= nums1[i], nums2[j] <= 105
1 <= k <= nums1.length * nums2.length
nums1 and nums2 are sorted.

*/


#include"head.h"
class Solution {
    public:
        typedef long long ll;
        long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
            const ll mx=1e10+1LL;
            vector<int> n2(nums2.rbegin(),nums2.rend());

            ll l=-mx,r=mx;
            while(l<r)
            {
                ll m=(l+r)>>1;
                if(check(nums1,nums2,n2,k,m))
                    r=m;
                else
                    l=m+1;
            }
            return l;
        }
        int calc(const vector<int> &nums,int cur,ll target)
        {
            int l=0,r=nums.size();
            while(l<r)
            {
                int m=(l+r)>>1;
                if(target<(ll)cur*nums[m])
                    r=m;
                else
                    l=m+1;
            }
            return l;
        }

        bool check(const vector<int> &nums1,const vector<int> &nums2,const vector<int> &n2,int k,ll target)
        {
            ll cnt=0;
            for(int i=0;i<nums1.size();i++)
            {
                int x=nums1[i];
                if(x>=0) cnt+=calc(nums2,x,target);
                else cnt+=calc(n2,x,target);

                if(cnt>=k)
                    return true;
            }
            return false;
        }
};


int main() 
{
    Solution s;
    vector<int> v1={2,5},v2={3,4};
    cout<<s.kthSmallestProduct(v1,v2,2)<<endl;
    v1.clear();v1={-4,-2,0,3};
    v2.clear();v2={2,4};
    cout<<s.kthSmallestProduct(v1,v2,6)<<endl;
    v1.clear();v1={-2,-1,0,1,2};
    v2.clear();v2={-3,-1,2,4,5};
    cout<<s.kthSmallestProduct(v1,v2,3)<<endl;
}
