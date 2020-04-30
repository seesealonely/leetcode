#include"94.h"
int main()
{
	Solution s;
	TreeNode * root=s.buildTree();
	vector<int> res=s.inorderTraversal(root);
	for(int i=0;i<res.size();i++)
	cout<<res[i]<<" ";
	cout<<endl;

	return 0;
}
