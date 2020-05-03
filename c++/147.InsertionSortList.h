/*
Sort a linked list using insertion sort.
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
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
 	ListNode *newhead=new ListNode(INT_MIN),*cur=head,*pre=newhead,*next=NULL;
	while(cur)
	{
		next=cur->next;
		while(pre->next&&pre->next->val<cur->val) pre=pre->next;
		cur->next=pre->next;
		pre->next=cur;
		pre=newhead;
		cur=next;
	}       
	return newhead->next;
    }
};
