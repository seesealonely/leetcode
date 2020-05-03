/*
   Given an integer array A, and an integer target, return the number of tuples i, j, k  such that i < j < k and A[i] + A[j] + A[k] == target.

   As the answer can be very large, return it modulo 10^9 + 7.



   Example 1:

Input: A = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation: 
Enumerating by the values (A[i], A[j], A[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.

Example 2:

Input: A = [1,1,2,2,2,2], target = 5
Output: 12
Explanation: 
A[i] = 1, A[j] = A[k] = 2 occurs 12 times:
We choose one 1 from [1,1] in 2 ways,
and two 2s from [2,2,2,2] in 6 ways.



Note:

3 <= A.length <= 3000
0 <= A[i] <= 100
0 <= target <= 300

*/
#define c11
#include"head.h"

class Solution {
	public:
		int threeSumMulti(vector<int>& A, int target) {
		return firstWay(A,target);
		}
		int firstWay(vector<int>& A, int target) {
			unordered_map<int,int> fre;
			int a=0,b=0,c=0;
			long res=0;	
			for(int i=0;i<A.size();i++)
				fre[A[i]]++;
			for(unordered_map<int,int>::iterator it1=fre.begin();it1!=fre.end();it1++)
			{
			for(unordered_map<int,int>::iterator it2=fre.begin();it2!=fre.end();it2++)
				{
					a=it1->first,b=it2->first,c=target-(a+b);
					if(!fre.count(c)) continue;
					if(a==b&&b==c)
						res+=fre[a]*(fre[b]-1)*(fre[c]-2)/6;	
					else if(a==b&&b!=c)
						res+=fre[a]*(fre[b]-1)/2*fre[c];
					else if(a<b&&b<c)
						res+=fre[a]*fre[b]*fre[c];
				}
			}
			return res%int(1e9+7);
		}
};
