/*
 Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:

Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:

Input: 3
Output: False

*/

#include"head.h"

class Solution {
public:
    bool judgeSquareSum(int c) {
 	int n1=0,n2=sqrt(c);       
	while(n1<=n2)
	{
	int cur=n1*n1+n2*n2;
	if(cur==c) return true;
	if(cur<c) n1++;
	else n2--;
	}
	return false;
    }
};
