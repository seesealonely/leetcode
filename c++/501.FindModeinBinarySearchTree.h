/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than or equal to the node's key.
    The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
    Both the left and right subtrees must also be binary search trees.

For example:
Given BST [1,null,2,2],

   1
    \
     2
    /
   2

return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count). 
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
    vector<int> findMode(TreeNode* root) {
	pre=LONG_MIN;
	count=1;maxcount=0;
	inorder(root,res);
	return res;
    }
	void inorder(TreeNode* root,vector<int> &res)
	{
		if(!root) return;
		inorder(root->left,res);
		if(pre!=LONG_MIN)
		{
			if(pre==root->val)
				count++;
			else
				count=1;
		}
		if(count>maxcount)
		{
			maxcount=count;
			res.clear();
			res.push_back(root->val);
		}
		else if(count==maxcount)
			res.push_back(root->val);
		pre=root->val;
		inorder(root->right,res);
	}
private:	
	vector<int> res;        
	long pre;
	int count;
	int maxcount;
};
