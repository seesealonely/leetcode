/*
   There are n persons on a social media website. You are given an integer array ages where ages[i] is the age of the ith person.

   A Person x will not send a friend request to a person y (x != y) if any of the following conditions is true:

   age[y] <= 0.5 1574.ShortestSubarraytobeRemovedtoMakeArraySorted.cc 1574.ShortestSubarraytobeRemovedtoMakeArraySorted.h 475.Heaters 475.Heaters.cc 475.Heaters.h 522.LongestUncommonSubsequenceII 522.LongestUncommonSubsequenceII.cc 522.LongestUncommonSubsequenceII.h 825.FriendsOfAppropriateAges.cc 825.FriendsOfAppropriateAges.h head.cc head.h head.o lib.a l.sh makefile age[x] + 7
   age[y] > age[x]
   age[y] > 100 && age[x] < 100

   Otherwise, x will send a friend request to y.

   Note that if x sends a request to y, y will not necessarily send a request to x. Also, a person will not send a friend request to themself.

   Return the total number of friend requests made.



   Example 1:

Input: ages = [16,16]
Output: 2
Explanation: 2 people friend request each other.

Example 2:

Input: ages = [16,17,18]
Output: 2
Explanation: Friend requests are made 17 -> 16, 18 -> 17.

Example 3:

Input: ages = [20,30,100,110,120]
Output: 3
Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.



Constraints:

n == ages.length
1 <= n <= 2 * 104
1 <= ages[i] <= 120
*/
#define c11
#include"head.h"
class Solution {
	public:
		int numFriendRequests(vector<int>& ages) {
			int res=0;
			unordered_map<int,int> fre;
			for(int i=0;i<ages.size();i++)
				fre[ages[i]]++;

			for(unordered_map<int,int>::iterator i=fre.begin();i!=fre.end();i++)
			for(unordered_map<int,int>::iterator j=fre.begin();j!=fre.end();j++)
			{
				if(!isValid(i->first,j->first))
					continue;
				if(i->first==j->first)
					res+=i->second*(i->second-1);
				else
					res+=i->second*j->second;
			}
			return res;
		}
		bool isValid(int a,int b)
		{
			if(b<=0.5*a+7||a<b||b>100&&a<100)
				return false;
			return true;
		}
};
