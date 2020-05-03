/*
   Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

   For example,
   Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
   \       /     /      / \      \
   3     2     1      1   3      2
   /     /       \                 \
   2     1         2                 3

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
		vector<TreeNode*> generateTrees(int n) {
			return dfs(1,n);
		}
		vector<TreeNode *> dfs(int beg,int end)
		{
			vector<TreeNode *> res;
			if(beg>end) {res.push_back(NULL);return res;}

			for(int i=beg;i<end+1;++i)
			{
				vector<TreeNode *> left=dfs(beg,i-1);
				vector<TreeNode *> right=dfs(i+1,end);
				for(vector<TreeNode *>::iterator l=left.begin();l!=left.end();++l)
				{
					for(vector<TreeNode *>::iterator r=right.begin();r!=right.end();++r)
					{
						TreeNode *root=new TreeNode (i);
						root->left=*l;
						root->right=*r;
						res.push_back(root);
					}
				}
			}	
			return res;
		}
};
/*
   for(int j=0;j<left.size();++j)
   for(int k=0;k<right.size();++k)
   {
   TreeNode *root=new TreeNode (i);
   root->left=left[j];
   root->right=right[k];
   res.push_back(root);
   }
   */
