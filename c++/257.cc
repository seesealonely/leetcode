#include"257.h"
int main()
{
	vector<string> res;
	Solution s;
	TreeNode *root=s.buildTree();
	res=s.binaryTreePaths(root);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	cout<<endl;
	return 0;
}
