/*
   You are given two strings stamp and target. Initially, there is a string s of length target.length with all s[i] == '?'.

   In one turn, you can place stamp over s and replace every letter in the s with the corresponding letter from stamp.

   For example, if stamp = "abc" and target = "abcba", then s is "?????" initially. In one turn you can:
   place stamp at index 0 of s to obtain "abc??",
   place stamp at index 1 of s to obtain "?abc?", or
   place stamp at index 2 of s to obtain "??abc".
   Note that stamp must be fully contained in the boundaries of s in order to stamp (i.e., you cannot place stamp at index 3 of s).

   We want to convert s to target using at most 10 321.CreateMaximumNumber 321.CreateMaximumNumber.cc 321.CreateMaximumNumber.h 84.LargestRectangleinHistogram 84.LargestRectangleinHistogram.cc 84.LargestRectangleinHistogram.h 895.MaximumFrequencyStack 895.MaximumFrequencyStack.cc 895.MaximumFrequencyStack.h 936.StampingTheSequence.cc 936.StampingTheSequence.h head.cc head.h head.o lib.a l.sh makefile target.length turns.

   Return an array of the index of the left-most letter being stamped at each turn. If we cannot obtain target from s within 10 321.CreateMaximumNumber 321.CreateMaximumNumber.cc 321.CreateMaximumNumber.h 84.LargestRectangleinHistogram 84.LargestRectangleinHistogram.cc 84.LargestRectangleinHistogram.h 895.MaximumFrequencyStack 895.MaximumFrequencyStack.cc 895.MaximumFrequencyStack.h 936.StampingTheSequence.cc 936.StampingTheSequence.h head.cc head.h head.o lib.a l.sh makefile target.length turns, return an empty array.



   Example 1:

Input: stamp = "abc", target = "ababc"
Output: [0,2]
Explanation: Initially s = "?????".
- Place stamp at index 0 to get "abc??".
- Place stamp at index 2 to get "ababc".
[1,0,2] would also be accepted as an answer, as well as some other answers.

Example 2:

Input: stamp = "abca", target = "aabcaca"
Output: [3,0,1]
Explanation: Initially s = "???????".
- Place stamp at index 3 to get "???abca".
- Place stamp at index 0 to get "abcabca".
- Place stamp at index 1 to get "aabcaca".



Constraints:

1 <= stamp.length <= target.length <= 1000
stamp and target consist of lowercase English letters.

*/
#include"head.h"
class Solution {
	public:
		vector<int> movesToStamp(string stamp, string target) {
			int ssize=stamp.size(),tsize=target.size(),n=0,time=0;
			vector<bool> visit(tsize,false);
			vector<int> res;
			bool flag=true;
			while(flag&&n<tsize)
			{
				flag=false;
				for(int i=0;i<=tsize-ssize;i++)
				{
					int l=check(stamp,target,i);
					if(l==0)
						continue;
					flag=true;
					n+=l;
					time++;
					res.push_back(i);
				}
			}
			reverse(res.begin(),res.end());
			return time<10*tsize&&n==tsize?res:vector<int>();
		}
		int check(string s,string &t,int start)
		{
			int l=s.size();
			for(int i=0;i<s.size();i++)
			{
				if(t[i+start]=='?')
					l--;
				else if(s[i]!=t[i+start])
					return 0;
			}
			
			if(l)
			for(int i=0;i<s.size();i++)
				if(s[i]==t[i+start])
					t[i+start]='?';
			return l;
		}
};
