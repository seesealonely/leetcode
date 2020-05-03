/*
 Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

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
void flatten(TreeNode* root) {
 if(!root) return;
stack<TreeNode *> st;
TreeNode *cur=NULL;
	st.push(root);
	while(!st.empty())       
	{
		cur=st.top();st.pop();
		if(!cur->right) st.push(cur->right);
		if(!cur->left) st.push(cur->left);
		if(!st.empty()) cur->right=st.top();
		cur->left=NULL;
	}
    }
void flatten1(TreeNode* root) {
	if(!root) return ;
	flatten1(root->right);
	flatten1(root->left);
	root->right=prev;
	root->left=NULL;
	prev=root;
}
private:
TreeNode *prev=NULL;
};
