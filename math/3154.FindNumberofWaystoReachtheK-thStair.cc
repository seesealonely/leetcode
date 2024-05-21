/*
   You are given a non-negative integer k. There exists a staircase with an infinite number of stairs, with the lowest stair numbered 0.

   Alice has an integer jump, with an initial value of 0. She starts on stair 1 and wants to reach stair k using any number of operations. If she is on stair i, in one operation she can:

   Go down to stair i - 1. This operation cannot be used consecutively or on stair 0.
   Go up to stair i + 2jump. And then, jump becomes jump + 1.

   Return the total number of ways Alice can reach stair k.

   Note that it is possible that Alice reaches the stair k, and performs some operations to reach the stair k again.



   Example 1:

Input: k = 0

Output: 2

Explanation:

The 2 possible ways of reaching stair 0 are:

Alice starts at stair 1.
Using an operation of the first type, she goes down 1 stair to reach stair 0.
Alice starts at stair 1.
Using an operation of the first type, she goes down 1 stair to reach stair 0.
Using an operation of the second type, she goes up 20 stairs to reach stair 1.
Using an operation of the first type, she goes down 1 stair to reach stair 0.

Example 2:

Input: k = 1

Output: 4

Explanation:

The 4 possible ways of reaching stair 1 are:

Alice starts at stair 1. Alice is at stair 1.
Alice starts at stair 1.
Using an operation of the first type, she goes down 1 stair to reach stair 0.
Using an operation of the second type, she goes up 20 stairs to reach stair 1.
Alice starts at stair 1.
Using an operation of the second type, she goes up 20 stairs to reach stair 2.
Using an operation of the first type, she goes down 1 stair to reach stair 1.
Alice starts at stair 1.
Using an operation of the first type, she goes down 1 stair to reach stair 0.
Using an operation of the second type, she goes up 20 stairs to reach stair 1.
Using an operation of the first type, she goes down 1 stair to reach stair 0.
Using an operation of the second type, she goes up 21 stairs to reach stair 2.
Using an operation of the first type, she goes down 1 stair to reach stair 1.



Constraints:

0 <= k <= 109

*/


int c[31][31];
void init()
{
	for(int i=0;i<31;i++)
	{
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
}
#include"head.h"
class Solution {
	public:
		int waysToReachStair(int k) {
			init();
			int res=0;
			for(int i=0;i<30;i++)
			{
				int m=(1<<i)-k;
				if(0<=m&&m<=i+1)
					res+=c[i+1][m];
			}
			return res;
		}
};


int main() 
{
	Solution s;
	cout<<s.waysToReachStair(0)<<endl;
	cout<<s.waysToReachStair(1)<<endl;
	return 0;
}
