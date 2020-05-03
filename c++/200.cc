#include"200.h"
int main()
{
	vector<vector<char> > v;
	vector<char> v1;
	v1.push_back('1');
	v1.push_back('1');
	v1.push_back('0');
	v1.push_back('0');
	v1.push_back('0');
	vector<char> v2;
	v2.push_back('1');
	v2.push_back('1');
	v2.push_back('0');
	v2.push_back('0');
	v2.push_back('0');
	vector<char> v3;
	v3.push_back('0');
	v3.push_back('0');
	v3.push_back('1');
	v3.push_back('0');
	v3.push_back('0');
	vector<char> v4;
	v4.push_back('0');
	v4.push_back('0');
	v4.push_back('0');
	v4.push_back('1');
	v4.push_back('1');
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	Solution s;
cout<<	s.numIslands(v)<<endl;
	return 0;
}
