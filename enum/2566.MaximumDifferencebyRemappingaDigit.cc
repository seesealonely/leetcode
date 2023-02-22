/*
   You are given an integer num. You know that Danny Mittal will sneakily remap one of the 10 possible digits (0 to 9) to another digit.

   Return the difference between the maximum and minimum values Danny can make by remapping exactly one digit in num.

Notes:

When Danny remaps a digit d1 to another digit d2, Danny replaces all occurrences of d1 in num with d2.
Danny can remap a digit to itself, in which case num does not change.
Danny can remap different digits for obtaining minimum and maximum values respectively.
The resulting number after remapping can contain leading zeroes.
We mentioned "Danny Mittal" to congratulate him on being in the top 10 in Weekly Contest 326.



Example 1:

Input: num = 11891
Output: 99009
Explanation:
To achieve the maximum value, Danny can remap the digit 1 to the digit 9 to yield 99899.
To achieve the minimum value, Danny can remap the digit 1 to the digit 0, yielding 890.
The difference between these two numbers is 99009.

Example 2:

Input: num = 90
Output: 99
Explanation:
The maximum value that can be returned by the function is 99 (if 0 is replaced by 9) and the minimum value that can be returned by the function is 0 (if 9 is replaced by 0).
Thus, we return 99.



Constraints:

1 <= num <= 108

*/


#include"head.h"
class Solution {
    public:
        int minMaxDifference(int num) {
        vector<int> s;

        while(num)
        {
            s.push_back(num%10);
            num/=10;
        }

        return getMax(s)-getMin(s);
        }
        void replace(vector<int> &s,int x,int y)
        {
            for(int i=0;i<s.size();i++)
                if(s[i]==x)
                    s[i]=y;
        }
        int getNum(const vector<int> &s)
        {
            int res=0;
            for(int i=s.size()-1;i>=0;i--)
                res=res*10+s[i];

            return res;
        }
        int getMax(vector<int> s)
        {
            int p=-1;
            for(int i=s.size()-1;i>=0;i--)
                if(s[i]!=9)
                {
                    p=i;
                    break;
                }
            if(p!=-1)
                replace(s,s[p],9);
            return getNum(s);
        }

        int getMin(vector<int> s)
        {
            replace(s,s.back(),0);
            return getNum(s);
        }
};


int main() 
{
    Solution s;
    cout<<s.minMaxDifference(11891)<<endl;
    cout<<s.minMaxDifference(90)<<endl;
    return 0;
}
