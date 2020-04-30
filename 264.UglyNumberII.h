/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note:  

    1 is typically treated as an ugly number.
    n does not exceed 1690.

*/

#include"head.h"

class Solution {
public:
    int nthUglyNumber(int n) {
	vector<int> index(3,0),res(n,INT_MAX),factor;
	factor.push_back(2);factor.push_back(3);factor.push_back(5);
	res[0]=1;
	for(int i=1;i<n;i++)
	{
		res[i]=min(res[index[0]]*2,min(res[index[1]]*3,res[index[2]]*5));
		for(int j=0;j<3;j++)
			if(res[index[j]]*factor[j]==res[i]) index[j]++;

	}
	return res[n-1];
    }
};
