/*
   You are given a string s. You can convert s to a
   palindrome
   by adding characters in front of it.

   Return the shortest palindrome you can find by performing this transformation.

    

   Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"

Example 2:

Input: s = "abcd"
Output: "dcbabcd"

 

Constraints:

0 <= s.length <= 5 * 104
s consists of lowercase English letters only.

*/


#include"head.h"
class Solution {
    public:
        string shortestPalindrome(string s) {
        const int n=s.size();
        string r=string(s.rbegin(),s.rend());
        string rs=s+"@"+r;

        vector<int> next(2*n+1,-1);
        for(int i=1,j=-1;i<=2*n;i++)
        {
            while(j!=-1&&rs[i]!=rs[j+1]) j=next[j];

            if(rs[j+1]==rs[i])
                j++;

            next[i]=j;
        }

        return r.substr(0,n-(next[2*n]+1))+s;
        }
};


int main() 
{
    Solution s;
    cout<<s.shortestPalindrome("aacecaaa")<<endl;
    cout<<s.shortestPalindrome("abcd")<<endl;
    return 0;
}
