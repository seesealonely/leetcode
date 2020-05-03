#include"17.h"
int main()
{
	Solution s;
	string s1("3");
	vector<string> v;
v=s.letterCombinations(s1);
for(vector<string>::iterator i=v.begin();i!=v.end();i++)
cout<<*i<<endl;

return 0;
}
