#include<iostream>
#include<algorithm>
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
		vector<vector<int> > levelOrderBottom(TreeNode* root)
		{
			vector<vector<int> >res;
			dfs(res,root,0);
			reverse(res.begin(),res.end());
			return res;
		}
		TreeNode *buildTree()
		{
			int input=0;
			cin>>input;
TreeNode *root;
			if(input<99)
			{
				root=new TreeNode(input);
				root->left=buildTree();
				root->right=buildTree();
			}	
			return input>=99?NULL:root;
		}
	private:
		void dfs(vector<vector<int> > &res,TreeNode* root,int level)
		{
			if(!root) return;
			if(level==res.size())
			{
				res.push_back({});
			}
			res[level].push_back(root->val);
			dfs(res,root->left,level+1);
			dfs(res,root->right,level+1);
		}
};
