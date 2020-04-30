/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]

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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
 	vector<vector<int> > res;
	dfs(root,0,res);	       
	return res;
    }
private:
	void dfs(TreeNode *root,int depth,vector<vector<int> > &res)
	{
		if(!root) return ;
		if(res.size()==depth) res.push_back({});
		if(depth%2==0) res[depth].push_back(root->val);
		else res[depth].insert(res[depth].begin(),root->val);
		dfs(root->left,depth+1,res);
		dfs(root->right,depth+1,res);
	}	
};
