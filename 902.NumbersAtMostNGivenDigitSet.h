/*
We have a sorted set of digits D, a non-empty subset of {'1','2','3','4','5','6','7','8','9'}.  (Note that '0' is not included.)

Now, we write numbers using these digits, using each digit as many times as we want.  For example, if D = {'1','3','5'}, we may write numbers such as '13', '551', '1351315'.

Return the number of positive integers that can be written (using the digits of D) that are less than or equal to N.

 

Example 1:

Input: D = ["1","3","5","7"], N = 100
Output: 20
Explanation: 
The 20 numbers that can be written are:
1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.

Example 2:

Input: D = ["1","4","9"], N = 1000000000
Output: 29523
Explanation: 
We can write 3 one digit numbers, 9 two digit numbers, 27 three digit numbers,
81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit numbers.
In total, this is 29523 integers that can be written using the digits of D.

 

Note:

    D is a subset of digits '1'-'9' in sorted order.
    1 <= N <= 10^9

*/

#include"head.h"

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
	string ds="",ns=to_string(N);
	for(int i=0;i<D.size();i++)
	ds+=D[i];	
	int dlen=D.size(),nlen=ns.size(),res=0;
	vector<int> dp(nlen+1,0);
	dp[nlen]=1;
	for(int i=nlen-1;i>=0;i--)
	{
		for(int j=0;j<dlen;j++)
		{
			if(ns[i]==ds[j])
			dp[i]+=dp[i+1];
			else if(ds[j]<ns[i])
			dp[i]+=pow(dlen,nlen-1-i);
		}
	}
	for(int i=1;i<nlen;i++)
		dp[0]+=pow(dlen,i);
	return dp[0];
    }
};
