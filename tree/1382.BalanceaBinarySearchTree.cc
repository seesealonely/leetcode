/*
   Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

   A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.



   Example 1:

Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

Example 2:

Input: root = [2,1,3]
Output: [2,1,3]



Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 105

*/


#include"head.h"
class Solution {
	public:
		TreeNode* balanceBST(TreeNode* root) {
		vector<int> num;
		inorder(root,num);

		return getRoot(0,num.size()-1,num);
		}
		void inorder(TreeNode* r,vector<int> &num)
		{
			if(!r)
				return ;
			inorder(r->left,num);
			num.push_back(r->val);
			inorder(r->right,num);
		}

		TreeNode* getRoot(int l,int r,const vector<int> &num)
		{
			if(l>r)return NULL;

			int m=(l+r)>>1;
			TreeNode* root=new TreeNode(num[m]);
			root->left=getRoot(l,m-1,num);
			root->right=getRoot(m+1,r,num);
			return root;
		}

};


int main() 
{
	Solution s;
	show(s.balanceBST(buildTree()));
	return 0;
}
