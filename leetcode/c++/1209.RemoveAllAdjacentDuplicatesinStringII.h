/*
   You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

   We repeatedly make k duplicate removals on s until we no longer can.

   Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.



   Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.

Example 2:

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation:
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"

Example 3:

Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"



Constraints:

1 <= s.length <= 105
2 <= k <= 104
s only contains lower case English letters.

*/
#include"head.h"
class Solution {
	public:
		string removeDuplicates(string s, int k) {
		return usingTwoPointers(s,k);
		return usingStack(s,k); 

		}
		string usingStack(string s, int k) {
			string res;
			stack<pair<int,char> > st;
			for(int i=0;i<s.size();i++)
				if(st.empty()||s[i]!=st.top().second)
					st.push({1,s[i]});
				else if(++st.top().first==k)
					st.pop();
			while(!st.empty())
			{
				res=string(st.top().first,st.top().second)+res;
				st.pop();
			}
			return res;
		}
		string usingTwoPointers(string s, int k) {
			int i=0,j=0,n=s.size();
			vector<int> count(n,0);
			for(;j<n;i++,j++)
			{
				s[i]=s[j];
				count[i]=i>0&&s[i]==s[i-1]?count[i-1]+1:1;
				if(count[i]==k)
					i-=k;
			}
			return s.substr(0,i);
		}
};
