#include<iostream>
#include<vector>
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
		vector<int> largestValues(TreeNode* root) 
		{
			vector<int> res;
			dfs(root,res,0);        
			return res;
		}
		void dfs(TreeNode *root,vector<int> &res,int level)
		{
			if(!root) return;
			if(level==res.size())
				res.push_back(root->val);
			if(root->val>res[level]) res[level]=root->val;
			dfs(root->left,res,level+1);
			dfs(root->right,res,level+1);
		}
};

