#include<iostream>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct ListNode *buildList(void)
{
	struct ListNode *head=NULL,*next=NULL;
	bool nohead=true;
	int inputnumber=0;
	cout<<"exit build buildList after input number more than 9"<<endl;
	do{
	cin>>inputnumber;
		if(inputnumber>9)
			break;
		if(nohead)
		{
		head=next=new struct ListNode(inputnumber);
			nohead=false;
		}
		else
		{
		next->next=new struct ListNode(inputnumber);
			next=next->next;	
			next->val=inputnumber;
		}
	}while(nohead||inputnumber<=9);
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
class Solution
{
	public:
		ListNode* removeNthFromEnd(ListNode* head, int n)
	       	{
			ListNode *newhead=new ListNode(0);
			newhead->next=head;
			ListNode *find=newhead,*move=newhead,*del=NULL;
			for(int i=0;i<n;++i)
				if(move)
					move=move->next;
				else return NULL;
			while(move->next)
			{
				find=find->next;
				move=move->next;
			}
			del=find->next;
			find->next=find->next->next;
			delete del;
			return newhead->next;
		}
};
