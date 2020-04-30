/*
   Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 
   */

#include"23.MergekSortedLists.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int main()
{
	vector<ListNode *> lp;
//	ListNode *lp=new ListNode *[3];
	for(int i=0;i<3;++i)
	lp.push_back(buildList());
	Solution s;
	show(s.mergeKLists(lp));
	return 0;
}
