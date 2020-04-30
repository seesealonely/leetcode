/*
In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.

Return the element repeated N times.

 

Example 1:

Input: [1,2,3,3]
Output: 3

Example 2:

Input: [2,1,2,5,3,2]
Output: 2

Example 3:

Input: [5,1,5,2,5,3,5,4]
Output: 5

 

Note:

    4 <= A.length <= 10000
    0 <= A[i] < 10000
    A.length is even


*/

#include"961.N-RepeatedElementinSize2NArray.h"

int main()
{
	vector<int> v;
	Solution s;
	v.push_back(1);v.push_back(2);v.push_back(3);v.push_back(3);
	cout<<s.repeatedNTimes(v)<<endl;
	v.clear();v.push_back(2);v.push_back(1);v.push_back(2);v.push_back(5);v.push_back(3);v.push_back(2);
	cout<<s.repeatedNTimes(v)<<endl;
	v.clear();v.push_back(5);v.push_back(1);v.push_back(5);v.push_back(2);v.push_back(5);v.push_back(3);v.push_back(5);v.push_back(4);
	cout<<s.repeatedNTimes(v)<<endl;
	return 0;
}
