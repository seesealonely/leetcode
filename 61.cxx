#include"61.h"
int main()
{

struct ListNode *head=buildList(9);
show(head);
Solution s;
struct ListNode *res=s.rotateRight(head,5);
show(res);
show(head);
return 0;
}
