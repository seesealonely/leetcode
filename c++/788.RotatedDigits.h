/*
X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X.  Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.

Now given a positive number N, how many numbers X from 1 to N are good?

Example:
Input: 10
Output: 4
Explanation: 
There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.

Note:

    N  will be in range [1, 10000].

*/

#include"head.h"

int dp(int N)
{
	vector<int> dp(N+1);
	int res=0;
	for(int i=0;i<N+1;i++)
	{
		if(i<10)
		{
		if(i==0||i==1||i==8)
			dp[i]=1;
		else if(i==2||i==5||i==6||i==9)
		{
			dp[i]=2;
			res++;
		}
		}
		else
		{
			int  prehalf=dp[i/10],nexthalf=dp[i%10];
			if(prehalf==1&&nexthalf==1)
			dp[i]=1;
			else if(prehalf+nexthalf>=3)
			{
				dp[i]=2;
				res++;
			}
		}
	}
	return res;
}
class Solution {
public:
    int rotatedDigits(int N) {
       return dp(N); 
    }
};
