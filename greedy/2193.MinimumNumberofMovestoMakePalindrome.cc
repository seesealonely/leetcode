/*
   You are given a string s consisting only of lowercase English letters.

   In one move, you can select any two adjacent characters of s and swap them.

   Return the minimum number of moves needed to make s a palindrome.

   Note that the input will be generated such that s can always be converted to a palindrome.



   Example 1:

Input: s = "aabb"
Output: 2
Explanation:
We can obtain two palindromes from s, "abba" and "baab".
- We can obtain "abba" from s in 2 moves: "aabb" -> "abab" -> "abba".
- We can obtain "baab" from s in 2 moves: "aabb" -> "abab" -> "baab".
Thus, the minimum number of moves needed to make s a palindrome is 2.

Example 2:

Input: s = "letelt"
Output: 2
Explanation:
One of the palindromes we can obtain from s in 2 moves is "lettel".
One of the ways we can obtain it is "letelt" -> "letetl" -> "lettel".
Other palindromes such as "tleelt" can also be obtained in 2 moves.
It can be shown that it is not possible to obtain a palindrome in less than 2 moves.



Constraints:

1 <= s.length <= 2000
s consists only of lowercase English letters.
s can be converted to a palindrome using a finite number of moves.

*/


#include"head.h"
class Solution {
    public:
        int minMovesToMakePalindrome(string s) {
            int res=0;
            solve(s,res);
            return res;
        }
        void solve(string &s,int &res)
        {
            if(s.empty()) return ;
            int n=s.size(),i=n-1;
            for(;i>=0;i--)
                if(s[i]==s[0])
                    break; 
            if(i==0)
                res+=n/2,s=s.substr(1);
            else
                res+=n-1-i,s=s.substr(1,i-1)+s.substr(i+1);
            solve(s,res);
        }
};


int main() 
{
    Solution s;
    cout<<s.minMovesToMakePalindrome("aabb")<<endl;
    cout<<s.minMovesToMakePalindrome("letelt")<<endl;
    return 0;
}
