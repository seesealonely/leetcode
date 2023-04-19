/*
   Given n orders, each order consist in pickup and delivery services.

   Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i).

   Since the answer may be too large, return it modulo 10^9 + 7.



   Example 1:

Input: n = 1
Output: 1
Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup 1.

Example 2:

Input: n = 2
Output: 6
Explanation: All possible orders:
(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.

Example 3:

Input: n = 3
Output: 90



Constraints:

1 <= n <= 500

*/


#include"head.h"
class Solution {
	public:
		int countOrders(int n) {
		const int mod=1e9+7;
		long long p=1;
		for(int i=2;i<=n;i++)
		{
			long long cnt=2*(i-1)+1;
			long long cur=cnt*(cnt-1)/2+cnt;
			p=(cur*p)%mod;
		}

		return p;
		}
};


int main() 
{
	Solution s;
	cout<<s.countOrders(1)<<endl;
	cout<<s.countOrders(2)<<endl;
	cout<<s.countOrders(3)<<endl;
	return 0;
}
