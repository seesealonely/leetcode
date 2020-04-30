/*
   Return the root node of a binary search tree that matches the given preorder traversal.

   (Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

   Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]



Note: 

1 <= preorder.length <= 100
The values of preorder are distinct.

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
		TreeNode* bstFromPreorder(vector<int>& preorder) {
			return usingStack(preorder);        
		}
		TreeNode* usingStack(vector<int>& preorder) {
			if(!preorder.size()) return NULL;
			stack<TreeNode*> st;
			TreeNode *root=new TreeNode(preorder[0]);
			st.push(root);
			for(int i=1;i<preorder.size();i++)
			{
				TreeNode *node=new TreeNode(preorder[i]);
				if(preorder[i]<st.top()->val)
				{
					st.top()->left=node;		
				}
				else
				{
					TreeNode* parent;
					while(!st.empty()&&preorder[i]>st.top()->val)
					{
						parent=st.top();
						st.pop();
					}
					parent->right=node;
				}
					st.push(node);
			}
			return root;
		}
};
