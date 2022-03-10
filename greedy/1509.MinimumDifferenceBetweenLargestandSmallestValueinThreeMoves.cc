/*
   You are given an integer array nums. In one move, you can choose one element of nums and change it by any value.

   Return the minimum difference between the largest and smallest value of nums after performing at most three moves.



   Example 1:

Input: nums = [5,3,2,4]
Output: 0
Explanation: Change the array [5,3,2,4] to [2,2,2,2].
The difference between the maximum and minimum is 2-2 = 0.

Example 2:

Input: nums = [1,5,0,10,14]
Output: 1
Explanation: Change the array [1,5,0,10,14] to [1,1,0,1,1].
The difference between the maximum and minimum is 1-0 = 1.



Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109

*/
#include"head.h"
class Solution {
    public:
        int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        const int n=nums.size();
        if(n<=4) return 0;
        int res=INT_MAX;
        for(int i=0;i<4;i++)
            res=min(res,nums[n-4+i]-nums[i]);

        return res;
        }
};
int main() 
{
    Solution s;
    vector<int> v={5,3,2,4};
    cout<<s.minDifference(v)<<endl;
    v.clear();v={1,5,0,10,14};
    cout<<s.minDifference(v)<<endl;
    return 0;
}
