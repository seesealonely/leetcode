/*
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.

 

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]

 

Constraints:

    arr1.length, arr2.length <= 1000
    0 <= arr1[i], arr2[i] <= 1000
    Each arr2[i] is distinct.
    Each arr2[i] is in arr1.

*/

#define c11
#include"head.h"

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
	unordered_map<int,int> hash;
	vector<int> res,tmp;
	for(int i=0;i<arr1.size();i++)
		hash[arr1[i]]++;
	for(int i=0;i<arr2.size();i++)
		while(hash[arr2[i]]-->0) res.push_back(arr2[i]);
	for(int i=0;i<arr1.size();i++)
		if(hash[arr1[i]]>0) tmp.push_back(arr1[i]);
	sort(tmp.begin(),tmp.end());
	for(int i=0;i<tmp.size();i++)
		res.push_back(tmp[i]);
	return res;
    }
};
