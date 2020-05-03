/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!

Example :

Input: n = 10, pick = 6
Output: 6

*/

#include"head.h"

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0

class Solution {
public:
int guess(int num){
	}
    int guessNumber(int n) {
	int l=1,r=n,res=0;
	while(true)
	{
		int g=l+(r-l)/2;
		res=guess(g);
		if(res==0)
			return g;
		else if(res==1)
			l=g+1;
		else
			r=g-1;
	}
    }
};
