#include"167.h"
int main()
{
		Solution s;
		int vv[]={-3,3,4,90};
		vector<int> v(vv,vv+4);
	vector<int >	res=s.twoSum(v,0);
		for(int i=0;i<res.size();i++)
			cout<<res[i]<<" ";
			cout<<endl;
	return 0;
}
