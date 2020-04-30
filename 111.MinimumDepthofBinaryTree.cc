/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

#include"111.MinimumDepthofBinaryTree.h"

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
	struct	TreeNode *r=buildTree();
	Solution s;
	cout<<s.minDepth(r)<<endl;
	return 0;
}
