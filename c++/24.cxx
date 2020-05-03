#include"24.h"
int main()
{
ListNode *head=buildList();
Solution s;
head=s.swapPairs(head);
show(head);

return 0;

}
