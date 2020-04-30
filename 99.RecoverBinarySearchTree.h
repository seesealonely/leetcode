/*
 Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
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
    void recoverTree(TreeNode* root) {
	TreeNode *pre=new TreeNode(INT_MAX);
	first=second=NULL;
	dfs(root);
	int temp=first->val;
	first->val=second->val;
	second->val=temp; 
	return ;
    }
	void dfs(TreeNode *root)
	{
		if(!root) return;
		dfs(root->left);
		if(!first&&pre->val>=root->val)
			first=pre;
		if(first&&pre->val>=root->val)
			second=root;
		pre=root;
		dfs(root->right);
	}
private: TreeNode *first,*second,*pre;
};
