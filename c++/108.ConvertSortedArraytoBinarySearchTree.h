/*
   Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
		TreeNode* sortedArrayToBST(vector<int>& nums) {
		return dfs(nums,0,nums.size()-1);
		}
	private:
		TreeNode *dfs(vector<int> nums,int begin,int end)
		{
			if((end-begin)<0) return NULL;
			if((end-begin)==0) return new TreeNode(nums[begin]);
			int mid=(begin+end)>>1;
			TreeNode *root=new TreeNode(nums[mid]);
			root->left=dfs(nums,begin,mid-1);
			root->right=dfs(nums,mid+1,end);
			return root;
		}
};
