/*
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3

Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.

*/
#include"head.h"

class Solution {
public:
    int findNthDigit(int n) {
	 long base=9,digits=1;
	while(n-base*digits>0)
	{
		n-=base*digits;
		base*=10;
		digits++;
	}       
	int index=n%digits;
	if(index==0)
	index=digits;
	long num=1;
	for(int i=1;i<digits;i++)
	num*=10;
	num+=(index==digits)?n/digits-1:n/digits;
	for(int i=index;i<digits;i++)
		num/=10;
	return num%10;
    }
};
