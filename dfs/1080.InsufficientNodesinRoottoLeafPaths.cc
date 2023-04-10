/*
   Given the root of a binary tree and an integer limit, delete all insufficient nodes in the tree simultaneously, and return the root of the resulting binary tree.

   A node is insufficient if every root to leaf path intersecting this node has a sum strictly less than limit.

   A leaf is a node with no children.



   Example 1:

Input: root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
Output: [1,2,3,4,null,null,7,8,9,null,14]

Example 2:

Input: root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
Output: [5,4,8,11,null,17,4,7,null,null,null,5]

Example 3:

Input: root = [1,2,-3,-5,null,4,null], limit = -1
Output: [1,null,-3,4]



Constraints:

The number of nodes in the tree is in the range [1, 5000].
-105 <= Node.val <= 105
-109 <= limit <= 109

*/


#include"head.h"
class Solution {
	public:
		TreeNode* sufficientSubset(TreeNode* root, int limit) {
			dfs(root,limit,root->val);
			return root;
		}
		void dfs(TreeNode *&root,int limit,int sum)
		{
			if(!root->left&&!root->right)
			{
				if(sum<limit)
					root=NULL;
				return ;
			}

			if(root->left)
				dfs(root->left,limit,sum+root->left->val);

			if(root->right)
				dfs(root->right,limit,sum+root->right->val);

			if(!root->left&&!root->right)
				root=NULL;
		}
};


int main() 
{
	Solution s;
	show(s.sufficientSubset(buildTree(),1));
	return 0;
}
