#include"448.h"
int main()
{
	int vv[]={1,2,2,3,4,5,6,9,10};
	vector<int> v(vv,vv+9);
	Solution s;
	vector<int> res=s.findDisappearedNumbers(v);
	for(vector<int>::iterator it=res.begin();it!=res.end();++it)
	cout<<*it<<endl;
	return 0;
}
