/*
   Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

   Find the leftmost occurrence of the substring part and remove it from s.

   Return s after removing all occurrences of part.

   A substring is a contiguous sequence of characters in a string.

    

   Example 1:

Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".

Example 2:

Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation: The following operations are done:
- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".

 

Constraints:

1 <= s.length <= 1000
1 <= part.length <= 1000
s​​​​​​ and part consists of lowercase English letters.

*/


#include"head.h"
class Solution {
    public:
        string removeOccurrences(string s, string part) {
        const int p=part.size();
        vector<int> next(p);

        next[0]=-1;
        for(int i=1,j=-1;i<p;i++)
        {
            while(j>-1&&part[i]!=part[j+1])
                j=next[j];

            if(part[i]==part[j+1])
                j++;

            next[i]=j;
        }
        while(true)
        {
            int n=s.size(),pos=-1;

            for(int i=0,j=-1;i<n;i++)
            {
                while(j>-1&&s[i]!=part[j+1])
                    j=next[j];

                if(s[i]==part[j+1])
                    j++;

                if(j==p-1)
                {
                    pos=i-p+1;
                    break;
                }
            }
            if(pos==-1)
                return s;

            s=s.substr(0,pos)+s.substr(pos+p);
        }

        return s;
        }
};


int main() 
{
    Solution s;
    cout<<s.removeOccurrences("daabcbaabcbc","abc")<<endl;
    cout<<s.removeOccurrences("axxxxyyyyb","xy")<<endl;
    return 0;
}
