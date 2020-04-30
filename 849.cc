/*
*/

#include"849.h"

int main()
{
	vector<int> v1(7,0);
	vector<int> v2(4,0);
	v1[0]=v1[4]=v1[6]=1;v2[0]=1;
	Solution s;
	cout<<s.maxDistToClosest(v1)<<endl;
	cout<<s.maxDistToClosest(v2)<<endl;
	return 0;
}
