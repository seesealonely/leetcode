/*
   Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

   For example:
   Given the following binary tree,

   1            <---
   /   \
   2     3         <---
   \     \
   5     4       <---

   You should return [1, 3, 4]. 
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
		vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		dfs(root,res,0);
		return res;
		}
	private:
		void dfs(TreeNode *root,vector<int> &res,int depth)
		{
			if(!root) return;
			//if(!root->right) root=root->left;
			if(depth==res.size()) res.push_back(root->val);
			dfs(root->right,res,depth+1);
			dfs(root->left,res,depth+1);
		}
};
