/*
   You are given a string word and an integer k.

   A substring s of word is complete if:

   Each character in s occurs exactly k times.
   The difference between two adjacent characters is at most 2. That is, for any two adjacent characters c1 and c2 in s, the absolute difference in their positions in the alphabet is at most 2.

   Return the number of complete substrings of word.

   A substring is a non-empty contiguous sequence of characters in a string.



   Example 1:

Input: word = "igigee", k = 2
Output: 3
Explanation: The complete substrings where each character appears exactly twice and the difference between adjacent characters is at most 2 are: igigee, igigee, igigee.

Example 2:

Input: word = "aaabbbccc", k = 3
Output: 6
Explanation: The complete substrings where each character appears exactly three times and the difference between adjacent characters is at most 2 are: aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc.



Constraints:

1 <= word.length <= 105
word consists only of lowercase English letters.
1 <= k <= word.length

*/


#include"head.h"
class Solution {
	public:
		int countCompleteSubstrings(string word, int k) {
			const int n=word.size();
			int res=0;
			string_view s(word);
			for(int l=0,r=1;r<=word.size();r++)
			{
				while(abs(word[r]-word[r-1])<=2)
					r++;
				res+=check(word.substr(l,r-l),k);
				l=r;
			}
			return res;
		}
		int check(const string&s,int k)
		{
			int res=0;
			for(int i=1;i<=26&&k*i<=s.size();i++)
			{
				vector<int> cnt(26,0);
				for(int r=0;r<s.size();r++)
				{
					cnt[s[r]-'a']++;
					int l=r+1-k*i;
					if(l>=0)
					{
						if(check1(cnt,k))
							res++;
						cnt[s[l]-'a']--;
					}
				}
			}
			return res;
		}
		bool check1(vector<int> & cnt,int k)
		{
			for(int i=0;i<26;i++)
				if(cnt[i]&&cnt[i]!=k)
					return false;
			return true;
		}
};


int main() 
{
	Solution s;
	cout<<s.countCompleteSubstrings("igigee",2)<<endl;
	cout<<s.countCompleteSubstrings("aaabbbccc",3)<<endl;
	return 0;
}
