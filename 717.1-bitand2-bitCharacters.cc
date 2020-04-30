/*
We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).

Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.

Example 1:

Input: 
bits = [1, 0, 0]
Output: True
Explanation: 
The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.

Example 2:

Input: 
bits = [1, 1, 1, 0]
Output: False
Explanation: 
The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.

Note:
1 <= len(bits) <= 1000.
bits[i] is always 0 or 1.
*/

#include"717.1-bitand2-bitCharacters.h"
int main()
{
	int bi1[]={1,0,0};
	int  bi2[]={1,1,1,0};
	vector<int>  b1(bi1,bi1+3), b2(bi2,bi2+4);
	Solution s;
	s.isOneBitCharacter(b1);
	s.isOneBitCharacter(b2);
	return 0;
}
