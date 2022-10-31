/*
   Given a non-negative integer num, return true if num can be expressed as the sum of any non-negative integer and its reverse, or false otherwise.



   Example 1:

Input: num = 443
Output: true
Explanation: 172 + 271 = 443 so we return true.

Example 2:

Input: num = 63
Output: false
Explanation: 63 cannot be expressed as the sum of a non-negative integer and its reverse so we return false.

Example 3:

Input: num = 181
Output: true
Explanation: 140 + 041 = 181 so we return true. Note that when a number is reversed, there may be leading zeros.



Constraints:

0 <= num <= 105

*/


#include"head.h"
class Solution {
    public:
        bool sumOfNumberAndReverse(int num) {
        for(int i=0;i<=num;i++)
        {
            int cur=i,rev=0;
            while(cur)
            {
                rev=rev*10+cur%10;
                cur/=10;
            }
            if(rev+i==num)
                return true;
        }

        return false;
        }
};


int main() 
{
    Solution s;
    cout<<s.sumOfNumberAndReverse(443)<<endl;
    cout<<s.sumOfNumberAndReverse(63)<<endl;
    cout<<s.sumOfNumberAndReverse(181)<<endl;
    return 0;
}
