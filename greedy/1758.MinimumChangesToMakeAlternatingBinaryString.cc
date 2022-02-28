/*
   You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.

   The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.

   Return the minimum number of operations needed to make s alternating.



   Example 1:

Input: s = "0100"
Output: 1
Explanation: If you change the last character to '1', s will be "0101", which is alternating.

Example 2:

Input: s = "10"
Output: 0
Explanation: s is already alternating.

Example 3:

Input: s = "1111"
Output: 2
Explanation: You need two operations to reach "0101" or "1010".



Constraints:

1 <= s.length <= 104
s[i] is either '0' or '1'.

*/
#include"head.h"
class Solution {
    public:
        int minOperations(string s) {
        int mode0=0,mode1=1; //mode0 010101...
                            //mode1 101010...
        int cnt0=0,cnt1=0;
        for(int i=0;i<s.size();i++)
        {
            cnt0+=(mode0==s[i]-'0'?0:1);
            cnt1+=(mode1==s[i]-'0'?0:1);
            mode0^=1;mode1^=1;
        }
        return min(cnt0,cnt1);
        }
};
int main() 
{
    Solution s;
    cout<<s.minOperations("0100")<<endl;
    cout<<s.minOperations("10")<<endl;
    cout<<s.minOperations("1111")<<endl;
    return 0;
}
