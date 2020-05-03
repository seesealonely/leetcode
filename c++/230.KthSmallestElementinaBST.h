/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ? k ? BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
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
    int kthSmallest(TreeNode* root, int k) {
       int num=0;
	 num=numberNode(root->left);
	if(k<=num) return kthSmallest(root->left,k);
	else if(k>num+1) return kthSmallest(root->right,k-num-1);
	return root->val; 
    }
int numberNode(TreeNode *root)
{
	if(!root) return 0;
	return 1+numberNode(root->left)+numberNode(root->right);
}
};
