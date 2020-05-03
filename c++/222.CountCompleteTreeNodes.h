/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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
    int countNodes(TreeNode* root) {
	if(!root) return 0;
	int left=0,right=0;
	for(TreeNode *l=root;l;l=l->left) ++left; 
	for(TreeNode *r=root;r;r=r->right) ++right;
	if(left==right) return (1<<(left))-1;
	return countNodes(root->left)+countNodes(root->right)+1;
    }
};
