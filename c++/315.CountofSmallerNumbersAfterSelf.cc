/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Input: [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
*/
#include"315.CountofSmallerNumbersAfterSelf.h"
int main() 
 {
 	 Solution s;
	vector<int> v;
	v.push_back(5);v.push_back(2);v.push_back(6);v.push_back(1);
 	 show(s.countSmaller(v));
 	 return 0;
 }
