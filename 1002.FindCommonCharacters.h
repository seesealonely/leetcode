/*
Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

 

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]

 

Note:

    1 <= A.length <= 100
    1 <= A[i].length <= 100
    A[i][j] is a lowercase letter

*/

#define c11
#include"head.h"

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
	vector<int> hash(26,INT_MAX);
	vector<string> res;
	for(int i=0;i<A.size();i++)        
	{
		vector<int> tmp(26,0);
		for(int j=0;j<A[i].size();j++)
		tmp[A[i][j]-'a']++;
		for(int j=0;j<26;j++)
		hash[j]=min(hash[j],tmp[j]);
	}
	for(int i=0;i<26;i++)
		if(hash[i])
		for(int j=hash[i];j>0;j--)
		res.push_back(string(1,i+'a'));
	return res;
    }
};
