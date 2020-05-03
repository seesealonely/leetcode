#include<iostream>
#include<cstdlib>
#include<stack>
#include<vector>
#include<string>
using namespace std;
class Solution {
	public:
		int evalRPN(vector<string>& tokens) {
			stack<int> st;
			int res=0;
			for(int i=0;i<tokens.size();i++)
			{
				if(tokens[i]=="+")
				{
					res=st.top();
					st.pop();
					res+=st.top();
					st.pop();
					st.push(res);
				}
				else if(tokens[i]=="-")
				{
					res=st.top();
					st.pop();
					res=st.top()-res;
					st.pop();
					st.push(res);
				}
				else if(tokens[i]=="*")
				{
					res=st.top();
					st.pop();
					res*=st.top();
					st.pop();
					st.push(res);
				}
				else if(tokens[i]=="/")
				{
					res=st.top();
					st.pop();
					res=st.top()/res;
					st.pop();
					st.push(res);
				}
				else if(tokens[i]==",");
				else
				{
					st.push(atoi(tokens[i].c_str()));
				}
			} 	       
			return st.top();
		}
};
