/*
   Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

   Example 1:

Input: 
5
/ \
3   6
/ \   \
2   4   7

Target = 9

Output: True

Example 2:

Input: 
5
/ \
3   6
/ \   \
2   4   7

Target = 28

Output: False
*/
#define c11
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
		bool findTarget1(TreeNode* root, int k) {
			unordered_set<int> hash;
			return dfs(root,hash,k); 
		}
		bool findTarget2(TreeNode* root, int k) {
			vector<int> res;
			inorder(root,res);
			for(int begin=0,end=res.size()-1;begin<end;)
			{
				if(res[begin]+res[end]==k) return true;
				(res[begin]+res[end]<k)? begin++:end--;
			}
			return false;
		}
		bool dfs(TreeNode *root,unordered_set<int> &hash,int k)
		{
			if(!root) return false;
			if(hash.count(k-root->val)) return true;
			hash.insert(root->val);
			return dfs(root->left,hash,k)||dfs(root->right,hash,k);
		}
		void inorder(TreeNode *root,vector<int> &res)
		{
			if(!root) return ;
			inorder(root->left,res);
			res.push_back(root->val);
			inorder(root->right,res);
		}
};
