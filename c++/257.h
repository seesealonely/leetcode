#include<iostream>
#include<vector>
#include<string>
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
    vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> res;
	string one;
	dfs(root,res,one);        
	return res;
    }
	void dfs(TreeNode *root,vector<string> &res,string one)
	{
		if(!root) return;
		one.push_back(root->val);
		if(!root->left&&!root->right)
		res.push_back(one);
		dfs(root->left,res,one+"->");
		dfs(root->right,res,one+"->");
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
