#include"206.h"
int main()
{
	Solution s;
	ListNode *head=	buildList();
	show(head);
	show(s.reverseList(head));
	return 0;
}
