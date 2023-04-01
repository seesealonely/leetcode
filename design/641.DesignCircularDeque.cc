/*
   Design your implementation of the circular double-ended queue (deque).

   Implement the MyCircularDeque class:

   MyCircularDeque(int k) Initializes the deque with a maximum size of k.
   boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
   boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
   boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
   boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
   int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
   int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
   boolean isEmpty() Returns true if the deque is empty, or false otherwise.
   boolean isFull() Returns true if the deque is full, or false otherwise.



   Example 1:

   Input
   ["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
   [[3], [1], [2], [3], [4], [], [], [], [4], []]
   Output
   [null, true, true, true, false, 2, true, true, true, 4]

   Explanation
   MyCircularDeque myCircularDeque = new MyCircularDeque(3);
   myCircularDeque.insertLast(1); // return True
   myCircularDeque.insertLast(2); // return True
   myCircularDeque.insertFront(3); // return True
   myCircularDeque.insertFront(4); // return False, the queue is full.
   myCircularDeque.getRear(); // return 2
   myCircularDeque.isFull(); // return True
   myCircularDeque.deleteLast(); // return True
   myCircularDeque.insertFront(4); // return True
   myCircularDeque.getFront(); // return 4



Constraints:

1 <= k <= 1000
0 <= value <= 1000
At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.

*/


#include"head.h"
class MyCircularDeque {
	public:
		int size,head,tail,n;
		vector<int> d;
		MyCircularDeque(int k) {
			d.resize(k);
			n=k;
			size=0;
			head=tail=0;
		}

		bool insertFront(int value) {
			if(isFull())
				return false;
			head=(head+n-1)%n;
			d[head]=value;
			size++;
			return true;
		}

		bool insertLast(int value) {
			if(isFull())
				return false;

			d[tail++]=value;
			tail%=n;
			size++;
			return true;
		}

		bool deleteFront() {
			if(isEmpty())
				return false;

			head=(head+1)%n;
			size--;
			return true;
		}

		bool deleteLast() {
			if(isEmpty())
				return  false;

			tail=(tail-1+n)%n;
			size--;
			return true;
		}

		int getFront() {
			if(isEmpty())
				return -1;

			return d[head];
		}

		int getRear() {
			if(isEmpty())
				return -1;

			return d[(tail+n-1)%n];
		}

		bool isEmpty() {
			return size==0;
		}

		bool isFull() {
			return size==n;
		}
};


int main() 
{
	MyCircularDeque  q(3);
	cout<<q.insertLast(1)<<endl;
	cout<<q.insertLast(2)<<endl;
	cout<<q.insertFront(3)<<endl;
	cout<<q.insertFront(4)<<endl;
	cout<<q.getRear()<<endl;
	cout<<q.isFull()<<endl;
	cout<<q.deleteLast()<<endl;
	cout<<q.insertFront(4)<<endl;
	cout<<q.getFront()<<endl;
	return 0;
}
