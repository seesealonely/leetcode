/*
   Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

   Implement the LRUCache class:

   LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
   int get(int key) Return the value of the key if the key exists, otherwise return -1.
   void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

   The functions get and put must each run in O(1) average time complexity.



   Example 1:

   Input
   ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
   [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
   Output
   [null, null, null, 1, null, -1, null, -1, 3, 4]

   Explanation
   LRUCache lRUCache = new LRUCache(2);
   lRUCache.put(1, 1); // cache is {1=1}
   lRUCache.put(2, 2); // cache is {1=1, 2=2}
   lRUCache.get(1);    // return 1
   lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
   lRUCache.get(2);    // returns -1 (not found)
   lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
   lRUCache.get(1);    // return -1 (not found)
   lRUCache.get(3);    // return 3
   lRUCache.get(4);    // return 4



Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.

*/

#define c11
#include"head.h"
class Node 
{
	public:
		int key,val;
		Node *prev,*next;
		Node(int key,int val)
		{
			this->key=key,this->val=val;
			prev=next=NULL;
		}
};
class LRUCache {
	public:
		int capacity,tot;
		Node *head,*tail;
		unordered_map<int,Node *> dic;
		LRUCache(int capacity) {
			tot=0;
			this->capacity=capacity;

			head=new Node(-1,-1);
			tail=new Node(-1,-1);
			head->next=tail;
			tail->prev=head;

		}

		void remove(Node* node)
		{
			node->prev->next=node->next;
			node->next->prev=node->prev;
		}

		void insertToTail(Node* node)
		{
			node->next=tail;
			node->prev=tail->prev;

			tail->prev->next=node;
			tail->prev=node;
		}
		int get(int key) {
		if(dic.find(key)==dic.end())
			return -1;

		Node *node=dic[key];
		remove(node);
		insertToTail(node);
		return node->val;
		}

		void put(int key, int value) {
		if(dic.find(key)!=dic.end())
		{
			Node *node=dic[key];
			node->val=value;
			remove(node);
			insertToTail(node);
		}
		else
		{
			if(tot==capacity)
			{
				Node *node=head->next;
				dic.erase(node->key);

				remove(node);
				delete node;
				tot--;
			}
			Node *node=new Node(key,value);
			dic[key]=node;
			insertToTail(node);
			tot++;
		}

		}
};


int main() 
{
	LRUCache L(2);
	L.put(1,1);
	L.put(2,2);
	cout<<L.get(1)<<endl;
	L.put(3,3);
	cout<<L.get(2)<<endl;
	L.put(4,4);
	cout<<L.get(1)<<endl;
	cout<<L.get(3)<<endl;
	cout<<L.get(4)<<endl;
	return 0;
}
