/*
Sort a linked list in O(n log n) time using constant space complexity.
*/

#include"148.SortList.h"

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
	Solution s;
	show(s.sortList(l));
	return 0;
}
