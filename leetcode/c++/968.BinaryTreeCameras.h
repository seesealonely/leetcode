/*
   You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

   Return the minimum number of cameras needed to monitor all nodes of the tree.



   Example 1:

Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.

Example 2:

Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.



Constraints:

The number of nodes in the tree is in the range [1, 1000].
Node.val == 0

*/
#include"head.h"
class Solution {
	public:
		int minCameraCover(TreeNode* root) {
		int res=0;
		if(dfs(root,res)==0)
			res++;
		return res;
		}
		int dfs(TreeNode *root,int &res)
		{
			if(!root) return 2;
			int left=dfs(root->left,res),right=dfs(root->right,res);
			if(left==0||right==0)
			{
				res++;
				return 1;
			}
			return left==1||right==1?2:0;
		}
};
