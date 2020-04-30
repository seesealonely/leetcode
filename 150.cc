#include"150.h"
int main()
{
	vector<string> ss;
	ss.push_back("4");
	ss.push_back("13");
	ss.push_back("5");
	ss.push_back("/");
	ss.push_back("+");
	Solution s;
	cout<<s.evalRPN(ss)<<endl;
	return 0;
}
