#include"434.h"
int main()
{
	string ss("Hello, my name is John");
	Solution s;
	cout<<s.countSegments(ss)<<endl;
	string s1("a, b, c");
	cout<<s.countSegments(s1)<<endl;
	return 0;
}
