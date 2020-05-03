#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct ListNode *buildList(int num)
{
	struct ListNode *head=NULL,*next=NULL;
	bool nohead=true;
	int inputnumber=0;
	cout<<"exit build buildList after input number more than 9"<<endl;
	do{
		//		cin>>inputnumber;
		if(inputnumber>9)
			break;
		if(nohead)
		{
			head=next=new struct ListNode(inputnumber);
			next->val=inputnumber++;
			nohead=false;
		}
		else
		{
			next->next=new struct ListNode(inputnumber);
			next=next->next;	
			next->val=inputnumber++;
		}
	}while(nohead||inputnumber<=num);
	return head;
}
void show(struct ListNode *head)
{
	int i=0;

	if(head)
	{
		cout<<"################"<<endl;
		for(struct ListNode *next=head;next;)
		{
			cout<<"Th"<<i<<" "<<next->val<<endl;
			next=next->next;
			i++;
		}
		cout<<"################"<<endl<<endl;;
	}
	//	else exit(0);
}
class Solution {
	public:
		ListNode* rotateRight(ListNode* head, int k) {
			if(!head||!k) return head;
			int len=1;
			ListNode *tail=head;
			while(tail->next) 
			{
				tail=tail->next;
				++len;
			}
			tail->next=head;
			if(k%=len)
			for(int i=0;i<len-k;i++)
				tail=tail->next;
			ListNode *h=tail->next;
			tail->next=NULL;
				return h;	
		}

};
