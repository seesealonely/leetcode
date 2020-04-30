#include<iostream>
#include<string>
#include<stack>
#include<iterator>
using namespace std;
class Solution {
	public:
		bool isValid(string s)
		{
		stack<char> st;
			for(string::iterator it=s.begin();it!=s.end();++it)
			{
				if((*it=='[')||(*it=='(')||(*it=='{'))
						st.push(*it);
				else if(*it==']')
				{
					if(st.empty())
						return  false;
					else if(st.top()!='[')
						return false;
					else st.pop();
				}
				else if(*it==')')
				{
					if(st.empty())
						return  false;
					else if(st.top()!='(')
						return false;
					else st.pop();
				}
				else if(*it=='}')
				{
					if(st.empty())
						return  false;
					else if(st.top()!='{')
						return false;
					else st.pop();
				}
			}
			if(st.empty())
				return true;
			else return false;
		}
};
