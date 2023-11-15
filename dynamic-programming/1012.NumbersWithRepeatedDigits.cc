/*
   Given an integer n, return the number of positive integers in the range [1, n] that have at least one repeated digit.



   Example 1:

Input: n = 20
Output: 1
Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.

Example 2:

Input: n = 100
Output: 10
Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.

Example 3:

Input: n = 1000
Output: 262



Constraints:

1 <= n <= 109

*/


#include"head.h"
class Solution {
	public:
		int numDupDigitsAtMostN(int n) {
		string s=to_string(n);
		int m=s.size();
		vis=vector<vector<int>>(m,vector<int>(1<<10,-1));
		return n-dfs(0,0,true,false,m,s);
		}
	private:
		vector<vector<int>> vis;
		int dfs(int i,int mask,bool limit,bool pre,int m,const string &s)
		{
			if(i==m)
				return pre;
			if(!limit&&pre&&vis[i][mask]!=-1)
				return vis[i][mask];

			int res=0;
			if(!pre)
				res=dfs(i+1,mask,false,false,m,s);
			int mx=limit?s[i]-'0':9;
			for(int j=1-pre;j<=mx;j++)
				if((mask>>j&1)==0)
					res+=dfs(i+1,mask|(1<<j),limit&&j==mx,true,m,s);
			if(!limit&&pre)
				vis[i][mask]=res;
			return res;
		}
};


int main() 
{
	Solution s;
	cout<<s.numDupDigitsAtMostN(20)<<endl;
	cout<<s.numDupDigitsAtMostN(100)<<endl;
	cout<<s.numDupDigitsAtMostN(1000)<<endl;
	return 0;
}
