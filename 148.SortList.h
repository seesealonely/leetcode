/*
   Sort a linked list in O(n log n) time using constant space complexity.
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
		ListNode* sortList(ListNode* head) {
			if(!head||!head->next) return head;
			ListNode *slow=head,*fast=head,*pre=NULL; 
			while(fast&&fast->next)
			{
				pre=slow;
				slow=slow->next;
				fast=fast->next->next;
			}
		if(pre)	pre->next=NULL;
			ListNode *one,*two;
			if(head!=slow)
			{
			one=sortList(head);	
			two=sortList(slow);	
			}
			return 	merge(one,two);
		}
		ListNode *merge(ListNode *pre,ListNode * next)
		{
			ListNode *h=new ListNode(0),*p=h;
			while(pre&&next)
			{
				if(pre->val<next->val)
				{
					p->next=pre;
					pre=pre->next;
				}
				else
				{
					p->next=next;
					next=next->next;
				}
				p=p->next;
			}
			if(pre) p->next=pre;
			else p->next=next; 
			return h->next;
		}
};
