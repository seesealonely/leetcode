/*
   You are given two jugs with capacities jug1Capacity and jug2Capacity liters. There is an infinite amount of water supply available. Determine whether it is possible to measure exactly targetCapacity liters using these two jugs.

   If targetCapacity liters of water are measurable, you must have targetCapacity liters of water contained within one or both buckets by the end.

   Operations allowed:

   Fill any of the jugs with water.
   Empty any of the jugs.
   Pour water from one jug into another till the other jug is completely full, or the first jug itself is empty.



   Example 1:

Input: jug1Capacity = 3, jug2Capacity = 5, targetCapacity = 4
Output: true
Explanation: The famous Die Hard example

Example 2:

Input: jug1Capacity = 2, jug2Capacity = 6, targetCapacity = 5
Output: false

Example 3:

Input: jug1Capacity = 1, jug2Capacity = 2, targetCapacity = 3
Output: true



Constraints:

1 <= jug1Capacity, jug2Capacity, targetCapacity <= 106

*/
#include"head.h"
class Solution {
	public:
		bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
		return oneWay(jug1Capacity,jug2Capacity,targetCapacity) ;
		}
		bool oneWay(int i,int j,int k)
		{
			if(i+j<k) return false;
			if(i==k||j==k||i+j==k)
				return true;
			return k%gcd(i,j)==0;
		}
		int gcd(int i,int j)
		{
			while(j)
			{
				int tmp=j;
				j=i%j;
				i=tmp;
			}
			return i;
		}
};
