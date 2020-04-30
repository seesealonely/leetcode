#include"20.h"
int main(void)
{
	Solution s;

	string s1("[");
	string s2("hfdah[dalj]fdfd");
	string s3("hfdah[dalj]fdf}");
	string s4("hfdah[dalj]}fdf}");
	string s5("{{hfdah[dalj]}fdf}");
cout<<	s.isValid(s1)<<endl;
cout<<	s.isValid(s2)<<endl;
cout<<	s.isValid(s3)<<endl;
cout<<	s.isValid(s4)<<endl;
cout<<	s.isValid(s5)<<endl;
return 0;
}
