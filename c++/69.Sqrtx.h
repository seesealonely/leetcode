/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

#include"head.h"

class Solution {
public:
    int mySqrt(int x) {
	long res=x;
	while(res*res>x)
	{
		res=(res+x/res)>>1;
	}
	return res;
    }
};
