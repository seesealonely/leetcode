/*
   You are given a string s of length n containing only four kinds of characters: 'Q', 'W', 'E', and 'R'.

   A string is said to be balanced if each of its characters appears n / 4 times where n is the length of the string.

   Return the minimum length of the substring that can be replaced with any other string of the same length to make s balanced. If s is already balanced, return 0.



   Example 1:

Input: s = "QWER"
Output: 0
Explanation: s is already balanced.

Example 2:

Input: s = "QQWE"
Output: 1
Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.

Example 3:

Input: s = "QQQW"
Output: 2
Explanation: We can replace the first "QQ" to "ER".



Constraints:

n == s.length
4 <= n <= 105
n is a multiple of 4.
s contains only 'Q', 'W', 'E', and 'R'.

*/

#define c11
#include"head.h"
class Solution {
    public:
        int balancedString(string s) {
            unordered_map<char,int> c;
            c['Q']=0,c['W']=1,c['E']=2,c['R']=3;

            int n=s.size();
            vector<int> sum(4,0),sub(4,0);
            for(int i=0;i<n;i++)
                sum[c[s[i]]]++;

            if(sum[0]==sum[1]&&sum[1]==sum[2]&&sum[2]==sum[3]&&sum[3]==sum[0])
                return 0;

            int res=n;
            for(int r=0,l=0;r<n;r++)
            {
                sub[c[s[r]]]++;
                while(l<=r&&check(sum,sub,n/4))
                {
                    res=min(res,r-l+1);
                    sub[c[s[l]]]--;
                    l++;
                }
            }
            return res;
        }
        bool check(vector<int> &sum,vector<int> &sub,int target)
        {
            for(int i=0;i<4;i++)
                if(sum[i]-sub[i]>target)
                    return false;

            return true;
        }
};


int main() 
{
    Solution s;
    cout<<s.balancedString("QWER")<<endl;
    cout<<s.balancedString("QQWE")<<endl;
    cout<<s.balancedString("QQQW")<<endl;
    cout<<s.balancedString("QQQQ")<<endl;
    cout<<s.balancedString("WQWRQQQW")<<endl;
    return 0;
}
