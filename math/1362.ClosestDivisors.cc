/*
   Given an integer num, find the closest two integers in absolute difference whose product equals num + 1 or num + 2.

   Return the two integers in any order.



   Example 1:

Input: num = 8
Output: [3,3]
Explanation: For num + 1 = 9, the closest divisors are 3 & 3, for num + 2 = 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.

Example 2:

Input: num = 123
Output: [5,25]

Example 3:

Input: num = 999
Output: [40,25]



Constraints:

1 <= num <= 10^9

Given an integer num, find the closest two integers in absolute difference whose product equals num + 1 or num + 2.

Return the two integers in any order.



Example 1:

Input: num = 8
Output: [3,3]
Explanation: For num + 1 = 9, the closest divisors are 3 & 3, for num + 2 = 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.

Example 2:

Input: num = 123
Output: [5,25]

Example 3:

Input: num = 999
Output: [40,25]



Constraints:

1 <= num <= 10^9

*/
#include"head.h"
class Solution {
    public:
        vector<int> closestDivisors(int num) {
        vector<int> add1=count(num+1);
        vector<int> add2=count(num+2);

        return abs(add1[0]-add1[1])<abs(add2[0]-add2[1])?add1:add2;
        }
        vector<int> count(int n)
        {
            for(int i=sqrt(n);i>0;i--)
                if(n%i==0)
                    return {i,n/i};
        }
};
int main() 
{
    Solution s;
    show(s.closestDivisors(8));
    show(s.closestDivisors(123));
    show(s.closestDivisors(999));
    return 0;
}
