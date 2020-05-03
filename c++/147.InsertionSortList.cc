/*
Sort a linked list using insertion sort.
*/

#include"147.InsertionSortList.h"

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
	ListNode *l=buildList();
	show(l);
	Solution s;
	s.insertionSortList(l);
	show(l);
}
