/*
   Given the root of a binary tree, construct a 0-indexed m x n string matrix res that represents a formatted layout of the tree. The formatted layout matrix should be constructed using the following rules:

   The height of the tree is height and the number of rows m should be equal to height + 1.
   The number of columns n should be equal to 2height+1 - 1.
   Place the root node in the middle of the top row (more formally, at location res[0][(n-1)/2]).
   For each node that has been placed in the matrix at position res[r][c], place its left child at res[r+1][c-2height-r-1] and its right child at res[r+1][c+2height-r-1].
   Continue this process until all the nodes in the tree have been placed.
   Any empty cells should contain the empty string "".

   Return the constructed matrix res.



   Example 1:

Input: root = [1,2]
Output:
[["","1",""],
["2","",""]]

Example 2:

Input: root = [1,2,3,null,4]
Output:
[["","","","1","","",""],
["","2","","","","3",""],
["","","4","","","",""]]



Constraints:

The number of nodes in the tree is in the range [1, 210].
-99 <= Node.val <= 99
The depth of the tree will be in the range [1, 10].

*/


#include"head.h"
class Solution {
	public:
		vector<vector<string>> printTree(TreeNode* root) {
			int row=depth(root)+1,col=pow(2,row)-1;
			vector<vector<string>> res(row,vector<string>(col,""));
			dfs(root,res,0,0,col);
			return res;
		}
		int depth(TreeNode *root)
		{
			if(!root) return 0;
			return max(depth(root->left),depth(root->right))+1;
		}
		void dfs(TreeNode *root,vector<vector<string>> &res,int dep,int l,int r)
		{
			if(!root)
				return;
			int pos=(l+r)>>1;
			res[dep][pos]=to_string(root->val);
			dfs(root->left,res,dep+1,l,pos);
			dfs(root->right,res,dep+1,pos,r);
		}
};


int main() 
{
	Solution s;
	show(s.printTree(buildTree()));
	return 0;
}
