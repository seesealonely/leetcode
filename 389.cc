#include"389.h"
int main()
{
	Solution s;
	string ss("abcd");
	string t("abcde");
	cout<<s.findTheDifference(ss,t)<<endl;
	string s1("a");
	string t1("aa");
	cout<<s.findTheDifference(s1,t1)<<endl;
	return 0;
}
