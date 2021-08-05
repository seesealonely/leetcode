/*
   Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

   The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

   The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

   Return an array of the k parts.



   Example 1:

Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].

Example 2:

Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.



Constraints:

The number of nodes in the list is in the range [0, 1000].
0 <= Node.val <= 1000
1 <= k <= 50
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

*/
#include"head.h"
class Solution {
	public:
		vector<ListNode*> splitListToParts(ListNode* head, int k) {
			vector<ListNode *> res(k,NULL);
			int len=0,num=0,mod=0;
			ListNode *pre=NULL;
			for(ListNode *cur=head;cur;cur=cur->next)
				len++;
			num=len/k;mod=len%k;
			for(int i=0;i<k&&head;i++,mod--)
			{
				res[i]=head;
				for(int j=0;j<num+(mod>0?1:0);j++)
				{
					pre=head;
					head=head->next;
				}
				pre->next=NULL;
			}
			return res;
		}
		vector<ListNode *>dfs(vector<ListNode *> res,ListNode *head,int k,int num,int mod)
		{
			res.push_back(head);
			for(int i=1;i<k&&head;i++)
				head=head->next;
			if(mod>0&&head) head=head->next;
			dfs(res,head,--k,--num,--mod);
			return res;
		}
};
