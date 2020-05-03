/*
   Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
   */

#include"109.ConvertSortedListtoBinarySearchTree.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
	ListNode *l=buildList();
	Solution s;
	show(s.sortedListToBST(l));
	return 0;	
}
