/*
Given preorder and inorder traversal of a tree, construct the binary tree.

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	return dfs(preorder,inorder,0,0,preorder.size()-1);     
    }
TreeNode * dfs(vector<int> &p,vector<int> &in,int pre,int beg,int end)
{
	if(pre>p.size()-1||beg>end)
	return NULL;
	TreeNode *root=new TreeNode (p[pre]);
	int index=0;
	for(int i=beg;i<=end;++i)
	if( in[i]==root->val) index=i;
	root->left=dfs(p,in,pre+1,beg,index-1);
	root->right=dfs(p,in,pre+index-beg+1,index+1,end);
	return root;
}
};
