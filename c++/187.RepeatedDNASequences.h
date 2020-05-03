/*
   All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

   Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

   For example,

   Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].

*/
#define c11
#include"head.h"
using namespace std;
class Solution {
	public:
		vector<string> findRepeatedDnaSequences(string s) {
			int begin=0,index=0,slen=s.size();       
			unordered_map<int,int> map;
			vector<string> res;
			while(begin<9) index=index<<3|s[begin++]&7;
			while(begin<slen)
			{
				index=(index<<3)&0x3fffffff|(s[begin++]&7);
				if((map[index]++)==1)
				 res.push_back(s.substr(begin-10,10));	
			}
			return res;
		}
};
