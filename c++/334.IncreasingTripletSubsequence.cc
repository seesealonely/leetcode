/*
 Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

    Return true if there exists i, j, k
    such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false. 

Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false. 
*/

#include"334.IncreasingTripletSubsequence.h"

int main()
{
	int vv[]={1, 2, 3, 4, 5};
	vector<int> v(vv,vv+5);
	int vv1[]={2,4,-2,-3};	
	vector<int> v1(vv1,vv1+4);
	Solution s;
	cout<<s.increasingTriplet(v)<<endl;
	cout<<s.increasingTriplet(v1)<<endl;
	return 0;
}
