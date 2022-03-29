/*
   Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).



   Example 1:

Input: low = 3, high = 7
Output: 3
Explanation: The odd numbers between 3 and 7 are [3,5,7].

Example 2:

Input: low = 8, high = 10
Output: 1
Explanation: The odd numbers between 8 and 10 are [9].



Constraints:

0 <= low <= high <= 10^9
*/


#include"head.h"
class Solution {
    public:
        int countOdds(int low, int high) {
        return preSum(high)-preSum(low-1);
        }
        int preSum(int n)
        {
            return (n+1)>>1;
        }
};


int main() 
{
    Solution s;
    cout<<s.countOdds(3,7)<<endl;
    cout<<s.countOdds(8,10)<<endl;
    return 0;
}
