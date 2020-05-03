#include"31.h"
int main()
{
	int vv[]={1,3,2,4};
	vector<int > v(vv,vv+4);
	Solution s;
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";	
	cout<<endl;
	s.nextPermutation(v);
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";	
	cout<<endl;
	return 0;
}
