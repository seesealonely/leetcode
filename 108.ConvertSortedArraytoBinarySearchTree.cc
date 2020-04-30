/*
   Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
   */

#include"108.ConvertSortedArraytoBinarySearchTree.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int main()
{
	int vv[]={1,2,3,4,5,6,7,8};
	vector<int> v(vv,vv+8);
	Solution s;
	show(s.sortedArrayToBST(v));
	return 0;
}
