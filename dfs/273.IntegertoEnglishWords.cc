/*
   Convert a non-negative integer num to its English words representation.



   Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"

Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"

Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"



Constraints:

0 <= num <= 231 - 1

*/


#include"head.h"
class Solution {
	public:
		string numberToWords(int num) {
		return num==0?"Zero":toString(num).substr(1);
		}
	private:
		string toString(int n)
		{
			if(n>=1e9)
				return toString(n/(int)1e9)+" Billion"+toString(n%(int)1e9);
			else if(n>=1e6)
				return toString(n/(int)1e6)+" Million"+toString(n%(int)1e6);
			else if(n>=1000)
				return toString(n/1000)+" Thousand"+toString(n%1000);
			else if(n>=100)
				return toString(n/100)+" Hundred"+toString(n%100);
			else if(n>=20)
				return " "+_100[n/10-2]+toString(n%10);
			else if(n>=1)
				return " "+_20[n-1];
			else 
				return "";
		}
		vector<string> _20 {"One","Two","Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};

		vector<string> _100 {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

};


int main() 
{
	Solution s;
	cout<<s.numberToWords(123)<<endl;
	cout<<s.numberToWords(12345)<<endl;
	cout<<s.numberToWords(1234567)<<endl;
	return 0;
}
