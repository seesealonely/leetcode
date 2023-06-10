/*
   Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.

   The closest is defined as the absolute difference minimized between two integers.



   Example 1:

Input: n = "123"
Output: "121"

Example 2:

Input: n = "1"
Output: "0"
Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.



Constraints:

1 <= n.length <= 18
n consists of only digits.
n does not have leading zeros.
n is representing an integer in the range [1, 1018 - 1].

*/


#include"head.h"
class Solution {
	public:
		typedef long long 	ll;
		ll get(const ll &num)
		{
			string s=to_string(num);
			for(int i=0,j=s.size()-1;i<j;i++,j--)
				s[j]=s[i];
			return stoll(s);
		}
		string nearestPalindromic(string n) {
		ll s=stoll(n);
		if(s==11) return "9";

		ll small=s,big=s;
		for(int i=0;small>=s;i++)
			small=get(s-pow(10,i));

		for(int i=0;big<=s;i++)
			big=get(s+pow(10,i));

		if(s-small<=big-s) return to_string(small);
		else return to_string(big);
		}
};


int main() 
{
	Solution s;
	cout<<s.nearestPalindromic("123")<<endl;
	cout<<s.nearestPalindromic("1")<<endl;
	return 0;
}
