#include"21.h"
int main()
{
	ListNode *head1=buildList();
	ListNode *head2=buildList();
	show(head1);
	show(head2);
//	ListNode *head1=NULL,*head2=NULL;
	Solution s;
	show(s.mergeTwoLists(head1,head2));
	return 0;
}
