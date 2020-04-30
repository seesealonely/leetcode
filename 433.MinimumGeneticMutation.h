/*
   A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".

   Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string.

   For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.

   Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make it a valid gene string.

   Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". If there is no such a mutation, return -1.

Note:

Starting point is assumed to be valid, so it might not be included in the bank.
If multiple mutations are needed, all mutations during in the sequence must be valid.
You may assume start and end string is not the same.



Example 1:

start: "AACCGGTT"
end:   "AACCGGTA"
bank: ["AACCGGTA"]

return: 1



Example 2:

start: "AACCGGTT"
end:   "AAACGGTA"
bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

return: 2



Example 3:

start: "AAAAACCC"
end:   "AACCCCCC"
bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

return: 3

*/
#define c11
#include"head.h"

class Solution {
	public:
		int minMutation(string start, string gend, vector<string>& bank) {
			unordered_set<string> set(bank.begin(),bank.end());        
			queue<string> qu;
			qu.push(start);set.erase(start);
			int res=0;
			while(!qu.empty())
			{
				for(int i=qu.size();i>0;i--)
				{
					string pop=qu.front();qu.pop();
					if(pop==gend) return res;
					addQueue(set,qu,pop);
				}
				res++;
			}
			return -1;
		}
		void addQueue(unordered_set<string> &set,queue<string> &qu,string &pop)
		{
			char  alpha[]={'A','C','T','G'};
			for(int i=0;i<pop.size();i++)
			{
				char cur=pop[i];
				for(int j=0;j<4;j++)
				{
					pop[i]=alpha[j];	
					if(set.find(pop)!=set.end())
					{
						qu.push(pop);
						set.erase(pop);
					}
				}	
				pop[i]=cur;
			}
		}
};
