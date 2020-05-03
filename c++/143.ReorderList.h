/*
 Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}. 
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
/*
class Solution {
public:
    void reorderList(ListNode* head) {
 	if(!head||!head->next||!head->next->next) return;
	stack<ListNode*> st;
	ListNode *slow=head,*fast=head;
	while(fast&&fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
	}       
	while(slow) { st.push(slow);slow=slow->next; }
	ListNode *prehalf=head,*next;
	for(ListNode *last;!st.empty();)
	{
		last=st.top();
		st.pop();
		if(last==prehalf) last->next=NULL;
		next=prehalf->next;
		prehalf->next=last;
		cout<<prehalf->val<<" "<<last->val<<endl;
		last->next=next;
		prehalf=next;	
	}
    }
};
*/
class Solution {
public:
    void reorderList(ListNode* head) {
 	if(!head||!head->next||!head->next->next) return;
	ListNode *slow=head,*fast=head;
	while(fast&&fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
	}       
	ListNode *head1=slow->next;
	slow->next=NULL;
	slow=fast=head1;
	head1=NULL;
	while(fast)
	{
		fast=fast->next;
		slow->next=head1;
		head1=slow;
		slow=fast;
	}
	show(head);
	show(head1);
	slow=fast=head;
	while(fast&&head1)
	{
		fast=fast->next;
		slow->next=head1;
		head1=head1->next;
		slow->next->next=fast?fast:head1;
		slow=fast;
	}
    }
};
