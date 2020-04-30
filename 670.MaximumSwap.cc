/*
 Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:

Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.

Example 2:

Input: 9973
Output: 9973
Explanation: No swap.

Note:

    The given number is in the range [0, 108]
*/

#include"670.MaximumSwap.h"

int main()
{
	Solution s;
	cout<<s.maximumSwap(2736)<<endl;
	cout<<s.maximumSwap(9973)<<endl;
	return 0;
}
