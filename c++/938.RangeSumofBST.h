/*
Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.

 

Example 1:

Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
Output: 32

Example 2:

Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
Output: 23

 

Note:

    The number of nodes in the tree is at most 10000.
    The final answer is guaranteed to be less than 2^31.

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
    int rangeSumBST(TreeNode* root, int L, int R) {
	return usingStack(root,L,R);	
    }
    int usingStack(TreeNode* root, int L, int R) {
	if(!root) return 0;
	stack<TreeNode *> st;
	int res=0;
	while(root||!st.empty())
	{
		while(root)
		{
			st.push(root);
			root=root->left;
		}
		TreeNode *top=st.top();
		st.pop();
		if(top->val>=L&&top->val<=R)
			res+=top->val;	
		root=top->right;
	}
	return res;
    }
    int dfs(TreeNode* root, int L, int R) {
	if(!root) return 0;
	if(root->val<L)
		dfs(root->right,L,R);
	if(root->val>R)
		dfs(root->left,L,R);
	return root->val+dfs(root->left,L,R)+dfs(root->right,L,R);
	}
};
