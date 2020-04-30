#include"263.h"
int main()
{
	Solution s;
	cout<<"2 ";
	s.print(s.isUgly(2));
	cout<<endl;
	cout<<"1024 ";
	s.print(s.isUgly(1024));
	cout<<endl;
	cout<<"7 ";
	s.print(s.isUgly(7));
	cout<<endl;
	cout<<"5 ";
	s.print(s.isUgly(5));
	cout<<endl;
	cout<<"0 ";
	s.print(s.isUgly(0));
	cout<<endl;
	return 0;
}
