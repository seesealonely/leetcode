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

#include"155.MinStack.h"

int main()
{
	MinStack s;
	s.push(-2);
	s.push(0);
	s.push(-3);
	cout<<s.getMin()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	cout<<s.getMin()<<endl;
	return 0;
}
