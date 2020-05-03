#include"283.h"
int main()
{
	Solution s;
	int v[]={0,1,0,3,12};
	vector<int > vv(v,v+5);
	for(int i=0;i<vv.size();i++)
	cout<<vv[i]<<" ";
	cout<<endl;
	s.moveZeroes(vv);
	for(int i=0;i<vv.size();i++)
	cout<<vv[i]<<" ";
	cout<<endl;
	return 0;
}
