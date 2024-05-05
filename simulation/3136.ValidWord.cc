/*
   A word is considered valid if:

   It contains a minimum of 3 characters.
   It consists of the digits 0-9, and the uppercase and lowercase English letters. (Not necessary to have all of them.)
   It includes at least one vowel.
   It includes at least one consonant.

   You are given a string word.

   Return true if word is valid, otherwise, return false.

Notes:

'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
A consonant is an English letter that is not a vowel.



Example 1:

Input: word = "234Adas"

Output: true

Explanation:

This word satisfies the conditions.

Example 2:

Input: word = "b3"

Output: false

Explanation:

The length of this word is fewer than 3, and does not have a vowel.

Example 3:

Input: word = "a3$e"

Output: false

Explanation:

This word contains a '$' character and does not have a consonant.



Constraints:

1 <= word.length <= 20
word consists of English uppercase and lowercase letters, digits, '@', '#', and '$'.

*/


#include"head.h"
class Solution {
	public:
		bool isValid(string word) {

			const int n=word.size();
			if(n<3) return false;
			int count=0;
			for(int i=0;i<n;i++)
			{
				if(isdigit(word[i]))
					count|=1;
				else if(isalpha(word[i]))
				{
					if(check(word[i]))
					count|=2;
					else
					count|=4;
				}
				else
					return false;
			}
			return count==7||count==6;
		}
		bool check(char x)
		{
			return x=='a'||x=='A'||x=='e'||x=='E'||x=='i'||x=='I'||x=='o'||x=='O'||x=='u'||x=='U';
		}
};


int main() 
{
	Solution s;
	cout<<s.isValid( "234Adas")<<endl;
	cout<<s.isValid("b3")<<endl;
	cout<<s.isValid("a3$e")<<endl;
	cout<<s.isValid("AhI")<<endl;
	return 0;
}
