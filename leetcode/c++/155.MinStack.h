/*
   Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

   push(x) -- Push element x onto stack.
   pop() -- Removes the element on top of the stack.
   top() -- Get the top element.
   getMin() -- Retrieve the minimum element in the stack.

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

*/

#include"head.h"

class MinStack {
	public:
		/** initialize your data structure here. */
		MinStack() {
		}

		void push(int x) {
		if(st.empty())
			st.push(node(x,x));
		else
			st.push(node(x,min(st.top().minval,x)));
		}

		void pop() {
		st.pop();	
		}

		int top() {
		return st.top().val;
		}

		int getMin() {
		return st.top().minval;
		}
		class node
		{
			public:
			node(int x,int mx)
			{
				val=x;
				minval=mx;
			}
//			private:
			int val;
			int minval;
		};
	private:
		stack<node> st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
