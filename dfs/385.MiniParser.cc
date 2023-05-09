/*
   Given a string s represents the serialization of a nested list, implement a parser to deserialize it and return the deserialized NestedInteger.

   Each element is either an integer or a list whose elements may also be integers or other lists.



   Example 1:

Input: s = "324"
Output: 324
Explanation: You should return a NestedInteger object which contains a single integer 324.

Example 2:

Input: s = "[123,[456,[789]]]"
Output: [123,[456,[789]]]
Explanation: Return a NestedInteger object containing a nested list with 2 elements:
1. An integer containing value 123.
2. A nested list containing two elements:
i.  An integer containing value 456.
ii. A nested list with one element:
a. An integer containing value 789



Constraints:

1 <= s.length <= 5 * 104
s consists of digits, square brackets "[]", negative sign '-', and commas ','.
s is the serialization of valid NestedInteger.
All the values in the input are in the range [-106, 106].

*/

#include"head.h"
class NestedInteger {
    public:
      // Constructor initializes an empty nested list.
      NestedInteger();
 
      // Constructor initializes a single integer.
      NestedInteger(int value);
 
      // Return true if this NestedInteger holds a single integer, rather than a nested list.
      bool isInteger() const;
 
      // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
      int getInteger() const;
 
      // Set this NestedInteger to hold a single integer.
      void setInteger(int value);
 
      // Set this NestedInteger to hold a nested list and adds a nested integer to it.
      void add(const NestedInteger &ni);
 
      // Return the nested list that this NestedInteger holds, if it holds a nested list
      // The result is undefined if this NestedInteger holds a single integer
      const vector<NestedInteger> &getList() const;
};
class Solution {
	public:
		int getNum(int &i,const string&s)
		{
			int val=0;
			bool negative=false;
			if(s[i]=='-')
			{
				negative=true;
				i++;
			}
			while(i<s.size()&&isdigit(s[i]))
				val=val*10+s[i++]-'0';

			if(negative) val=-val;
			return val;
		}
		NestedInteger dfs(int &i,const string &s)
		{
			NestedInteger res;
			if(s[i]=='-'||isdigit(s[i]))
				res.setInteger(getNum(i,s));
			else
			{
				i++;
				if(s[i]==']')
				{
					i++;
					return res;
				}
				while(true)
				{
					res.add(dfs(i,s));
					if(s[i++]==']')break;
				}
			}
			return res;
		}
		NestedInteger deserialize(string s) {
		int i=0;

		return dfs(i,s);

		}
};


int main() 
{
	return 0;
}
