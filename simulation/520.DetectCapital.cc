/*
   We define the usage of capitals in a word to be right when one of the following cases holds:

   All letters in this word are capitals, like "USA".
   All letters in this word are not capitals, like "leetcode".
   Only the first letter in this word is capital, like "Google".

   Given a string word, return true if the usage of capitals in it is right.



   Example 1:

Input: word = "USA"
Output: true

Example 2:

Input: word = "FlaG"
Output: false



Constraints:

1 <= word.length <= 100
word consists of lowercase and uppercase English letters.

*/
#include"head.h"
class Solution {
    public:
        bool detectCapitalUse(string word) {
        int cnt=0;
        for(int i=0;i<word.size();i++)
            if(word[i]<='Z')
                cnt++;
        return cnt==0||cnt==word.size()||word[0]<='Z'&&cnt==1;
        }
};
int main() 
{
    Solution s;
    cout<<s.detectCapitalUse("USA")<<endl;
    cout<<s.detectCapitalUse("FlaG")<<endl;
    return 0;
}
