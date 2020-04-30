/*
   Given a binary tree, return the postorder traversal of its nodes' values.

   For example:
   Given binary tree {1,#,2,3},

   1
   \
   2
   /
   3

   return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
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
		vector<int> postorderTraversal(TreeNode* root) {
			vector<int> res;
			if(!root) return res;
			stack<TreeNode *> s;
			s.push(root);
			TreeNode *p=NULL;
			while(!s.empty())
			{
				p=s.top();
				s.pop();
				res.insert(res.begin(),p->val);
				if(p->left) s.push(p->left);
				if(p->right) s.push(p->right);
			}
			return res;
		}
	private:
		void dfs(TreeNode *root,vector<int> &res)
		{
			if(!root) return;
			dfs(root->left,res);
			dfs(root->right,res);
			res.push_back(root->val);
		}
		vector<int> iterator(TreeNode *root)
		{
			vector<int> res;
			stack<TreeNode *> st;
			TreeNode *cur=root,*last=NULL,*top;
			while(cur||!st.empty())
			{
				if(cur) 
				{
					st.push(cur);
					cur=cur->left;
				}
				else
				{
					top=st.top();
					if(top->right&&last!=top->right)
						cur=top->right;
					else
					{
						res.push_back(top->val);
						last=top;
						st.pop();
					}
				}
			}
			return res;
		}
};
