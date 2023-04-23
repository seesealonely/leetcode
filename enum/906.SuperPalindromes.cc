/*
   Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.

   Given two positive integers left and right represented as strings, return the number of super-palindromes integers in the inclusive range [left, right].



   Example 1:

Input: left = "4", right = "1000"
Output: 4
Explanation: 4, 9, 121, and 484 are superpalindromes.
Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.

Example 2:

Input: left = "1", right = "2"
Output: 1



Constraints:

1 <= left.length, right.length <= 18
left and right consist of only digits.
left and right cannot have leading zeros.
left and right represent integers in the range [1, 1018 - 1].
left is less than or equal to right.

*/


#include"head.h"
class Solution {
	public:
		#define ll long long 
		bool check(string s)
		{
			for(int i=0,j=s.size()-1;i<j;i++,j--)
				if(s[i]!=s[j])
					return false;
			return true;
		}
		int superpalindromesInRange(string L, string R) {
		ll l=stoll(L),r=stoll(R);

		int res=0;
		for(int i=1;i<=3;i++)
			if(i*i>=l&&i*i<=r)
				res++;

		for(int i=1;i<10000;i++)
		{
			string t=to_string(i);
			string rt=t;
			reverse(rt.begin(),rt.end());

			ll s=stoll(t+rt);
			s*=s;
			if(s>r)
				break;

			if(check(to_string(s))&&l<=s&&s<=r)
				res++;

			for(char j='0';j<='9';j++)
			{
				s=stoll(t+j+rt);
				s*=s;
				if(check(to_string(s))&&l<=s&&s<=r)
					res++;

			}
		}

		return res;
		}
};


int main() 
{
	Solution s;
	cout<<s.superpalindromesInRange("4","1000")<<endl;
	cout<<s.superpalindromesInRange("1","2")<<endl;
	return 0;
}
