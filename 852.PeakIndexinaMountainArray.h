/*
Let's call an array A a mountain if the following properties hold:

    A.length >= 3
    There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]

Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

Example 1:

Input: [0,1,0]
Output: 1

Example 2:

Input: [0,2,1,0]
Output: 1

Note:

    3 <= A.length <= 10000
    0 <= A[i] <= 10^6
    A is a mountain, as defined above.


*/

#include"head.h"

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
	return binarySearch(A);
	return lineScan(A);	        
    }
	int lineScan(vector<int> &A)
	{
		int i=0;
		while(A[i]<A[i+1]) i++;
		return i;
	}
	int binarySearch(vector<int> &A)
	{
		int begin=0,end=A.size()-1,mid=0;
		while(begin<end)
		{
			mid=begin+(end-begin)/2;
			if(A[mid]<A[mid+1])
				begin=mid+1;
			else
				end=mid;
		}
		return begin;
	}
};
