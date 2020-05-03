#include"412.h"
int main()
{
	Solution s;
	vector<string> res=s.fizzBuzz(15);
	for(int i=0;i<res.size();i++)
	{
	for(int j=0;j<res[i].size();j++)
		cout<<res[i][j]<<" ";
	cout<<endl;
	}
	return 0;
}
