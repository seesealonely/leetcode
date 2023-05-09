/*
   Given an array arr that represents a permutation of numbers from 1 to n.

   You have a binary string of size n that initially has all its bits set to zero. At each step i (assuming both the binary string and arr are 1-indexed) from 1 to n, the bit at position arr[i] is set to 1.

   You are also given an integer m. Find the latest step at which there exists a group of ones of length m. A group of ones is a contiguous substring of 1's such that it cannot be extended in either direction.

   Return the latest step at which there exists a group of ones of length exactly m. If no such group exists, return -1.



   Example 1:

Input: arr = [3,5,1,2,4], m = 1
Output: 4
Explanation:
Step 1: "00100", groups: ["1"]
Step 2: "00101", groups: ["1", "1"]
Step 3: "10101", groups: ["1", "1", "1"]
Step 4: "11101", groups: ["111", "1"]
Step 5: "11111", groups: ["11111"]
The latest step at which there exists a group of size 1 is step 4.

Example 2:

Input: arr = [3,1,5,4,2], m = 2
Output: -1
Explanation:
Step 1: "00100", groups: ["1"]
Step 2: "10100", groups: ["1", "1"]
Step 3: "10101", groups: ["1", "1", "1"]
Step 4: "10111", groups: ["1", "111"]
Step 5: "11111", groups: ["11111"]
No group of size 2 exists during any step.



Constraints:

n == arr.length
1 <= m <= n <= 105
1 <= arr[i] <= n
All integers in arr are distinct.

*/

#define c11
#include"head.h"
class Solution {
	private:
		static const int N=1e5+2;
		int pa[N],size[N];
		int find(int x)
		{
			return pa[x]==x?pa[x]:find(pa[x]);
		}
	public:
		int findLatestStep(vector<int>& arr, int m) {
		const int n=arr.size();
		unordered_map<int,int> cnt;

		cnt[0]=n+1;
		for(int i=1;i<=n+1;i++)
			size[i]=0,pa[i]=i;

		int res=-1;
		for(int i=0;i<arr.size();i++)
		{
			int cur=arr[i];
			pa[cur]=find(cur+1);
			cnt[size[cur]]--,cnt[size[pa[cur]]]--;
			size[pa[cur]]+=size[cur]+1;
			cnt[size[pa[cur]]]++;
			if(cnt[m]>0) res=i+1;
		}
		return  res;
		}
};


int main() 
{
	Solution s;
	vector<int> arr={3,5,1,2,4};
	cout<<s.findLatestStep(arr,1)<<endl;
	arr.clear();arr={3,1,5,4,2};
	cout<<s.findLatestStep(arr,2)<<endl;
	return 0;
}
