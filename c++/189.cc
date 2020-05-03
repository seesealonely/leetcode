#include"189.h"
int main()
{
	int vv[]={1,2,3,4,5,6,7};
	vector<int> v(vv,vv+7);
	Solution s;
	s.rotate(v,4);
	return 0;
}
