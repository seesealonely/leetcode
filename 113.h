#include<iostream>
#include<vector>
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
class Solution {
	public:
		vector<vector<int> > hasPathSum(TreeNode* root, int sum)
		{
			vector<vector<int> > res;
			vector<int> one; 
			dfs(root,sum,res,one);
			return res;
		}
		void dfs(TreeNode *root,int sum,vector<vector<int> > & res,vector<int> one)
		{
			if(!root) return ;
			one.push_back(root->val);
			if(!root->left&&!root->right&&sum==root->val)
				res.push_back(one);
			dfs(root->left,sum-root->val,res,one);
			dfs(root->right,sum-root->val,res,one);
		}
		TreeNode *buildTree()
		{
			const int max=99;
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
