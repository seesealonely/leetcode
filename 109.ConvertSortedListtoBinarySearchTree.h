/*
   Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
   */

#include"head.h"

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
class Solution {
	public:
		TreeNode* sortedListToBST(ListNode* head) {
			return dfs(head,NULL);
		}
		TreeNode *dfs(ListNode *head,ListNode *end)
		{
			if(!head) return NULL;
			if(head==end) return NULL;// new TreeNode(head->val);
			ListNode *mid=head,*fast=head;
			while(fast!=end&&fast->next!=end)
			{
				mid=mid->next;
				fast=fast->next->next;
			}
			TreeNode *root=new TreeNode(mid->val);
			root->left=dfs(head,mid);
			root->right=dfs(mid->next,end);
			return root;
		}
};
