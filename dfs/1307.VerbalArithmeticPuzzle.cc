/*
   Given an equation, represented by words on the left side and the result on the right side.

   You need to check if the equation is solvable under the following rules:

   Each character is decoded as one digit (0 - 9).
   No two characters can map to the same digit.
   Each words[i] and result are decoded as one number without leading zeros.
   Sum of numbers on the left side (words) will equal to the number on the right side (result).

   Return true if the equation is solvable, otherwise return false.



   Example 1:

Input: words = ["SEND","MORE"], result = "MONEY"
Output: true
Explanation: Map 'S'-> 9, 'E'->5, 'N'->6, 'D'->7, 'M'->1, 'O'->0, 'R'->8, 'Y'->'2'
Such that: "SEND" + "MORE" = "MONEY" , 9567 + 1085 = 10652

Example 2:

Input: words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
Output: true
Explanation: Map 'S'-> 6, 'I'->5, 'X'->0, 'E'->8, 'V'->7, 'N'->2, 'T'->1, 'W'->'3', 'Y'->4
Such that: "SIX" + "SEVEN" + "SEVEN" = "TWENTY" , 650 + 68782 + 68782 = 138214

Example 3:

Input: words = ["LEET","CODE"], result = "POINT"
Output: false
Explanation: There is no possible mapping to satisfy the equation, so we return false.
Note that two different characters cannot map to the same digit.



Constraints:

2 <= words.length <= 5
1 <= words[i].length, result.length <= 7
words[i], result contain only uppercase English letters.
The number of different characters used in the expression is at most 10.

*/


#include"head.h"
class Solution {
	public:
		bool isSolvable(vector<string>& words, string result) {
		int maxc=0;
		vector<int> hash(26,-1);

		for(int i=0;i<words.size();i++)
		{
			reverse(words[i].begin(),words[i].end());
			maxc=max(maxc,(int)words[i].size());
		}

		reverse(result.begin(),result.end());

		if(maxc!=result.size()&&maxc+1!=result.size())
			return false;

		maxc=max(maxc,(int)result.size());
		words.push_back(result);

		vector<bool> vis(10,false);
		return dfs(0,0,0,maxc,hash,vis,words);

		}
		int dfs(int r,int c,int carry,int maxc,vector<int>&hash,vector<bool> &vis,const vector<string> &words)
		{
			if(c==maxc)
				return carry==0;

			if(r==words.size())
			{
				int sum=carry;
				for(int i=0;i<words.size()-1;i++)
					if(c<words[i].size())
						sum+=hash[words[i][c]-'A'];
				if(sum%10!=hash[words.back()[c]-'A'])
						return false;

				return dfs(0,c+1,sum/10,maxc,hash,vis,words);
			}

			if(words[r].size()>1&&c==words[r].size()-1&&hash[words[r][c]-'A']==0)
				return false;

			if(c>=words[r].size()||hash[words[r][c]-'A']!=-1)
				return dfs(r+1,c,carry,maxc,hash,vis,words);

			for(int i=0;i<10;i++)
			{
				if(vis[i])
					continue;

				vis[i]=true;
				hash[words[r][c]-'A']=i;

				if(dfs(r+1,c,carry,maxc,hash,vis,words))
					return true;

				hash[words[r][c]-'A']=-1;
				vis[i]=false;
			}

			return false;
		}
};


int main() 
{
	Solution s;
	vector<string> words={"SEND","MORE"};
	cout<<s.isSolvable(words,"MONEY")<<endl;
	words.clear();words={"SIX","SEVEN","SEVEN"};
	cout<<s.isSolvable(words,"TWENTY")<<endl;
	words.clear();words={"LEET","CODE"};
	cout<<s.isSolvable(words,"POINT")<<endl;
	return 0;
}
