/*
   You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.

   Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.

    

   Example 1:

Input: s = "aabaaaacaabc", k = 2
Output: 8
Explanation:
Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
A total of 3 + 5 = 8 minutes is needed.
It can be proven that 8 is the minimum number of minutes needed.

Example 2:

Input: s = "a", k = 1
Output: -1
Explanation: It is not possible to take one 'b' or 'c' so return -1.

 

Constraints:

1 <= s.length <= 105
s consists of only the letters 'a', 'b', and 'c'.
0 <= k <= s.length

*/


#include"head.h"
class Solution {
    public:
        int takeCharacters(string s, int k) {
        const int n=s.size();

        vector<vector<int>> suf(n+1,vector<int> (3,0));
        for(int i=n-1;i>=0;i--)
        {
            suf[i]=suf[i+1];
            suf[i][s[i]-'a']++;
        }

        int res=n+1;
        vector<int> pre(3,0);
        for(int i=0;i<=n;i++)
        {
            int l=i-1,r=n;
            while(l<r)
            {
                int m=(l+r+1)>>1;
                if(check(m,pre,suf,k))
                    l=m;
                else
                    r=m-1;
            }

            if(l!=i-1)
                res=min(res,i+n-l);

            if(i<n)
                pre[s[i]-'a']++;
        }

        return res==n+1?-1:res;
        }
        bool check(int s,const vector<int> &pre,const vector<vector<int>> &suf,int k)
        {
            for(int i=0;i<3;i++)
                if(pre[i]+suf[s][i]<k)
                    return false;
            return true;
        }
};


int main() 
{
    Solution s;
    cout<<s.takeCharacters("aabaaaacaabc",2)<<endl;
    cout<<s.takeCharacters("a",1)<<endl;
    return 0;
}
