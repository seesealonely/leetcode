/*
   Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.



   Example 1:

Input: n = 13
Output: 6

Example 2:

Input: n = 0
Output: 0



Constraints:

0 <= n <= 109

*/


#include"head.h"
class Solution {
	public:
		int countDigitOne(int n) {
		string s=to_string(n);

		int len=s.size();
		if(len==1) return  n>0?1:0;

		vector<int> pre(len,0),suf(len,0);
		suf[0]=stoi(s.substr(1));
		for(int i=1;i<len-1;i++)
		{
			pre[i]=stoi(s.substr(0,i));
			suf[i]=stoi(s.substr(i+1));
		}
		pre[len-1]=stoi(s.substr(0,len-1));

		int res=0;
		for(int i=0;i<len;i++)
		{
			int c=s[i]-'0',m=len-i-1;

			int pr=pre[i],su=suf[i],tot=0;
			tot+=pr*pow(10,m);
			if(c==1)
				tot+=su+1;
			else if(c>1)
				tot+=pow(10,m);
			res+=tot;
		}
		return res;
		}
};


int main() 
{
	Solution s;
	cout<<s.countDigitOne(13)<<endl;
	cout<<s.countDigitOne(0)<<endl;
	return 0;
}
