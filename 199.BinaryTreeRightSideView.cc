/*
   Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

   For example:
   Given the following binary tree,

   1            <---
   /   \
   2     3         <---
   \     \
   5     4       <---

   You should return [1, 3, 4]. 
   */

#include"199.BinaryTreeRightSideView.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int main()
{
	struct TreeNode *r=buildTree();	
	Solution s;
	show(s.rightSideView(r));
	return 0;
}
