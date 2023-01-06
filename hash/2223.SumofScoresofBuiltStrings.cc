/*
   You are building a string s of length n one character at a time, prepending each new character to the front of the string. The strings are labeled from 1 to n, where the string with length i is labeled si.

   For example, for s = "abaca", s1 == "a", s2 == "ca", s3 == "aca", etc.

   The score of si is the length of the longest common prefix between si and sn (Note that s == sn).

   Given the final string s, return the sum of the score of every si.

    

   Example 1:

Input: s = "babab"
Output: 9
Explanation:
For s1 == "b", the longest common prefix is "b" which has a score of 1.
For s2 == "ab", there is no common prefix so the score is 0.
For s3 == "bab", the longest common prefix is "bab" which has a score of 3.
For s4 == "abab", there is no common prefix so the score is 0.
For s5 == "babab", the longest common prefix is "babab" which has a score of 5.
The sum of the scores is 1 + 0 + 3 + 0 + 5 = 9, so we return 9.

Example 2:

Input: s = "azbazbzaz"
Output: 14
Explanation:
For s2 == "az", the longest common prefix is "az" which has a score of 2.
For s6 == "azbzaz", the longest common prefix is "azb" which has a score of 3.
For s9 == "azbazbzaz", the longest common prefix is "azbazbzaz" which has a score of 9.
For all other si, the score is 0.
The sum of the scores is 2 + 3 + 9 = 14, so we return 14.

 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.

*/

#define c11
#include"head.h"
class Solution {
    public:
        typedef unsigned long long ll;
        long long sumScores(string s) {
            const  int n=s.size();
            vector<ll> p(n+1,0LL),h(n+1,0LL);

            p[0]=1,h[0]=0;
            for(int i=1;i<=n;i++)
            {
                h[i]=h[i-1]*31+s[i-1]-'a'+1;
                p[i]=p[i-1]*31;
            }

            ll res=0;
            for(int i=1;i<=n;i++)
            {
                int l=0,r=i;
                while(l<r)
                {
                    int m=(l+r+1)>>1;
                    if(check(p,h,m,n-i))
                        l=m;
                    else
                        r=m-1;
                }
                res+=l;
            }

            return res;
        }
        bool check(vector<ll> &p,vector<ll> &h,int len,int start)
        {
            //if(len==0) return false;
            if(len==0) return true;
            const int n=h.size();
            ll k1=h[1+len-1];
            ll k2=h[1+start+len-1]-h[1+start-1]*p[len];
            return  k1==k2;

        }
};


int main() 
{
    Solution s;
    cout<<s.sumScores("babab")<<endl;
    cout<<s.sumScores("azbazbzaz")<<endl;
    return 0;
}
