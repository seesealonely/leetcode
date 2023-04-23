/*
   Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

   If there exist multiple answers, you can return any of them.



   Example 1:

Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]

Example 2:

Input: preorder = [1], postorder = [1]
Output: [1]



Constraints:

1 <= preorder.length <= 30
1 <= preorder[i] <= preorder.length
All the values of preorder are unique.
postorder.length == preorder.length
1 <= postorder[i] <= postorder.length
All the values of postorder are unique.
It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.

*/


#include"head.h"
class Solution {
	public:
		int preidx=0,postidx=0;
		TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
			TreeNode *root=new TreeNode(preorder[preidx++]);
			if(postorder[postidx]!=root->val)
				root->left=constructFromPrePost(preorder,postorder);
			if(postorder[postidx]!=root->val)
				root->right=constructFromPrePost(preorder,postorder);
			postidx++;
			return root;		
		}
};


int main() 
{
	Solution s;
	vector<int> pre={1,2,4,5,3,6,7},post={4,5,2,6,7,3,1};
	show(s.constructFromPrePost(pre,post));
	return 0;
}
