#include<iostream>
#include<stack>
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
		vector<int> inorderTraversal(TreeNode* root)
		{
			stack<TreeNode *> st;
			vector<int> res;
			while(root)
			{
				st.push(root);
				root=root->left;
			}
			TreeNode *tmp;
			while(!st.empty())
			{
				tmp=st.top();	
				st.pop();
				res.push_back(tmp->val);
				tmp=tmp->right;
				while(tmp) 
				{
					st.push(tmp);
					tmp=tmp->left;
				}
			}
			return res;
		}
};
