/*
   You are given a positive integer array nums.

   The element sum is the sum of all the elements in nums.
   The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.

   Return the absolute difference between the element sum and digit sum of nums.

   Note that the absolute difference between two integers x and y is defined as |x - y|.

    

   Example 1:

Input: nums = [1,15,6,3]
Output: 9
Explanation:
The element sum of nums is 1 + 15 + 6 + 3 = 25.
The digit sum of nums is 1 + 1 + 5 + 6 + 3 = 16.
The absolute difference between the element sum and digit sum is |25 - 16| = 9.

Example 2:

Input: nums = [1,2,3,4]
Output: 0
Explanation:
The element sum of nums is 1 + 2 + 3 + 4 = 10.
The digit sum of nums is 1 + 2 + 3 + 4 = 10.
The absolute difference between the element sum and digit sum is |10 - 10| = 0.

 

Constraints:

1 <= nums.length <= 2000
1 <= nums[i] <= 2000

*/


#include"head.h"
class Solution {
    public:
        int differenceOfSum(vector<int>& nums) {
        int s1=0,s2=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            s1+=nums[i];
            s2+=getAbs(nums[i]);
        }
        return abs(s1-s2);
        }
        int getAbs(int x)
        {
            int res=0;
            while(x)
            {
                res+=x%10;
                x/=10;
            }
            return res;
        }
};


int main() 
{
    Solution s;
    vector<int> v={1,15,6,3};
    cout<<s.differenceOfSum(v)<<endl;
    v.clear();v={1,2,3,4};
    cout<<s.differenceOfSum(v)<<endl;
    return 0;
}
