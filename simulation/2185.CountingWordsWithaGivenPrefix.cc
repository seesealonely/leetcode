/*
   You are given an array of strings words and a string pref.

   Return the number of strings in words that contain pref as a prefix.

   A prefix of a string s is any leading contiguous substring of s.



   Example 1:

Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".

Example 2:

Input: words = ["leetcode","win","loops","success"], pref = "code"
Output: 0
Explanation: There are no strings that contain "code" as a prefix.



Constraints:

1 <= words.length <= 100
1 <= words[i].length, pref.length <= 100
words[i] and pref consist of lowercase English letters.

*/
#include"head.h"
class Solution {
    public:
        int prefixCount(vector<string>& words, string pref) {
            int m=pref.size(),res=0;
            for(int i=0;i<words.size();i++)
            {
                if(words[i].substr(0,m)==pref)
                    res++;
            }
            return res;
        }
};
int main() 
{
    Solution s;
    vector<string> v={"pay","attention","practice","attend"};
    cout<<s.prefixCount(v,"at")<<endl;
    v.clear();v={"leetcode","win","loops","success"};
    cout<<s.prefixCount(v,"code")<<endl;
    return 0;
}
