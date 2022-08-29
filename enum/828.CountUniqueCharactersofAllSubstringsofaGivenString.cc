/*
   Let's define a function countUniqueChars(s) that returns the number of unique characters on s.

   For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.

   Given a string s, return the sum of countUniqueChars(t) where t is a substring of s. The test cases are generated such that the answer fits in a 32-bit integer.

   Notice that some substrings can be repeated so in this case you have to count the repeated ones too.



   Example 1:

Input: s = "ABC"
Output: 10
Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
Every substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10

Example 2:

Input: s = "ABA"
Output: 8
Explanation: The same as example 1, except countUniqueChars("ABA") = 1.

Example 3:

Input: s = "LEETCODE"
Output: 92



Constraints:

1 <= s.length <= 105
s consists of uppercase English letters only.

*/


#include"head.h"
class Solution {
    public:
        int uniqueLetterString(string s) {
        const int n=s.size(),mod=1e9+7;
        vector<int> left(n,-1),right(n,n);

        vector<int> idx(26,-1);
        for(int i=0;i<n;i++)
        {
            left[i]=idx[s[i]-'A'];
            idx[s[i]-'A']=i;
        }

        idx=vector<int>(26,n);
        for(int i=n-1;i>=0;i--)
        {
            right[i]=idx[s[i]-'A'];
            idx[s[i]-'A']=i;
        }

        int res=0;
        for(int i=0;i<n;i++)
            res=(res+(long long)(i-left[i])*(right[i]-i))%mod;

        return res;
        }
};


int main() 
{
    Solution s;
    cout<<s.uniqueLetterString("ABC")<<endl;
    cout<<s.uniqueLetterString("ABA")<<endl;
    return 0;
}
