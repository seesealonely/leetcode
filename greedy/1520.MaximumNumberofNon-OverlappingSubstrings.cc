/*
   Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that meet the following conditions:

   The substrings do not overlap, that is for any two substrings s[i..j] and s[x..y], either j < x or i > y is true.
   A substring that contains a certain character c must also contain all occurrences of c.

   Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings, return the one with minimum total length. It can be shown that there exists a unique solution of minimum total length.

   Notice that you can return the substrings in any order.



   Example 1:

Input: s = "adefaddaccc"
Output: e
Explanation: The following are all the possible substrings that meet the conditions:
[
"adefaddaccc"
"adefadda",
"ef",
"e",
"f",
"ccc",
]
If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose e which gives us 3 substrings. No other solution of the same number of substrings exist.

Example 2:

Input: s = "abbaccd"
Output: ["d","bb","cc"]
Explanation: Notice that while the set of substrings ["d","abba","cc"] also has length 3, it's considered incorrect since it has larger total length.



Constraints:

1 <= s.length <= 105
s contains only lowercase English letters.

*/


#include"head.h"
class Solution {
    public:
        vector<string> maxNumOfSubstrings(string s) {
        vector<int> l(26,INT_MAX),r(26,INT_MIN);

        for(int i=0;i<s.size();i++)
        {
            int index=s[i]-'a';
            l[index]=min(l[index],i);
            r[index]=max(r[index],i);
        }

        vector<string> res;
        int ri=-1;
        for(int i=0;i<s.size();i++)
        {
            if(i!=l[s[i]-'a'])
                continue;
            int rbound=getRight(s,i,l,r);
            if(rbound!=-1)
            {
                if(i>ri)
                    res.push_back("");
                    ri=rbound;
                    res.back()=s.substr(i,ri-i+1);
            }
        }

        return res;
        }
        int getRight(string &s,int j,vector<int>&l,vector<int>&r)
        {
            int ri=r[s[j]-'a'];
            for(int i=j+1;i<ri;i++)
            {
                if(l[s[i]-'a']<j) return -1;
                ri=max(ri,r[s[i]-'a']);
            }
            return ri;
        }
};


int main() 
{
    Solution s;
    show(s.maxNumOfSubstrings("adefaddaccc"));
    show(s.maxNumOfSubstrings("abbaccd"));
    return 0;
}
