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
		int findBottomLeftValue(TreeNode* root) 
		{
			int res;
			int pre=0;
			dfs(root,1,pre,res);        
			return res;
		}
		void dfs(TreeNode *root,int depth,int &pre,int &res)
		{
			if(!root) return;
			if(pre<depth)
			{	
				pre=depth;
				res=root->val;
			}
			dfs(root->left,depth+1,pre,res);
			dfs(root->right,depth+1,pre,res);
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
