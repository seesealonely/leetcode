/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree. 
*/

#include"105.ConstructBinaryTreefromPreorderandInorderTraversal.h"

int main()
{
	int pr[]={1,2,3};
	int in[]={2,1,3};
	vector<int> p(pr,pr+3) ,i(in,in+3);
	Solution s;
	show(s.buildTree(p,i));
	return 0;
}
