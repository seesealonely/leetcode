/*
   You are given two strings a and b that consist of lowercase letters. In one operation, you can change any character in a or b to any lowercase letter.

   Your goal is to satisfy one of the following three conditions:

   Every letter in a is strictly less than every letter in b in the alphabet.
   Every letter in b is strictly less than every letter in a in the alphabet.
   Both a and b consist of only one distinct letter.

   Return the minimum number of operations needed to achieve your goal.



   Example 1:

Input: a = "aba", b = "caa"
Output: 2
Explanation: Consider the best way to make each condition true:
1) Change b to "ccc" in 2 operations, then every letter in a is less than every letter in b.
2) Change a to "bbb" and b to "aaa" in 3 operations, then every letter in b is less than every letter in a.
3) Change a to "aaa" and b to "aaa" in 2 operations, then a and b consist of one distinct letter.
The best way was done in 2 operations (either condition 1 or condition 3).

Example 2:

Input: a = "dabadd", b = "cda"
Output: 3
Explanation: The best way is to make condition 1 true by changing b to "eee".



Constraints:

1 <= a.length, b.length <= 105
a and b consist only of lowercase letters.

*/
#define c11
#include"head.h"
class Solution {
    public:
        int minCharacters(string a, string b) {
        unordered_map<char,int> cnta,cntb;
        const int m=a.size(),n=b.size();
        for(int i=0;i<m;i++)
            cnta[a[i]]++;
        for(int i=0;i<n;i++)
            cntb[b[i]]++;

        int suma=0,sumb=0,res=INT_MAX;
        for(char i='a';i<'z';i++)
        {
            res=min(res,m-cnta[i]+n-cntb[i]);

            if(i>'a')
            {
            res=min(res,m-suma+sumb);
            res=min(res,n-sumb+suma);
            }
            suma+=cnta[i];
            sumb+=cntb[i];
        }
        return res;
        }
};
int main() 
{
    Solution s;
    cout<<s.minCharacters("aba","caa")<<endl;
    cout<<s.minCharacters("dabadd","cda")<<endl;
    return 0;
}
