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

#include"653.TwoSumIV-InputisaBST.h"

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
	Solution s;
	cout<<s.findTarget1(buildTree(),3)<<endl;
	cout<<s.findTarget2(buildTree(),3)<<endl;
	return 0;
}
