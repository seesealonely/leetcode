#include"260.h"
int main()
{
	int vv[]={1, 2, 1, 3, 2, 5};
	vector<int> v(vv,vv+6);
	Solution s;
	vector<int> res=s.singleNumber(v);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	cout<<endl;
	return 0;
}
