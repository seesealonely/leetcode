/*
   Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

   Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

   A subarray is defined as a contiguous block of elements in the array.



   Example 1:

Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.

Example 2:

Input: nums = [6,3,5,2], p = 9
Output: 2
Explanation: We cannot remove a single element to get a sum divisible by 9. The best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.

Example 3:

Input: nums = [1,2,3], p = 3
Output: 0
Explanation: Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.



Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= p <= 109

*/

#define c11
#include"head.h"
class Solution {
    public:
        int minSubarray(vector<int>& nums, int p) {
            typedef long long ll;
            ll sum=accumulate(nums.begin(),nums.end(),0LL);
            if(sum<p) return -1;
            int mod=sum%p;
            if(!mod) return 0;

            unordered_map<int,int> h;
            int res=INT_MAX;
            h[0]=-1;
            ll s=0;
            for(int i=0,cp=0;i<nums.size();i++)
            {
                s+=nums[i];
                h[s%p]=i;
                cp=(s%p+p-mod)%p; 
                if(h.count(cp))
                    res=min(res,i-h[cp]);
            }
            return res==nums.size()?-1:res;
        }
};


int main() 
{
    Solution s;
    vector<int> v={3,1,4,2};
    cout<<s.minSubarray(v,6)<<endl;
    v.clear();v={6,3,5,2};
    cout<<s.minSubarray(v,9)<<endl;
    v.clear();v={1,2,3};
    cout<<s.minSubarray(v,3)<<endl;
    v.clear();v={1,2,3};
    cout<<s.minSubarray(v,7)<<endl;
    return 0;
}
