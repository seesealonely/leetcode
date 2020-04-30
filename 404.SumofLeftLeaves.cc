/*
   Find the sum of all left leaves in a given binary tree.

Example:

3
/ \
9  20
/  \
15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

*/

#include"404.SumofLeftLeaves.h"

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
	TreeNode *r=buildTree();
	Solution s;
	cout<<s.sumOfLeftLeaves(r)<<endl;
	return 0;
}
