/*
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n
*/
/*
Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99]) 
*/
#include"head.h"

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
	if(n==0) return 1;
 	int res=10,usingNumber=9,curRes=9; 
	while(--n>0&&usingNumber>0)
	{
		curRes=curRes*usingNumber;
		res+=curRes;
		--usingNumber;
	}
	return res;
    }
};
