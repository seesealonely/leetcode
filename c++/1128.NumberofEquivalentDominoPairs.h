/*
Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a==c and b==d), or (a==d and b==c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

 

Example 1:

Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1

 

Constraints:

    1 <= dominoes.length <= 40000
    1 <= dominoes[i][j] <= 9

*/

#define c11
#include"head.h"

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {        
	unordered_map<int,int> fre;
	int res=0;
	for(int i=0;i<dominoes.size();i++)
	{
		int cur=10*min(dominoes[i][0],dominoes[i][1])+max(dominoes[i][0],dominoes[i][1]);
		fre[cur]++;
	}
	for(unordered_map<int,int>::iterator it=fre.begin();it!=fre.end();it++)
	res+=it->second*(it->second-1)/2;
	return res;
    }
};
