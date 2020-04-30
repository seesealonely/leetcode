/*
   Given an encoded string, return it's decoded string.

   The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

   You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

   Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

*/

#include"head.h"

class Solution {
	public:
		string decodeString(string s) {
			return usingStack(s);
			return dfs(s,0);        
		}
	private:
		string usingStack(string s)
		{
			string res,sub;
			stack<int> cstack;
			stack<string> sstack;
			for(int i=0;i<s.size();i++)
			{
				if(isdigit(s[i]))
				{
					int c=s[i]-'0';
					while(isdigit(s[i+1]))
						c=c*10+s[++i]-'0';
					cstack.push(c);
				}	
				else if(s[i]=='[')
				{
					sstack.push(res);
					res="";
				}
				else if(s[i]==']')
				{
					sub=sstack.top();sstack.pop();
					for(int i=cstack.top();i>0;i--)
					sub+=res;
					cstack.pop();	
					res=sub;
				}
				else
				res+=s[i];
			}
			return res;
		}

		string dfs(string s,int begin)
		{
			string res(""),recurRes;
			int num=0;
			while(begin<s.size()&&s[begin]!=']')
			{
				if(!isdigit(s[begin]))//&&s[begin]!='['&&s[begin]!=']')
					res+=s[begin++];	
				else
				{
					while(begin<s.size()&&isdigit(s[begin]))
						num=num*10+s[begin++]-'0';
					begin++;// skip [	
					recurRes=dfs(s,begin);	
					begin+=recurRes.size()+1;// skip ]		
					while(num-->0) res+=recurRes;
					num=0;
				}
			}
			return res;
		}
};
