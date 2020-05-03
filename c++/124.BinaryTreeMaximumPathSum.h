/*
   Given a binary tree, find the maximum path sum.

   For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

   For example:
   Given the below binary tree,

   1
   / \
   2   3

   Return 6. 
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
		int maxPathSum(TreeNode* root) {
			maxLen=INT_MIN;        
			dfs(root);
			return maxLen;
		}

	private:
		int dfs(TreeNode *root)
		{
			if(!root) return 0;
			int left=max(0,dfs(root->left));
			int right=max(0,dfs(root->right));
				maxLen=max(maxLen,left+right+root->val);
				return max(left,right)+root->val;
		}
		int maxLen;
};
