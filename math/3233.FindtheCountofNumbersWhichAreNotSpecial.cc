/*
   You are given 2 positive integers l and r. For any number x, all positive divisors of x except x are called the proper divisors of x.

   A number is called special if it has exactly 2 proper divisors. For example:

   The number 4 is special because it has proper divisors 1 and 2.
   The number 6 is not special because it has proper divisors 1, 2, and 3.

   Return the count of numbers in the range [l, r] that are not special.



   Example 1:

Input: l = 5, r = 7

Output: 3

Explanation:

There are no special numbers in the range [5, 7].

Example 2:

Input: l = 4, r = 16

Output: 11

Explanation:

The special numbers in the range [4, 16] are 4 and 9.



Constraints:

1 <= l <= r <= 109

*/


#include"head.h"
class Solution {
	public:
		Solution()
		{
			for(int i=2;i<=N;i++)
			{
				if(!not_prime[i])
					prime.push_back(i);
				for(int j=0;j<prime.size()&&i*prime[j]<N;j++)
				{
					not_prime[i*prime[j]]=true;
					if(i%prime[j]==0)
						break;
				}
			}
			for(int i=0;i<prime.size();i++)
				prime[i]*=prime[i];
		}
		int getCount(int x)
		{
			return upper_bound(prime.begin(),prime.end(),x)-prime.begin();
		}
		int nonSpecialCount(int l, int r) {
			return r-l+1-getCount(r)+getCount(l-1);
		}
	private:
		static const int N=33334;
		bool not_prime[N];
		vector<int> prime;
};


int main() 
{
	Solution s;
	cout<<s.nonSpecialCount(5,7)<<endl;
	cout<<s.nonSpecialCount(4,16)<<endl;
	return 0;
}
