/*
   You are given an array arr of size n consisting of non-empty strings.

   Find a string array answer of size n such that:

   answer[i] is the shortest
   substring
   of arr[i] that does not occur as a substring in any other string in arr. If multiple such substrings exist, answer[i] should be the
   lexicographically smallest
   . And if no such substring exists, answer[i] should be an empty string.

   Return the array answer.



   Example 1:

Input: arr = ["cab","ad","bad","c"]
Output: ["ab","","ba",""]
Explanation: We have the following:
- For the string "cab", the shortest substring that does not occur in any other string is either "ca" or "ab", we choose the lexicographically smaller substring, which is "ab".
- For the string "ad", there is no substring that does not occur in any other string.
- For the string "bad", the shortest substring that does not occur in any other string is "ba".
- For the string "c", there is no substring that does not occur in any other string.

Example 2:

Input: arr = ["abc","bcd","abcd"]
Output: ["","","abcd"]
Explanation: We have the following:
- For the string "abc", there is no substring that does not occur in any other string.
- For the string "bcd", there is no substring that does not occur in any other string.
- For the string "abcd", the shortest substring that does not occur in any other string is "abcd".



Constraints:

n == arr.length
2 <= n <= 100
1 <= arr[i].length <= 20
arr[i] consists only of lowercase English letters.

*/

#define c11
#include"head.h"
class Node {
	public:
		Node *next[26];
		unordered_set<int> idx;
		Node()
		{
			memset(next,0,sizeof(next));
		}
};
class Solution {
	public:
		vector<string> shortestSubstrings(vector<string>& arr) {
			root=new Node();
			const int n=arr.size();
			for(int i=0;i<n;i++)
			{
				const int m=arr[i].size();
				for(int j=0;j<m;j++)
				{
					Node *p=root;
					for(int k=j;k<m;k++)
					{
						int c=arr[i][k]-'a';
						if(p->next[c]==NULL)
							p->next[c]=new Node();

						p=p->next[c];
						p->idx.insert(i);
					}
				}
			}

			vector<string> res(n);
			for(int i=0;i<n;i++)
			{
				const int m=arr[i].size();
				int mx=m+1;
				for(int j=0;j<m;j++)
				{
					string sub;
					Node *p=root;

					for(int k=j;k<m&&mx>=k-j+1;k++)
					{
						sub+=arr[i][k];
						p=p->next[arr[i][k]-'a'];

						if(p->idx.size()>1)
							continue;

						if(mx>k-j+1||(mx==k-j+1&&res[i]>sub))
								res[i]=sub;
						mx=k-j+1;
					}
				}
			}
			return res;
		}
	private:
		Node *root;
};


int main() 
{
	Solution s;
	vector<string> arr = {"cab","ad","bad","c"};
	show(s.shortestSubstrings(arr));
	arr.clear();arr = {"abc","bcd","abcd"};
	show(s.shortestSubstrings(arr));
	return 0;
}
