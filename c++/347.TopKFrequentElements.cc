/*
 Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:

    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

*/
#include"347.TopKFrequentElements.h"

int main()
{
	int vv[]={1,1,1,2,2,5};
	vector<int> v(vv,vv+6);
	Solution s;	
	show(s.topKFrequent(v,2));
	int vv1[]={-1,-1};
	vector<int> v1(vv1,vv1+2);
	show(s.topKFrequent(v1,1));
	return 0;
}
