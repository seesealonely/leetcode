/*
   Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

   A pair (i, j) is fair if:

   0 <= i < j < n, and
   lower <= nums[i] + nums[j] <= upper



   Example 1:

Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).

Example 2:

Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).



Constraints:

1 <= nums.length <= 105
nums.length == n
-109 <= nums[i] <= 109
-109 <= lower <= upper <= 109

*/


#include"head.h"
class Solution {
    public:
        typedef long long ll;
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            const int n=nums.size();

            sort(nums.begin(),nums.end());

            ll res=0;
            int l=n-1,r=n-1;
            for(int i=0;i<n;i++)
            {
                while(l>=0&&lower<=nums[i]+nums[l])
                    l--;

                while(r>=0&&upper<nums[i]+nums[r])
                    r--;

                res+=r-l;
                if(lower<=2*nums[i]&&2*nums[i]<=upper)
                    res--;
            }

            return res/2;
        }
};


int main() 
{
    Solution s;
    vector<int> v={0,1,7,4,4,5};
    cout<<s.countFairPairs(v,3,6)<<endl;
    v.clear();v={1,7,9,2,5};
    cout<<s.countFairPairs(v,11,11)<<endl;
    return 0;
}
