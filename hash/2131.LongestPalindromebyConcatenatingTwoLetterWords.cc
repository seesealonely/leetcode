/*
   You are given an array of strings words. Each element of words consists of two lowercase English letters.

   Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

   Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

   A palindrome is a string that reads the same forward and backward.



   Example 1:

Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.

Example 2:

Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.

Example 3:

Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".



Constraints:

1 <= words.length <= 105
words[i].length == 2
words[i] consists of lowercase English letters.

*/


#include"head.h"
class Solution {
    public:
        int longestPalindrome(vector<string>& words) {
            vector<vector<int> > h(26,vector<int>(26,0));

            for(int i=0;i<words.size();i++)
                h[words[i][0]-'a'][words[i][1]-'a']++;

            int res=0,odd=0;
            for(int i=0;i<26;i++)
            {
                    res+=h[i][i]-h[i][i]%2;
                    odd|=h[i][i]%2;
                    for(int j=i+1;j<26;j++)
                        res+=min(h[i][j],h[j][i])*2;
            }
            return (res+odd)*2;
        }
};


int main() 
{
    Solution s;
    vector<string> v={"lc","cl","gg"};
    cout<<s.longestPalindrome(v)<<endl;
    v.clear();v={"ab","ty","yt","lc","cl","ab"};
    cout<<s.longestPalindrome(v)<<endl;
    v.clear();v={"cc","ll","xx"};
    cout<<s.longestPalindrome(v)<<endl;
    return 0;
}
