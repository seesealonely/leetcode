/*
   Given an integer n, return the number of ways you can write n as the sum of consecutive positive integers.



   Example 1:

Input: n = 5
Output: 2
Explanation: 5 = 2 + 3

Example 2:

Input: n = 9
Output: 3
Explanation: 9 = 4 + 5 = 2 + 3 + 4

Example 3:

Input: n = 15
Output: 4
Explanation: 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5



Constraints:

1 <= n <= 109

*/


#include"head.h"
class Solution {
	public:
		int consecutiveNumbersSum(int n) {
		int res=0;

		n+=n;

		for(int i=1;i*i<=n;i++)
		{
			if(n%i)
				continue;

			int x=n/i+1-i;

			if(x%2==0&&x>0)
				res++;
		}
		return res;
		}
};


int main() 
{
	Solution s;
	cout<<s.consecutiveNumbersSum(5)<<endl;
	cout<<s.consecutiveNumbersSum(9)<<endl;
	cout<<s.consecutiveNumbersSum(15)<<endl;
	return 0;
}
