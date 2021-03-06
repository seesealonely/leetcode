/*
Given an array of integers arr.

We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]

Note that ^ denotes the bitwise-xor operation.

Return the number of triplets (i, j and k) Where a == b.



Example 1:

Input: arr = [2,3,1,6,7]
Output: 4
Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)

Example 2:

Input: arr = [1,1,1,1,1]
Output: 10

Example 3:

Input: arr = [2,3]
Output: 0

Example 4:

Input: arr = 9
Output: 3

Example 5:

Input: arr = 9
Output: 8



Constraints:

1 <= arr.length <= 300
1 <= arr[i] <= 10^8
*/
#include"head.h"
class Solution {
public:
int countTriplets(vector<int>& arr) {
	vector<int> pre(arr.size()+1,0);
	int res=0;
	for(int i=0;i<arr.size();i++)
	pre[i+1]=arr[i]^pre[i];
	for(int i=0;i<pre.size();i++)
		for(int j=i+1;j<pre.size();j++)
		if(pre[i]==pre[j])
			res+=j-i-1;
	return res;
}
};
