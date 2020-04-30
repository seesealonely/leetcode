#include<iostream>
#include<vector>
#include<stack>
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
		vector<int> preorderTraversal(TreeNode* root) 
		{
			vector<int> res;
			if(!root) res;
			TreeNode *tmp;
			stack<TreeNode *> st;
			tmp=root;
			while(tmp)
			{
				res.push_back(tmp->val);
				st.push(tmp);
				tmp=tmp->left;
			}
			while(!st.empty())        
			{
				tmp=st.top();
				st.pop();	
				tmp=tmp->right;
				while(tmp) 
				{
					res.push_back(tmp->val);
					st.push(tmp);
					tmp=tmp->left;
				}
			}
			return res;
		}
		TreeNode *buildTree()
		{
			int input=10;
			cin>>input;
			TreeNode *root;
			if(input<9)
			{
				root=new TreeNode(input);
				root->left=buildTree();
				root->right=buildTree();
			}	
			return input>=9?NULL:root;
		}
};
