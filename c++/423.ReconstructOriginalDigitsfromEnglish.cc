/*
Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:

    Input contains only lowercase English letters.
    Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
    Input length is less than 50,000.

Example 1:

Input: "owoztneoer"

Output: "012"

Example 2:

Input: "fviefuro"

Output: "45"

*/

#include"423.ReconstructOriginalDigitsfromEnglish.h"

int main()
{
	Solution s;
	cout<<s.originalDigits("owoztneoer")<<endl;
	cout<<s.originalDigits("fviefuro")<<endl;
	cout<<s.originalDigits("zerozero")<<endl;
	return 0;
}
