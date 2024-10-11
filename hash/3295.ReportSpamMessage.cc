/*
   You are given an array of strings message and an array of strings bannedWords.

   An array of words is considered spam if there are at least two words in it that exactly match any word in bannedWords.

   Return true if the array message is spam, and false otherwise.



   Example 1:

Input: message = ["hello","world","leetcode"], bannedWords = ["world","hello"]

Output: true

Explanation:

The words "hello" and "world" from the message array both appear in the bannedWords array.

Example 2:

Input: message = ["hello","programming","fun"], bannedWords = ["world","programming","leetcode"]

Output: false

Explanation:

Only one word from the message array ("programming") appears in the bannedWords array.



Constraints:

1 <= message.length, bannedWords.length <= 105
1 <= message[i].length, bannedWords[i].length <= 15
message[i] and bannedWords[i] consist only of lowercase English letters.

*/

#define c11
#include"head.h"
class Solution {
	public:
		bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
		unordered_set<string> vis(bannedWords.begin(),bannedWords.end());
		int cnt=0;
		for(int i=0;i<message.size();i++)
		{
			if(vis.count(message[i]))
				cnt++;
			if(cnt==2)
				return true;
		}
		return false;
		}
};


int main() 
{
	Solution s;
	vector<string> message = {"hello","world","leetcode"}, bannedWords = {"world","hello"};
	cout<<s.reportSpam(message,bannedWords)<<endl;
	message.clear();bannedWords.clear();
	message = {"hello","programming","fun"}, bannedWords = {"world","programming","leetcode"};
	cout<<s.reportSpam(message,bannedWords)<<endl;
	return 0;
}
