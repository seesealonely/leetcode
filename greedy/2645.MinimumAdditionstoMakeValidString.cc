/*
   Given a string word to which you can insert letters "a", "b" or "c" anywhere and any number of times, return the minimum number of letters that must be inserted so that word becomes valid.

   A string is called valid if it can be formed by concatenating the string "abc" several times.



   Example 1:

Input: word = "b"
Output: 2
Explanation: Insert the letter "a" right before "b", and the letter "c" right next to "a" to obtain the valid string "abc".

Example 2:

Input: word = "aaa"
Output: 6
Explanation: Insert letters "b" and "c" next to each "a" to obtain the valid string "abcabcabc".

Example 3:

Input: word = "abc"
Output: 0
Explanation: word is already valid. No modifications are needed.



Constraints:

1 <= word.length <= 50
word consists of letters "a", "b" and "c" only.

*/


#include"head.h"
class Solution {
	public:
		int addMinimum(string word) {
		const int n=word.size();
		int count=1;
		for(int i=1;i<n;i++)
			if(word[i-1]>=word[i])
				count++;

		return 3*count-n;
		}
};


int main() 
{
	Solution s;
	cout<<s.addMinimum("b")<<endl;
	cout<<s.addMinimum("aaa")<<endl;
	cout<<s.addMinimum("abc")<<endl;
	return 0;
}
