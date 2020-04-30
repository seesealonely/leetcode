#include"513.h"
int main()
{
	Solution s;
	TreeNode* root=s.buildTree();
	cout<<s.findBottomLeftValue(root)<<endl;
	return 0;
}
