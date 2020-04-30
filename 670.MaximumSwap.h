/*
 Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:

Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.

Example 2:

Input: 9973
Output: 9973
Explanation: No swap.

Note:

    The given number is in the range [0, 108]
*/

#include"head.h"
int dp(int num)
{
	string s=to_string(num);
	vector<int> dp(s.size(),-1);
	int maxindex=s.size()-1;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]>s[maxindex])
		{
			maxindex=i;
		}
		dp[i]=maxindex;
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[dp[i]]!=s[i])
		{
			char tmp=s[i];
			s[i]=s[dp[i]];
			s[dp[i]]=tmp;
			break;
		}
	}
	return atoi(s.c_str());
}
class Solution {
public:
    int maximumSwap(int num) {
	return dp(num);        
    }
};
