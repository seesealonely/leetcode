/*
   A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

   Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.

    

   Example 1:

Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".

Example 2:

Input: s = "ababab"
Output: "abab"
Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.

 

Constraints:

1 <= s.length <= 105
s contains only lowercase English letters.

*/


#include"head.h"
class Solution {
    public:
        string longestPrefix(string s) {
        const int n=s.size();
        vector<int> next(n,-1);

        for(int i=1,j=-1;i<n;i++)
        {
            while(j!=-1&&s[j+1]!=s[i])
                j=next[j];

            j+=s[j+1]==s[i];

            next[i]=j;
        }

        return s.substr(0,next[n-1]+1);
        }
};


int main() 
{
    Solution s;
    cout<<s.longestPrefix("level")<<endl;
    cout<<s.longestPrefix("ababab")<<endl;
    cout<<s.longestPrefix("leetcodeleet")<<endl;
    cout<<s.longestPrefix("a")<<endl;
    return 0;
}
