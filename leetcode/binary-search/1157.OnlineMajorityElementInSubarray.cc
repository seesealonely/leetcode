/*
   Design a data structure that efficiently finds the majority element of a given subarray.

   The majority element of a subarray is an element that occurs threshold times or more in the subarray.

   Implementing the MajorityChecker class:

   MajorityChecker(int[] arr) Initializes the instance of the class with the given array arr.
   int query(int left, int right, int threshold) returns the element in the subarray arr[left...right] that occurs at least threshold times, or -1 if no such element exists.



   Example 1:

   Input
   ["MajorityChecker", "query", "query", "query"]
   [[[1, 1, 2, 2, 1, 1]], [0, 5, 4], [0, 3, 3], [2, 3, 2]]
   Output
   [null, 1, -1, 2]

   Explanation
   MajorityChecker majorityChecker = new MajorityChecker([1, 1, 2, 2, 1, 1]);
   majorityChecker.query(0, 5, 4); // return 1
   majorityChecker.query(0, 3, 3); // return -1
   majorityChecker.query(2, 3, 2); // return 2



Constraints:

1 <= arr.length <= 2 * 104
1 <= arr[i] <= 2 * 104
0 <= left <= right < arr.length
threshold <= right - left + 1
2 * threshold > right - left + 1
At most 104 calls will be made to query.

*/
#define c11
#include"head.h"
class MajorityChecker {
	public:
		MajorityChecker(vector<int>& arr) {
			for(int i=0;i<arr.size();i++)
				index[arr[i]].push_back(i);
		}

		int query(int left, int right, int threshold) {
		for(unordered_map<int,vector<int>>::iterator it=index.begin();it!=index.end();it++)
		{
			vector<int>::iterator  l,r;
			l=lower_bound(it->second.begin(),it->second.end(),left);
			r=upper_bound(it->second.begin(),it->second.end(),right);
			if(r-l>=threshold)
				return it->first;
		}
		return -1;
		}
		unordered_map<int,vector<int> > index;
};
int main() 
{
	vector<int> v={1,1,2,2,1,1};
	MajorityChecker m(v);
	cout<<m.query(0,5,4)<<endl;
	cout<<m.query(0,3,3)<<endl;
	cout<<m.query(2,3,2)<<endl;
	return 0;
}
