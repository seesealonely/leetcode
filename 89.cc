#include"89.h"
int main()
{
	Solution s;
	vector<int> res=s.grayCode(9);
	for(int i=0;i<res.size();i++)
	cout<<res[i]<<" ";
	cout<<endl;
	return 0;
}
