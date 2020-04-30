/*
Print a binary tree in an m*n 2D string array following these rules:

    The row number m should be equal to the height of the given binary tree.
    The column number n should always be an odd number.
    The root node's value (in string format) should be put in the exactly middle of the first row it can be put. The column and the row where the root node belongs will separate the rest space into two parts (left-bottom part and right-bottom part). You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space for both of them.
    Each unused space should contain an empty string "".
    Print the subtrees following the same rules.

Example 1:

Input:
     1
    /
   2
Output:
[["", "1", ""],
 ["2", "", ""]]

Example 2:

Input:
     1
    / \
   2   3
    \
     4
Output:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]

Example 3:

Input:
      1
     / \
    2   5
   / 
  3 
 / 
4 
Output:

[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]

Note: The height of binary tree is in the range of [1, 10]. 
*/
#define C11
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
    vector<vector<string> > printTree(TreeNode* root) {
 	int h=getHeight(root),w=getWidth(root);       
	vector<vector<string> > res(h,vector<string>(w,""));
	dfs(res,root,0,0,w-1);
	return res;
    }
	int getHeight(TreeNode *root)
	{
		if(!root) return 0;
		int left=getHeight(root->left),right=getHeight(root->right);
		return max(left,right)+1;
	}
	int getWidth(TreeNode *root)
	{
		if(!root) return 0;
		int left=getWidth(root->left),right=getWidth(root->right);
		return max(left,right)*2+1;
	}
	void dfs(vector<vector<string> > &res,TreeNode *root,int level,int l,int r)
	{
		if(!root) return;
		int mid=l+(r-1)/2;
		res[level][mid]=to_string(root->val);
		dfs(res,root->left,level+1,1,mid-1);
		dfs(res,root->right,level+1,mid+1,r);
	}
};
