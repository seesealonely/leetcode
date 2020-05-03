/*
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

The length of path between two nodes is represented by the number of edges between them.

 

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5

Output: 2

 

Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5

Output: 2

 

Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.

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
    int longestUnivaluePath(TreeNode* root) {
       res=0; 
	dfs(root);	
	return res;
    }
    int dfs(TreeNode* root) {
	if(!root) return 0;
	int left=root->left==NULL?0:dfs(root->left);
	int right=root->right==NULL?0:dfs(root->right);
	int resl=root->left!=NULL&&root->left->val==root->val?left+1:0;
	int resr=root->right!=NULL&&root->right->val==root->val?right+1:0;
	res=max(res,resl+resr);
	return max(resl,resr);
    }
private:
	int res;
};
