#include"144.h"
int  main()
{
	Solution s;
	TreeNode *root=s.buildTree();
	vector<int> res=s.preorderTraversal(root);
	for(int i=0;i<res.size();i++)
	cout<<res[i]<<" ";
	cout<<endl;
	return 0;
}
