/*
   An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.

   Given an integer n, return the smallest numerically balanced number strictly greater than n.



   Example 1:

Input: n = 1
Output: 22
Explanation:
22 is numerically balanced since:
- The digit 2 occurs 2 times.
It is also the smallest numerically balanced number strictly greater than 1.

Example 2:

Input: n = 1000
Output: 1333
Explanation:
1333 is numerically balanced since:
- The digit 1 occurs 1 time.
- The digit 3 occurs 3 times.
It is also the smallest numerically balanced number strictly greater than 1000.
Note that 1022 cannot be the answer because 0 appeared more than 0 times.

Example 3:

Input: n = 3000
Output: 3133
Explanation:
3133 is numerically balanced since:
- The digit 1 occurs 1 time.
- The digit 3 occurs 3 times.
It is also the smallest numerically balanced number strictly greater than 3000.



Constraints:

0 <= n <= 106

*/


#include"head.h"
class Solution {
    public:
        int nextBeautifulNumber(int n) {
        if(n==0)
            return 1;
        int i=n+1;
        for(;i<1e7+1;i++)
            if(check(i))
                break;
        return i;
        }
        bool check(int n)
        {
            vector<int> hash(8,0);
            while(n)
            {
                if(n%10>7||n%10==0)
                    return false;
                ++hash[n%10];
                n/=10;
            }
            for(int i=1;i<=7;i++)
                if(hash[i]&&hash[i]!=i)
                    return false;
            return true;
        }
};


int main() 
{
    Solution s;
    cout<<s.nextBeautifulNumber(1)<<endl;
    cout<<s.nextBeautifulNumber(1000)<<endl;
    cout<<s.nextBeautifulNumber(3000)<<endl;
    return 0;
}
