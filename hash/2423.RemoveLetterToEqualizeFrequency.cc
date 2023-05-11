/*
   You are given a 0-indexed string word, consisting of lowercase English letters. You need to select one index and remove the letter at that index from word so that the frequency of every letter present in word is equal.

   Return true if it is possible to remove one letter so that the frequency of all letters in word are equal, and false otherwise.

Note:

The frequency of a letter x is the number of times it occurs in the string.
You must remove exactly one letter and cannot chose to do nothing.



Example 1:

Input: word = "abcc"
Output: true
Explanation: Select index 3 and delete it: word becomes "abc" and each character has a frequency of 1.

Example 2:

Input: word = "aazz"
Output: false
Explanation: We must delete a character, so either the frequency of "a" is 1 and the frequency of "z" is 2, or vice versa. It is impossible to make all present letters have equal frequency.



Constraints:

2 <= word.length <= 100
word consists of lowercase English letters only.

*/

#define c11
#include"head.h"
class Solution {
	public:
		bool equalFrequency(string word) {
		vector<int> cnt(26,0);
		for(int i=0;i<word.size();i++)
			cnt[word[i]-'a']++;

		int onlyone=0;
		unordered_set<int> exist;
		int mx=0,cnt_mx=0;
		int mn=word.size()+1,cnt_mn=0;

		for(int i=0;i<26;i++)
		{
			if(cnt[i]==0)
				continue;

			onlyone++;
			exist.insert(cnt[i]);

			if(mx<cnt[i])
			mx=cnt[i],cnt_mx=1;
			else if(mx==cnt[i])
				cnt_mx++;

			if(mn>cnt[i])
			mn=cnt[i],cnt_mn=1;
			else if(mn==cnt[i])
				cnt_mn++;

		}

		if(exist.size()>2)
			return false;

		if(onlyone==1)
			return true;

		if(mx>mn+1)
			return cnt_mn==1&&mn==1;

		if(mx==mn+1)
			return cnt_mx==1||(mn==1&&cnt_mn==1);

		return mx==1;

		}
};


int main() 
{
	Solution s;
	cout<<s.equalFrequency("abcc")<<endl;
	cout<<s.equalFrequency("aazz")<<endl;
	return 0;
}
