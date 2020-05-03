/*
   Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 
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
		ListNode* mergeKLists(vector<ListNode*>& lists) {
		if(lists.empty()) return NULL;
		ListNode *res=NULL;
		for(int i=0;i<lists.size();++i)
		res=mergeTwoList(res,lists[i]);	
		return res;
		}
		ListNode *mergeTwoList(ListNode *one,ListNode *two)
		{
			if(!one&&!two) return NULL;
			if(!one) return two;
			if(!two) return one;
			if(one->val<=two->val)
			{
			one->next=mergeTwoList(one->next,two);
			return one;
			}
			else
			{
			two->next=mergeTwoList(one,two->next);
			return two;
			}
		}
};
