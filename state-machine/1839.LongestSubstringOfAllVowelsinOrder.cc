/*
   A string is considered beautiful if it satisfies the following conditions:

   Each of the 5 English vowels ('a', 'e', 'i', 'o', 'u') must appear at least once in it.
   The letters must be sorted in alphabetical order (i.e. all 'a's before 'e's, all 'e's before 'i's, etc.).

   For example, strings "aeiou" and "aaaaaaeiiiioou" are considered beautiful, but "uaeio", "aeoiu", and "aaaeeeooo" are not beautiful.

   Given a string word consisting of English vowels, return the length of the longest beautiful substring of word. If no such substring exists, return 0.

   A substring is a contiguous sequence of characters in a string.



   Example 1:

Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
Output: 13
Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.

Example 2:

Input: word = "aeeeiiiioooauuuaeiou"
Output: 5
Explanation: The longest beautiful substring in word is "aeiou" of length 5.

Example 3:

Input: word = "a"
Output: 0
Explanation: There is no beautiful substring, so return 0.



Constraints:

1 <= word.length <= 5 1839.LongestSubstringOfAllVowelsinOrder.cc head.h head.o lib.a l.sh 105
word consists of characters 'a', 'e', 'i', 'o', and 'u'.

*/
#define c11
#include"head.h"
class Solution {
    public:
        int longestBeautifulSubstring(string word) {
            unordered_set<string> tran={"xa","aa","ee","ii","oo","uu","ae","ei","io","ou"};
            string state="x";
            int res=0,cur=0;
            for(int i=0;i<word.size();i++)
            {
                string c=word.substr(i,1);
                if(tran.count(state+c))
                {
                    if(state!="a"&&c=="a")
                    {
                        cur=1;
                    }
                    else
                        cur++;
                    if(c=="u")
                        res=max(res,cur);
                    state=c;
                }
                else
                    state=(c=="a"?c:"x"),cur=(c=="a"?1:0);
            }
            return res;
        }
};
int main() 
{
    Solution s;
    cout<<s.longestBeautifulSubstring("aeiaaioaaaaeiiiiouuuooaauuaeiu")<<endl;
    cout<<s.longestBeautifulSubstring("aeeeiiiioooauuuaeiou")<<endl;
    cout<<s.longestBeautifulSubstring("a")<<endl;
    return 0;
}
