/*
   You are given a positive integer n.

   Continuously replace n with the sum of its prime factors.

   Note that if a prime factor divides n multiple times, it should be included in the sum as many times as it divides n.

   Return the smallest value n will take on.

    

   Example 1:

Input: n = 15
Output: 5
Explanation: Initially, n = 15.
15 = 3 * 5, so replace n with 3 + 5 = 8.
8 = 2 * 2 * 2, so replace n with 2 + 2 + 2 = 6.
6 = 2 * 3, so replace n with 2 + 3 = 5.
5 is the smallest value n will take on.

Example 2:

Input: n = 3
Output: 3
Explanation: Initially, n = 3.
3 is the smallest value n will take on.

 

Constraints:

2 <= n <= 105

*/


#include"head.h"
class Solution {
    public:
        int smallestValue(int n) {

            while(true)
            {
                int sum=0,target=n;
                for(int i=2;i*i<=target;i++)
                    while(target%i==0)
                    {
                        sum+=i;
                        target/=i;
                    }

                if(target>1)
                    sum+=target;

                if(n==sum)
                    return sum;

                n=sum;
            }

            return -1;
        }
};


int main() 
{
    Solution s;
    cout<<s.smallestValue(15)<<endl;
    cout<<s.smallestValue(3)<<endl;
    cout<<s.smallestValue(12)<<endl;
    return 0;
}
