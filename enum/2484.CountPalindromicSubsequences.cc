/*
   Given a string of digits s, return the number of palindromic subsequences of s having length 5. Since the answer may be very large, return it modulo 109 + 7.

Note:

A string is palindromic if it reads the same forward and backward.
A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

 

Example 1:

Input: s = "103301"
Output: 2
Explanation:
There are 6 possible subsequences of length 5: "10330","10331","10301","10301","13301","03301".
Two of them (both equal to "10301") are palindromic.

Example 2:

Input: s = "0000000"
Output: 21
Explanation: All 21 subsequences are "00000", which is palindromic.

Example 3:

Input: s = "9999900000"
Output: 2
Explanation: The only two palindromic subsequences are "99999" and "00000".

 

Constraints:

1 <= s.length <= 104
s consists of digits.

*/


#include"head.h"
class Solution {
    public:
        static const int N=10001;
        int countPalindromes(string s) {
        typedef long long ll;
        const int n=s.size(),mod=1e9+7;

        int digit[10];
        memset(digit,0,sizeof(digit));
        memset(l[0],0,sizeof(l[0]));
        for(int i=1;i<=n;i++)
        {
            int d=s[i-1]-'0';
            memcpy(l[i],l[i-1],sizeof(l[i]));
            for(int j=0;j<10;j++)
                l[i][d][j]+=digit[j];
            digit[d]++;
        }

        memset(digit,0,sizeof(digit));
        memset(r[n+1],0,sizeof(r[n]));
        for(int i=n;i>=1;i--)
        {
            int d=s[i-1]-'0';
            memcpy(r[i],r[i+1],sizeof(r[i]));
            for(int j=0;j<10;j++)
                r[i][d][j]+=digit[j];
            digit[d]++;
        }

        int res=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j<10;j++)
                for(int k=0;k<10;k++)
                    res=(res+(ll)l[i-1][j][k]*r[i+1][j][k])%mod;

        return res;
        }
    private:
        int l[N][10][10],r[N][10][10];
};


int main() 
{
    Solution s;
    cout<<s.countPalindromes("103301")<<endl;
    cout<<s.countPalindromes("0000000")<<endl;
    cout<<s.countPalindromes("9999900000")<<endl;
    return 0;
}
