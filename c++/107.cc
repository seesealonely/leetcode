#include"107.h"
int main()
{
	Solution s;
	TreeNode *root=s.buildTree();
	vector<vector<int> > res=s.levelOrderBottom(root);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
