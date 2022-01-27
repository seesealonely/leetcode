/*
   Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.

   An alphanumeric string is a string consisting of lowercase English letters and digits.



   Example 1:

Input: s = "dfa12321afd"
Output: 2
Explanation: The digits that appear in s are [1, 2, 3]. The second largest digit is 2.

Example 2:

Input: s = "abc1111"
Output: -1
Explanation: The digits that appear in s are [1]. There is no second largest digit.



Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters and/or digits.

*/
#include"head.h"
class Solution {
	public:
		int secondHighest(string s) {
		int count=0;
		for(int i=0;i<s.size();i++)
			if(s[i]>='0'&&s[i]<='9')
				count|=(1<<(s[i]-'0'+1));
		int cntOne=0,i=10;
		for(;i>0;i--)
			if(count&(1<<i))
			{
				cntOne++;
				if(cntOne==2)
					break;
			}

			return cntOne==2?i-1:-1;
		}
};
int main() 
{
	Solution s;
	cout<<s.secondHighest("dfa12321afd")<<endl;
	cout<<s.secondHighest("abc111")<<endl;
	return 0;
}
