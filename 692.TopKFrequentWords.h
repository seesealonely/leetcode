/*
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:

Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:

Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.

Note:

    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Input words contain only lowercase letters.

Follow up:

    Try to solve it in O(n log k) time and O(n) extra space.

*/

#define c11
#include"head.h"

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
	     return usingBucket(words,k); 
    }
    vector<string> usingBucket(vector<string>& words, int k) {
	vector<string> res;
	  unordered_map<string,int> freq;
	vector<set<string> > v(words.size()+1,set<string>()); 
	for(int i=0;i<words.size();i++)
		freq[words[i]]++;
	for(unordered_map<string,int>::iterator it=freq.begin();it!=freq.end();it++)
	v[it->second].insert(it->first);
	for(int i=v.size()-1;i>=0;i--)
	{
		if(k<=0) break;
		vector<string> sub(v[i].begin(),v[i].end());
		if(k>=sub.size())
		res.insert(res.end(),sub.begin(),sub.end());
		else
		res.insert(res.end(),sub.begin(),sub.begin()+k);
		k-=sub.size();
	}
	return res;
    }
    vector<string> usingPriority(vector<string>& words, int k) {
	
	}
};
