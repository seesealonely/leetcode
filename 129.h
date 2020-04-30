#include<iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution 
{
	public:
		int sumNumbers(TreeNode* root) 
		{
			return dfs(root,0);
		}
		int dfs(TreeNode *root,int res)
		{
			res=10*res+root->val;	
			if(!root->left&&!root->right) return res;
			return dfs(root->left,res)+dfs(root->right,res);
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
