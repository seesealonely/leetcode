#include"414.h"
int main()
{
	int v[]={3,2,1};
	vector<int > vv(v,v+3);
	int v1[]={1,2};
	vector<int > v11(v1,v1+2);
	int v2[]={2,2,3,1};
	vector<int > v22(v2,v2+4);
	Solution s;
	cout<<s.thirdMax(vv)<<endl;
	cout<<s.thirdMax(v11)<<endl;
	cout<<s.thirdMax(v22)<<endl;
	return 0;
}
