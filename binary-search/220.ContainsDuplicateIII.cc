/*
   Given an integer array nums and two integers k and t, return true if there are two distinct indices i and j in the array such that abs(nums[i] - nums[j]) <= t and abs(i - j) <= k.



   Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true

Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true

Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false



Constraints:

1 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
0 <= k <= 104
0 <= t <= 231 - 1

*/

#define c11
#include"head.h"
class Solution {
    public:
        bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
            set<long> w;
            for(int i=0;i<nums.size();i++)
            {
                set<long>::iterator it=w.lower_bound((long)nums[i]-t);
                if(it!=w.end()&&*it<=(long)nums[i]+t)
                    return true;
                w.insert(nums[i]);
                if(i>=k) w.erase(nums[i-k]);
            }
            return false;
        }
};


int main() 
{
    Solution s;
    vector<int> v={1,2,3,1};
    cout<<s.containsNearbyAlmostDuplicate(v,3,0)<<endl;
    v.clear();v={1,0,1,1};
    cout<<s.containsNearbyAlmostDuplicate(v,1,2)<<endl;
    v.clear();v={1,5,9,1,5,9};
    cout<<s.containsNearbyAlmostDuplicate(v,2,3)<<endl;
    return 0;
}
