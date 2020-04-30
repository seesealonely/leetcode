#include"112.h"
int main()
{
	Solution s;
	TreeNode *root=s.buildTree();
	cout<<s.hasPathSum(root,0)<<endl;
	return 0;
}
