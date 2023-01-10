/*
   You are given two 0-indexed strings word1 and word2.

   A move consists of choosing two indices i and j such that 0 <= i < word1.length and 0 <= j < word2.length and swapping word1[i] with word2[j].

   Return true if it is possible to get the number of distinct characters in word1 and word2 to be equal with exactly one move. Return false otherwise.

    

   Example 1:

Input: word1 = "ac", word2 = "b"
Output: false
Explanation: Any pair of swaps would yield two distinct characters in the first string, and one in the second string.

Example 2:

Input: word1 = "abcc", word2 = "aab"
Output: true
Explanation: We swap index 2 of the first string with index 0 of the second string. The resulting strings are word1 = "abac" and word2 = "cab", which both have 3 distinct characters.

Example 3:

Input: word1 = "abcde", word2 = "fghij"
Output: true
Explanation: Both resulting strings will have 5 distinct characters, regardless of which indices we swap.

 

Constraints:

1 <= word1.length, word2.length <= 105
word1 and word2 consist of only lowercase English letters.

*/

#define c11
#include"head.h"
class Solution {
    public:
        bool isItPossible(string word1, string word2) {
        unordered_map<char,int> m1,m2;
        unordered_set<char> s1,s2;
        for(int i=0;i<word1.size();i++)
            m1[word1[i]]++,s1.insert(word1[i]);
        for(int i=0;i<word2.size();i++)
            m2[word2[i]]++,s2.insert(word2[i]);

        int l1=s1.size(),l2=s2.size();
        if(abs(l1-l2)>2) return false;

        for(int i='a';i<='z';i++)
        {
            if(m1[i]==0) continue;
            for(int j='a';j<='z';j++)
            {
                if(m2[j]==0) continue;
                l1=s1.size(),l2=s2.size();
                if(m1[i]==1&&i!=j)
                    l1--;
                if(m2[i]==0)
                    l2++;
                if(m2[j]==1&&i!=j) 
                    l2--;
                if(m1[j]==0)
                    l1++;

                if(l1==l2)
                    return true;
            }
        }
        return false;
        }
};


int main() 
{
    Solution s;
    cout<<s.isItPossible("ac","b")<<endl;
    cout<<s.isItPossible("abcc","abb")<<endl;
    cout<<s.isItPossible("abcde","fghij")<<endl;
    return 0;
}
