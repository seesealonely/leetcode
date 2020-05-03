/*
Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.

*/

#include"head.h"

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
	return bruteForce(A,B); 	       
    }
	int bruteForce(string a,string b)
	{
		string adda(a);
		int i=1;
		for(;i<=b.size()/a.size()+2;i++,adda+=a)
			if(adda.find(b)!=string::npos) return i;
		return -1;
	}
};
