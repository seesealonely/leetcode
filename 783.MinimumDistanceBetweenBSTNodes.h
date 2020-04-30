/*
Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

Example :

Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

          4
        /   \
      2      6
     / \    
    1   3  

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.

Note:

    The size of the BST will be between 2 and 100.
    The BST is always valid, each node's value is an integer, and each node's value is different.


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
	TreeNode *pre;
	int res;
    int minDiffInBST(TreeNode* root) {
	pre=NULL;
	res=INT_MAX;	
	return dfs(root);
	return usingStack(root);
    }
    int dfs(TreeNode* root) {
	if(root->left) dfs(root->left);
	if(pre) res=min(res,abs(root->val-pre->val));
	pre=root;
	if(root->right) dfs(root->right);
	return res;
    }
    int usingStack(TreeNode* root) {
	stack<TreeNode*> st;
	TreeNode* top,*pre;
	int res=INT_MAX;
	pre=NULL;
	while(root||!st.empty())
	{
		while(root) 
		{
			st.push(root);
			root=root->left;
		}
		top=st.top();
		st.pop();
		if(pre)
			res=min(abs(pre->val-top->val),res);
		pre=top;
		root=top->right;
	}
	return res;
    }
};
