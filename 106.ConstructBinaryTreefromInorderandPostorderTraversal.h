/*
   Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
		TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	return dfs(inorder,postorder,inorder.size()-1,0,inorder.size()-1);
		}
		TreeNode *dfs(vector<int> &in,vector<int> &po,int ro,int beg,int end)
		{
			if(beg>end||ro<0) return NULL;
			TreeNode *root=new TreeNode(po[ro]);
			int index;
			for(int i=0;i<in.size();++i)
				if(in[i]==po[ro])
				{
					index=i;
					break;
				}
			int add=index-beg;
			root->left=dfs(in,po,ro-(end-index)-1,beg,index-1);
			root->right=dfs(in,po,ro-1,index+1,end);
			return root;
		}
};
