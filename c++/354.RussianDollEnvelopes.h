/*
   You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

   What is the maximum number of envelopes can you Russian doll? (put one inside other)

Note:
Rotation is not allowed.

Example:

Input: [[5,4],[6,4],[6,7],[2,3]]
Output: 3 
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

*/

#include"head.h"

class Solution {
	public:
	static		bool cmp (pair<int, int> i, pair<int, int> j) {
			if (i.first == j.first)
				return i.second < j.second;
			return i.first < j.first;
		}
		int maxEnvelopes(vector<pair<int, int>>& envelopes) {
			int n=envelopes.size();
			int res=(n==0?0:1);	
			if(!n) return 0;
			sort(envelopes.begin(),envelopes.end(),cmp);
			vector<int> dp(n,1);
			for(int i=0;i<envelopes.size();i++)
			{
				for(int j=i-1;j>=0;j--)
					if(envelopes[i].first>envelopes[j].first&&envelopes[i].second>envelopes[j].second)
					{
						dp[i]=max(dp[j]+1,dp[i]);
						res=max(dp[i],res);
					}
			}
			return res;
		}
};
