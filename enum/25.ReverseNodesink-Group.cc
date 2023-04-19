/*
   Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

   k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

   You may not alter the values in the list's nodes, only nodes themselves may be changed.



   Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]



Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000



Follow-up: Can you solve the problem in O(1) extra memory space?
*/


#include"head.h"
class Solution {
	public:
		ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *dummy=new ListNode(0);
		dummy->next=head;
		ListNode *cur=dummy;

		while(cur)
		{
			ListNode *first=cur->next;
			ListNode *end=cur;

			for(int i=0;i<k&&end;i++)
				end=end->next;

			if(end==NULL)
				break;

			ListNode *p1=first;
			ListNode *p2=first->next;
			while(p1!=end)
			{
				ListNode *new_p2=p2->next;
				p2->next=p1;
				p1=p2;
				p2=new_p2;
			}
			first->next=p2;
			cur->next=end;
			cur=first;
		}

		return dummy->next;
		}
};


int main() 
{
	Solution s;
	show(s.reverseKGroup(buildList(),3));
	return 0;
}
