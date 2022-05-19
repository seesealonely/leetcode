/*
   You are given a string s. An awesome substring is a non-empty substring of s such that we can make any number of swaps in order to make it a palindrome.

   Return the length of the maximum length awesome substring of s.



   Example 1:

Input: s = "3242415"
Output: 5
Explanation: "24241" is the longest awesome substring, we can form the palindrome "24142" with some swaps.

Example 2:

Input: s = "12345678"
Output: 1

Example 3:

Input: s = "213123"
Output: 6
Explanation: "213123" is the longest awesome substring, we can form the palindrome "231132" with some swaps.



Constraints:

1 <= s.length <= 105
s consists only of digits.

*/

#define c11
#include"head.h"
class Solution {
    public:
        int longestAwesome(string s) {
            unordered_map<int,int> idx;
            idx[0]=-1;
            int n=s.size(),res=0,pre=0;

            for(int i=0;i<n;i++)
            {
                pre^=(1<<(s[i]-'0'));
                if(idx.count(pre))
                    res=max(res,i-idx[pre]);
                else
                    idx[pre]=i;
                for(int j=0;j<=9;j++)
                {
                    if(idx.count(pre^(1<<j)))
                            res=max(res,i-idx[pre^(1<<j)]);
                }
            }
            return res;
        }
};


int main() 
{
    Solution s;
    cout<<s.longestAwesome("3242415")<<endl;
    cout<<s.longestAwesome("12345678")<<endl;
    cout<<s.longestAwesome("213123")<<endl;
    cout<<s.longestAwesome("00")<<endl;
    return 0;
}
