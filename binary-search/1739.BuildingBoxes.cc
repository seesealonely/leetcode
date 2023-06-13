/*
   You have a cubic storeroom where the width, length, and height of the room are all equal to n units. You are asked to place n boxes in this room where each box is a cube of unit side length. There are however some rules to placing the boxes:

   You can place the boxes anywhere on the floor.
   If box x is placed on top of the box y, then each side of the four vertical sides of the box y must either be adjacent to another box or to a wall.

   Given an integer n, return the minimum possible number of boxes touching the floor.



   Example 1:

Input: n = 3
Output: 3
Explanation: The figure above is for the placement of the three boxes.
These boxes are placed in the corner of the room, where the corner is on the left side.

Example 2:

Input: n = 4
Output: 3
Explanation: The figure above is for the placement of the four boxes.
These boxes are placed in the corner of the room, where the corner is on the left side.

Example 3:

Input: n = 10
Output: 6
Explanation: The figure above is for the placement of the ten boxes.
These boxes are placed in the corner of the room, where the corner is on the back side.



Constraints:

1 <= n <= 109

*/


#include"head.h"
class Solution {
	private:
		typedef long long ll;
		ll get(ll x)
		{
			ll l=1,r=x;
			while(l<r)
			{
				ll mid=(l+r)>>1;
				if((mid+1)*(mid+2)>>1>x) r=mid;
				else
					l=mid+1;
			}

			return l;
		}
		bool check(ll x,int n)
		{
			ll tot=x;
			while(x>=3&&tot<n)
			{
				ll t=get(x);
				ll r=x-t*(t+1)/2;
				x=(t-1)*t/2;
				if(r>0) x+=r-1;
				tot+=x;
			}
			return tot>=n;
		}
	public:
		int minimumBoxes(int n) {
		ll l=1,r=n;
		while(l<r)
		{
			ll mid=(l+r)>>1;
			if(check(mid,n)) r=mid;
			else l=mid+1;
		}
		return l;
		}
};


int main() 
{
	Solution s;
	cout<<s.minimumBoxes(3)<<endl;
	cout<<s.minimumBoxes(4)<<endl;
	cout<<s.minimumBoxes(10)<<endl;
	return 0;
}
