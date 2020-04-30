#include"119.h"
int main()
{
	Solution s;
	vector<int> res=s.generate(5);
	for(int i=0;i<res.size();i++)
			cout<<res[i]<<" ";
		cout<<endl;
	res=s.generate(3);
	for(int i=0;i<res.size();i++)
			cout<<res[i]<<" ";
		cout<<endl;
	return 0;
}
