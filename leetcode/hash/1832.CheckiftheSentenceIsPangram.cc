/*
   A pangram is a sentence where every letter of the English alphabet appears at least once.

   Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.



   Example 1:

Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.

Example 2:

Input: sentence = "leetcode"
Output: false



Constraints:

1 <= sentence.length <= 1000
sentence consists of lowercase English letters.

*/
#include"head.h"
class Solution {
	public:
		bool checkIfPangram(string sentence) {
		int hash=0,count=0;
		const int n=sentence.size();
		for(int i=0;i<n;i++)
			hash|=(1<<(sentence[i]-'a'));
		while(hash)
		{
			if(hash&1)
				count++;
			hash>>=1;
		}
		return count==26;
		}
};
int main() 
{
	Solution s;
	cout<<s.checkIfPangram("thequickbrownfoxjumpsoverthelazydog")<<endl;
	cout<<s.checkIfPangram("leetcode")<<endl;
	return 0;
}
