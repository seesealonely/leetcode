/*
   Find the sum of all left leaves in a given binary tree.

Example:

3
/ \
9  20
/  \
15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

*/

#include"head.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	public:
		int dfs(TreeNode *root)
		{
			if(!root) return 0;
			int sum=0;
			if(root->left)
			{
				if(!root->left->left&&!root->left->right)
				sum+=root->left->val;
				else  sum+=dfs(root->left);
			}
			sum+=dfs(root->right);
			return sum;
		}
		int sumOfLeftLeaves(TreeNode* root) {
			return dfs(root);
		}
};
