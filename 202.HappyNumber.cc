/*
   Write an algorithm to determine if a number is "happy".

   A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
   */

#include"202.HappyNumber.h"

int main()
{
	Solution s;
	cout<<s.isHappy(1)<<endl;	
	cout<<s.isHappy(19)<<endl;	
	cout<<s.isHappy(100)<<endl;	
	cout<<s.isHappy(68)<<endl;	
	cout<<s.isHappy(67)<<endl;	
	return 0;
}
