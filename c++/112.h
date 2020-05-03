#include<iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	public:
		bool hasPathSum(TreeNode* root, int sum) 
		{
			if(!root) return false;
			if(!root->left&&!root->right&&sum==root->val)
			return true;
			return	hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
		}
		TreeNode *buildTree()
		{
			const int max=9;
			int input=0;
			cin>>input;
			TreeNode *root;
			if(input<max)
			{
				root=new TreeNode(input);
				root->left=buildTree();
				root->right=buildTree();
			}	
			return input>=max?NULL:root;
		}
};
