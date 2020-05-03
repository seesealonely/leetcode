#include"47.PermutationsII.h"
int main()
{
	int vv[]={1,1,1,2,3};
	vector<int> v(vv,vv+5);
	Solution s;
	vector<vector<int> > res=s.permuteUnique(v);	
	s.show(res);
}
