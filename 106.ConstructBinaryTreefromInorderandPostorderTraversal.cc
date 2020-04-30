/*
   Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/

#include"106.ConstructBinaryTreefromInorderandPostorderTraversal.h"

int main()
{
	int i1[]={2,1,3};
	int p1[]={2,3,1};
	vector<int> i(i1,i1+3),p(p1,p1+3);
	Solution s;
	show(s.buildTree(i,p));
	cout<<endl;
	return 0;
}
