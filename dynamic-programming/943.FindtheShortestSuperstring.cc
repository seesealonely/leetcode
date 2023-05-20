/*
   Given an array of strings words, return the smallest string that contains each string in words as a substring. If there are multiple valid strings of the smallest length, return any of them.

   You may assume that no string in words is a substring of another string in words.



   Example 1:

Input: words = ["alex","loves","leetcode"]
Output: "alexlovesleetcode"
Explanation: All permutations of "alex","loves","leetcode" would also be accepted.

Example 2:

Input: words = ["catg","ctaagt","gcta","ttca","atgcatc"]
Output: "gctaagttcatgcatc"



Constraints:

1 <= words.length <= 12
1 <= words[i].length <= 20
words[i] consists of lowercase English letters.
All the strings of words are unique.

*/


#include"head.h"
class Solution {
	public:
		string shortestSuperstring(vector<string>& words) {
		const int n=words.size();

		vector<vector<int>> dp(1<<n,vector<int>(n,12*20+1));
		vector<vector<int>> idx(1<<n,vector<int>(n,-1));
		vector<vector<int>> contain(n,vector<int>(n,0));

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				contain[i][j]=getContain(words[i],words[j]);

		for(int i=0;i<n;i++)
			dp[1<<i][i]=words[i].size();

		for(int s=0;s<(1<<n);s++)
			for(int i=0;i<n;i++)
				if(s&(1<<i))
					for(int j=0;j<n;j++)
						if(!(s&(1<<j)))
							if(dp[s|(1<<j)][j]>dp[s][i]+words[j].size()-contain[i][j])
							{
								dp[s|(1<<j)][j]=dp[s][i]+words[j].size()-contain[i][j];
								idx[s|(1<<j)][j]=i;
							}
		int mn=12+20+1,k=-1;

		for(int i=0;i<n;i++)
			if(mn>=dp[(1<<n)-1][i])
				mn=dp[(1<<n)-1][i],
				k=i;
		string res=string(mn,' ');
		int s=(1<<n)-1,pos=mn;

		while(true)
		{
			for(int i=pos-words[k].size(),j=0;i<pos&&j<words[k].size();i++,j++)
				res[i]=words[k][j];

			if(idx[s][k]==-1)
				break;

			pos=pos-words[k].size()+contain[idx[s][k]][k];
			int newk=idx[s][k];
			s=s-(1<<k);
			k=newk;
		}
	
		return res;
		}
		int getContain(const string &x,const string &y)
		{
			const int m=x.size(),n=y.size();
			for(int s=0;s<m;s++)
			{
				bool flag=true;
				for(int i=s,j=0;j<n&&i<m;i++,j++)
					if(x[i]!=y[j])
					{
						flag=false;
						break;
					}
				if(flag) return m-s;
			}
			return 0;
		}
};


int main() 
{
	Solution s;
	vector<string> words={"alex","loves","leetcode"};
	cout<<s.shortestSuperstring(words)<<endl;
	words.clear();words={"catg","ctaagt","gcta","ttca","atgcatc"};
	cout<<s.shortestSuperstring(words)<<endl;
	words.clear();words={"ab","a","b"};
	cout<<s.shortestSuperstring(words)<<endl;
	return 0;
}
