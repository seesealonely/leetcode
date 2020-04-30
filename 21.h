#include<iostream>
#include<set>
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
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
		{
			multiset<int> s;
			while(l1||l2)
			{
			if(l1){	s.insert(l1->val);l1=l1->next;}
			if(l2)	{s.insert(l2->val);l2=l2->next;}
			}
			if(s.empty())
				return NULL;
			ListNode *tmp=NULL,*head=NULL;
			for(set<int>::const_iterator it=s.begin();it!=s.end();++it)
			{
				if(!head)
					tmp=head=new ListNode(*it);
				else
				{
					tmp->next=new ListNode(*it);
					tmp=tmp->next;
				}
			}
			return head;
		}
};
