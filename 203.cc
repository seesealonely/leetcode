#include"203.h"
int main()
{
	ListNode *head=buildList();
	show(head);
	Solution s;
	show(s.removeElements(head,6));
	return 0;
}
