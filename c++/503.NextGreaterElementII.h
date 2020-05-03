/*
 Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:

Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.

Note: The length of given array won't exceed 10000. 
*/

#include"head.h"

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
	int len=nums.size();
	vector<int> res(len,-1);
	stack<int> st;
	for(int i=0;i<len*2;++i)
	{
		while(st.size()&&nums[st.top()]<nums[i%len])
		{
			res[st.top()]=nums[i%len];
			st.pop();
		}	
		if(i<len) st.push(i);
	}        
	return res;
    }
};
