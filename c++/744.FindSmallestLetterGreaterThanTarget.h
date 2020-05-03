/*
   Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.

   Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.

Examples:

Input:
letters = ["c", "f", "j"]
target = "a"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "c"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "d"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "g"
Output: "j"

Input:
letters = ["c", "f", "j"]
target = "j"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "k"
Output: "c"

Note:

letters has a length in range [2, 10000].
letters consists of lowercase letters, and contains at least 2 unique letters.
target is a lowercase letter.

*/

#include"head.h"
char way1(vector<char>& letters, char target) 
{
	vector<bool> skeen(26,false);
//	bool *skeen=s[0];
	for(int i=0;i<letters.size();i++)
	skeen[letters[i]-'a']=true;
	while(true)
	{
		++target;
		if(target>'z') target='a';
		if(skeen[target-'a']) return target;
	}
}


char way2(vector<char>& letters, char target) 
{
	for(int i=0,len=letters.size();i<len;++i)
	if(letters[i]>target) return letters[i];
	return letters[0];
}

char way3(vector<char>& letters, char target) 
{
	int lo=0,hi=letters.size();
	while(lo<hi)
	{
	int mi=lo+(hi-lo)/2;
	if(letters[mi]>target) lo=mi+1;
	else hi=mi;
	}
	return  letters[lo%letters.size()];
}
class Solution {
	public:
		char nextGreatestLetter(vector<char>& letters, char target) {
		cout<<way1(letters,target)<<" "<<
		way2(letters,target)<<" "<<
		way2(letters,target)<<" "<<endl;

		}
};
