/*
 Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000. 
*/

#include"386.LexicographicalNumbers.h"

int main()
{
	Solution s;
	show(s.lexicalOrder(10));
	show(s.lexicalOrder(13));
	show(s.lexicalOrder(133));
	show(s.lexicalOrder(34));
	return 0;
}
