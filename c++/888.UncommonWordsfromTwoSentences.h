/*
We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Return a list of all uncommon words. 

You may return the list in any order.

 

Example 1:

Input: A = "this apple is sweet", B = "this apple is sour"
Output: ["sweet","sour"]

Example 2:

Input: A = "apple apple", B = "banana"
Output: ["banana"]

 

Note:

    0 <= A.length <= 200
    0 <= B.length <= 200
    A and B both contain only spaces and lowercase letters.

*/

#include"head.h"

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
 	map<string,int> h;
	istringstream a(A);istringstream b(B);
	vector<string> res;
	string temp;
	while(a>>temp)
	h[temp]++;
	while(b>>temp)
	h[temp]++;
	for(map<string,int>::iterator it=h.begin();it!=h.end();it++)
	if(it->second==1)
	res.push_back(it->first);
	return res;	
    }
};
