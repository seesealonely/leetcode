/*
*/


#include"head.h"
class Solution {
	public:
		vector<string> removeComments(vector<string>& source) {
			vector<string> res;
			string cur;
			bool flag=true;
			for(int i=0;i<source.size();i++)
			{
				string s=source[i];
				for(int j=0;j<s.size();j++)
				{
					if(flag)
					{
						if(s[j]=='/')
						{
							if(j+1<s.size()&&s[j+1]=='*')
							{
								flag=false;
								j++;
								continue;
							}
							else if(j+1<s.size()&&s[j+1]=='/')
								break;
						}
						cur+=s[j];
					}
					else
					{
						if(j+1<s.size()&&s[j]=='*'&&s[j+1]=='/')
						{
							flag=true;
							j++;
						}
					}
				}
				if(flag&&cur.size()) res.push_back(cur),cur="";
			}
			return res;
		}
};


int main() 
{
	Solution s;
	vector<string> v={"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"};
	show(s.removeComments(v));
	return 0;
}
