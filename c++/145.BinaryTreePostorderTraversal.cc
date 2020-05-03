/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

#include"145.BinaryTreePostorderTraversal.h"

int main()
{
	TreeNode *r=buildTree();
	Solution s;
	show(s.postorderTraversal(r));
	return 0;
}
