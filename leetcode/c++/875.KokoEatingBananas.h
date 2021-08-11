/*
   Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

   Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

   Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

   Return the minimum integer k such that she can eat all the bananas within h hours.



   Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23



Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109

*/
#include"head.h"
class Solution {
	public:
		int minEatingSpeed(vector<int>& piles, int h) {
		return binarySearch(piles,h);
		}
		int binarySearch(vector<int>& piles, int h) {
			int n=piles.size(),l=1,r=1e9,m=0;
			while(l<r)
			{
				m=(l+r)/2;
				if(check(piles,m)>h)
					l=m+1;
				else
					r=m;
			}
			return l;
		}
		int check(vector<int> &p,int k)
		{
			int res=0;
			for(int i=0;i<p.size();i++)
				res+=p[i]/k==0?1:p[i]%k==0?p[i]/k:p[i]/k+1;
			return res;
		}
};
