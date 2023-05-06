/*
   Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].



   Example 1:

Input: n = 13, k = 2
Output: 10
Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.

Example 2:

Input: n = 1, k = 1
Output: 1



Constraints:

1 <= k <= n <= 109

*/


#include"head.h"
class Solution {
	public:
		typedef long long ll;
		int count(int prefix,int n)
		{
			int tot=0;

			ll t=prefix,k=1;
			while(t*10<=n)
			{
				tot+=k;
				k*=10;
				t*=10;
			}

			if(n-t<k)
				tot+=n-t+1;
			else 
				tot+=k;
			return tot;
		}
		int findKthNumber(int n, int k) {
		int prefix=1;
		while(k>1)
		{
			int size=count(prefix,n);
			if(k>size)
			{
				k-=size;
				prefix++;
			}
			else
				prefix=prefix*10,k--;
		}
		return prefix;

		}
};


int main() 
{
	Solution s;
	cout<<s.findKthNumber(13,2)<<endl;
	cout<<s.findKthNumber(1,1)<<endl;
	return 0;
}
