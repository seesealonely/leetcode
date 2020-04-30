#include"19.h"
int main(void)
{
	Solution s;
	ListNode *head=buildList();
	show(head);
head=	s.removeNthFromEnd(head,1);
//	show(head);
	head=s.removeNthFromEnd(head,6);
	show(head);
//	s.removeNthFromEnd(head,2);
//show(head);
		return 0;
}
