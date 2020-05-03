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
void free(struct ListNode *head)
{
	struct ListNode *tmp=NULL;
	int i=0;
	for(struct ListNode *next=head;next;)
	{
		cout<<"Th"<<i<<" "<<next->val<<endl;
		tmp=next;
		next=next->next;
		i++;
		delete tmp;
	}
}
void show(struct ListNode *head)
{
	int i=0;
	cout<<"################"<<endl;
	for(struct ListNode *next=head;next;)
	{
		cout<<"Th"<<i<<" "<<next->val<<endl;
		next=next->next;
		i++;
	}
	cout<<"################"<<endl<<endl;;
}
class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
		{
			struct ListNode *head=NULL,*next=NULL,*l1next=l1,*l2next=l2;
			int addnumber=0;
			bool  nohead=true;
			while(l1next||l2next||addnumber)
			{
				if(l1next)	addnumber+=l1next->val;
				if(l2next)	addnumber+=l2next->val;
				if(nohead)
				{

					head=next=new struct ListNode((addnumber)%10);
					nohead=false;
				}
				else
				{
					next->next=new struct ListNode((addnumber)%10);
					next=next->next;	
				}
					if(addnumber>9)
					addnumber=1;
					else
					addnumber=0;
				if(l1next)	l1next=l1next->next;
				if(l2next)	l2next=l2next->next;

			}
			return head;
		}
		};
