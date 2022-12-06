/*
   The variance of a string is defined as the largest difference between the number of occurrences of any 2 characters present in the string. Note the two characters may or may not be the same.

   Given a string s consisting of lowercase English letters only, return the largest variance possible among all substrings of s.

   A substring is a contiguous sequence of characters within a string.



   Example 1:

Input: s = "aababbb"
Output: 3
Explanation:
All possible variances along with their respective substrings are listed below:
- Variance 0 for substrings "a", "aa", "ab", "abab", "aababb", "ba", "b", "bb", and "bbb".
- Variance 1 for substrings "aab", "aba", "abb", "aabab", "ababb", "aababbb", and "bab".
- Variance 2 for substrings "aaba", "ababbb", "abbb", and "babb".
- Variance 3 for substring "babbb".
Since the largest possible variance is 3, we return it.

Example 2:

Input: s = "abcde"
Output: 0
Explanation:
No letter occurs more than once in s, so the variance of every substring is 0.



Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.

*/


#include"head.h"
class Solution {
    public:
        int largestVariance(string s) {
        int n=s.size(),res=0;

        for(int x='a';x<='z';x++)
        {
            for(int y='a';y<='z';y++)
            {
                if(x==y)
                    continue;
                int sub=0,subWithb=INT_MIN;
                for(int i=0;i<n;i++)
                {
                    if(s[i]==x)
                    {
                        sub=max(sub,0)+1;
                        subWithb++;
                    }
                    else if(s[i]==y)
                    {
                        sub=max(sub,0)-1;
                        subWithb=sub;
                    }
                    res=max(res,subWithb);
                }
            }
        }
        return res;
        }
};


int main() 
{
    Solution s;
    cout<<s.largestVariance("aababbb")<<endl;
    cout<<s.largestVariance("abcde")<<endl;
    return 0;
}
