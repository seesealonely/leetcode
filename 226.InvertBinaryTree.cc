/*
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9

to

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include"226.InvertBinaryTree.h"

int main()
{
	struct TreeNode *r=buildTree();
	cout<<r<<endl;
	Solution s;	
	struct TreeNode *rr=s.invertTree(r);
	cout<<rr<<endl;
	show(rr);
	return 0;
}
