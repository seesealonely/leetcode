#include"234.h"
int main()
{
	Solution s;
	ListNode *head=buildList();
	show(head);
	s.isPalindrome(head);
	return 0;
}
