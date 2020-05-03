/*
Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Example 1:

Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.

Example 2:

Input: arr = [1,0,2,3,4]
Output: 4
Explanation:
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.

Note:

    arr will have length in range [1, 10].
    arr[i] will be a permutation of [0, 1, ..., arr.length - 1].

*/

#include"769.MaxChunksToMakeSorted.h"

int main()
{
	vector<int> v;
	for(int i=4;i>=0;i--)
	v.push_back(i);
	Solution s;
	cout<<s.maxChunksToSorted(v)<<endl;
	v.clear();
	v.push_back(1);v.push_back(0);v.push_back(2);v.push_back(3);v.push_back(4);
	cout<<s.maxChunksToSorted(v)<<endl;
	return 0;
}
