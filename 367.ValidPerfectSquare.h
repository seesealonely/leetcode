/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True

Example 2:

Input: 14
Returns: False
*/

#include"head.h"

/*
class Solution {
public:
    bool isPerfectSquare(int num) {
 	int  begin=1,end=num,mid;
	while(begin<=end)
	{
	mid=(begin+end)>>1;
	if(mid*mid==num)
		return true;
	else if(mid*mid<num)
		begin=mid+1;
	else end=mid-1;
	}       
	return false;
    }
};
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
	long x=num;
	while(x*x>num)
	{
	x=(x+num/x)>>1;
	}
	return x*x==num;
    }
};
