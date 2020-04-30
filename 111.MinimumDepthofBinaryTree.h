/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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

    int minDepth(TreeNode* root) {
        	return dfs(root);     
    }
private:
	int dfs(TreeNode *root)
		{
			if(!root) return 0;
			if(!root->left&&!root->right) return 1;
			if(!root->left) return dfs(root->right)+1;
			if(!root->right) return dfs(root->left)+1;
		return	min(dfs(root->left),dfs(root->right))+1;
		}
};
