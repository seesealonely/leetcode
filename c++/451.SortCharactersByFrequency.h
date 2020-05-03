/*
   Given a string, sort it in decreasing order based on the frequency of characters.

   Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

*/
#define c11
#include"head.h"

class Solution {
	public:
		string frequencySort(string s)
		{
			unordered_map<char,int> h;
			vector<string> bucket(s.size()+1,"");       
			string res;
			for(int i=0;i<s.size();++i)
				h[s[i]]++;
			for(unordered_map<char,int>::iterator i=h.begin();i!=h.end();++i)
				bucket[i->second].append(i->second,i->first);
			for(int i=s.size();i>0;i--)
				if(!bucket[i].empty())
					res.append(bucket[i]);
			return res;
		}
};
