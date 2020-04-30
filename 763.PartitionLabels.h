/*
 A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

Note:

    S will have length in range [1, 500].
    S will consist of lowercase letters ('a' to 'z') only.

*/

#include"head.h"

class Solution {
public:
    vector<int> partitionLabels(string S) {
	int begin=0,end=0;
 	vector<int> last(26,0),res;
	for(int i=0;i<S.size();i++)
	last[S[i]-'a']=i;
	for(int i=0;i<S.size();i++)
	{
		end=max(end,last[S[i]-'a']);
		if(i==end)
		{
		res.push_back(end-begin+1);
		begin=end+1;
		}
	}       
	return res;
    }
};
