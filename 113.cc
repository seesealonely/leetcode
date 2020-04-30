#include"113.h"
int main()
{
	vector<vector<int> > res;
	Solution s;
	TreeNode *root=s.buildTree();
	res=s.hasPathSum(root,22);
	for(int i=0;i<res.size();i++)
		for(int j=0;j<res[i].size();j++)
		cout<<res[i][j]<<" ";
	cout<<endl;
	return 0;
}
