/*
   Given the root of a binary tree, each node in the tree has a distinct value.

   After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

   Return the roots of the trees in the remaining forest. You may return the result in any order.



   Example 1:

Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]

Example 2:

Input: root = [1,2,4,null,3], to_delete = [3]
Output: [[1,2,4]]



Constraints:

The number of nodes in the given tree is at most 1000.
Each node has a distinct value between 1 and 1000.
to_delete.length <= 1000
to_delete contains distinct values between 1 and 1000.



*/
#define c11
#include"head.h"
class Solution {
	public:
		vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		for(int i=0;i<to_delete.size();i++)
			todelete.insert(to_delete[i]);
		dfs(root,todelete,res,true);
		return res;
		}
		TreeNode *dfs(TreeNode *root,unordered_set<int> &todelete,vector<TreeNode*> &res,bool isroot)
		{
			if(!root) return NULL;
			bool isdelete=todelete.count(root->val)?true:false;
			if(isroot&&!isdelete) res.push_back(root);
			root->left=dfs(root->left,todelete,res,isdelete);
			root->right=dfs(root->right,todelete,res,isdelete);
			return isdelete?NULL:root;
		}
	private:
		unordered_set<int> todelete;
		vector<TreeNode *> res;
};
