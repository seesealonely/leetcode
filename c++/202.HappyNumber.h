/*
   Write an algorithm to determine if a number is "happy".

   A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
   */

#include"head.h"

class Solution {
	public:
		bool isHappy(int n) {
			int fast=next(n),slow=n;
			while(fast!=slow)
			{
				slow=next(slow);
				fast=next(next(fast));
			}
			return slow==1;
		}
	private:
		int next(int n)
		{
			int res=0,i;
			while(n)
			{
				i=n%10;
				res+=i*i;
				n/=10;
			}
			return res;
		}
};
