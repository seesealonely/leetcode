/*
   Given a binary string s, return the minimum number of character swaps to make it alternating, or -1 if it is impossible.

   The string is called alternating if no two adjacent characters are equal. For example, the strings "010" and "1010" are alternating, while the string "0100" is not.

   Any two characters may be swapped, even if they are not adjacent.



   Example 1:

Input: s = "111000"
Output: 1
Explanation: Swap positions 1 and 4: "111000" -> "101010"
The string is now alternating.

Example 2:

Input: s = "010"
Output: 0
Explanation: The string is already alternating, no swaps are needed.

Example 3:

Input: s = "1110"
Output: -1



Constraints:

1 <= s.length <= 1000
s[i] is either '0' or '1'.

*/


#include"head.h"
class Solution {
  public:
    int minSwaps(string s) {
      int res=min(solve(s,1),solve(s,0));
      return res==INT_MAX?-1:res;
    }
    int solve(string s,int c)
    {
      vector<int> cnt(2,0);
      for(int i=0;i<s.size();i++,c^=1)
      {
        if(s[i]!=c+'0')
          cnt[s[i]-'0']++;
      }
      return cnt[0]==cnt[1]?cnt[0]:INT_MAX;
    }
};


int main() 
{
  Solution s;
  cout<<s.minSwaps("111000")<<endl;
  cout<<s.minSwaps("010")<<endl;
  cout<<s.minSwaps("1110")<<endl;
  return 0;
}
