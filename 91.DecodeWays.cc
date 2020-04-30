/*
 A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2. 
*/

#include"91.DecodeWays.h"

int main()
{
	Solution s;
	cout<<s.numDecodings("12")<<endl;
	cout<<"input"<<"226"<<endl;
	cout<<s.numDecodings("226")<<endl;
	cout<<"input"<<"0"<<endl;
	cout<<s.numDecodings("0")<<endl;
	cout<<"input"<<"100"<<endl;
	cout<<s.numDecodings("100")<<endl;
	cout<<"input"<<"10"<<endl;
	cout<<s.numDecodings("10")<<endl;
	cout<<"input"<<"012"<<endl;
	cout<<s.numDecodings("012")<<endl;
	cout<<"input"<<"17"<<endl;
	cout<<s.numDecodings("17")<<endl;
	cout<<"input"<<"27"<<endl;
	cout<<s.numDecodings("27")<<endl;
	return 0;
}
