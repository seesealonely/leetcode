/*
   Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

   Implement the AllOne class:

   AllOne() Initializes the object of the data structure.
   inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
   dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
   getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
   getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".

   Note that each function must run in O(1) average time complexity.



   Example 1:

   Input
   ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
   [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
   Output
   [null, null, null, "hello", "hello", null, "hello", "leet"]

   Explanation
   AllOne allOne = new AllOne();
   allOne.inc("hello");
   allOne.inc("hello");
   allOne.getMaxKey(); // return "hello"
   allOne.getMinKey(); // return "hello"
   allOne.inc("leet");
   allOne.getMaxKey(); // return "hello"
   allOne.getMinKey(); // return "leet"



Constraints:

1 <= key.length <= 10
key consists of lowercase English letters.
It is guaranteed that for each call to dec, key is existing in the data structure.
At most 5 * 104 calls will be made to inc, dec, getMaxKey, and getMinKey.

*/

#define c11
#include"head.h"
class AllOne {
	public:
		struct Node
		{
			Node *pre,*next;
			int val;
			unordered_set<string> keys;
			Node(int v)
			{
				pre=next=NULL;
				val=v;
			}
		};
		unordered_map<string,Node*> h;
		Node *s,*e;
		AllOne() {
			s=new  Node(0);
			e=new Node(INT_MAX);
			s->next=e;
			e->pre=s;
		}

		void insert(Node *cur,int v)
		{
			Node *next=new Node(v);
			next->next=cur->next;
			next->pre=cur;
			next->next->pre=next;
			cur->next=next;
		}

		void remove(Node* cur)
		{
			cur->pre->next=cur->next;
			cur->next->pre=cur->pre;
			delete cur;
		}
		void inc(string key) {
			if(h.find(key)==h.end())
				h[key]=s;
			Node *cur=h[key];
			if(cur->next->val>cur->val+1)
				insert(cur,cur->val+1);

			h[key]=cur->next;
			cur->next->keys.insert(key);

			if(cur->val>0)
			{
				cur->keys.erase(key);
				if(cur->keys.empty())
					remove(cur);
			}
		}

		void dec(string key) {
		if(h.find(key)==h.end())
			return;

		Node *cur=h[key];
		if(cur->pre->val<cur->val-1)
			insert(cur->pre,cur->val-1);
		
		if(cur->val>1)
		{
			h[key]=cur->pre;
			cur->pre->keys.insert(key);
		}
		else
			h.erase(key);

		cur->keys.erase(key);
		if(cur->keys.empty())
			remove(cur);
		}

		string getMaxKey() {
		if(e->pre==s)
			return "";
		return *(e->pre->keys.begin());
		}

		string getMinKey() {
		if(s->next==e)
			return "";
		return *(s->next->keys.begin());
		}
};


int main() 
{
   AllOne allOne = AllOne();
   allOne.inc("hello");
   allOne.inc("hello");
   allOne.getMaxKey(); // return "hello"
   allOne.getMinKey(); // return "hello"
   allOne.inc("leet");
   allOne.getMaxKey(); // return "hello"
   allOne.getMinKey(); // return "leet"
	return 0;
}
