/*
   You are given the head of a linked list, and an integer k.

   Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).



   Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]

Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: 9

Example 3:

Input: head = [1], k = 1
Output: [1]

Example 4:

Input: head = [1,2], k = 1
Output: [2,1]

Example 5:

Input: head = [1,2,3], k = 2
Output: [1,2,3]



Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100

*/
#include"head.h"
class Solution {
	public:
		ListNode* swapNodes(ListNode* head, int k) {
			int len=0,i=0,j=0,tmp=0;
			ListNode *h=head,*pre=h,*post=h,*newh=h;
			while(h)
			{
				h=h->next;
				len++;
			}
			i=k-1,j=len-k;
			while(i--)
				pre=pre->next;
			while(j--)
				post=post->next;
			tmp=pre->val;
			pre->val=post->val;
			post->val=tmp;
			return newh;
		}
};
