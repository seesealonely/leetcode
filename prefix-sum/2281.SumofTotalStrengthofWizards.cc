/*
   As the ruler of a kingdom, you have an army of wizards at your command.

   You are given a 0-indexed integer array strength, where strength[i] denotes the strength of the ith wizard. For a contiguous group of wizards (i.e. the wizards' strengths form a subarray of strength), the total strength is defined as the product of the following two values:

   The strength of the weakest wizard in the group.
   The total of all the individual strengths of the wizards in the group.

   Return the sum of the total strengths of all contiguous groups of wizards. Since the answer may be very large, return it modulo 109 + 7.

   A subarray is a contiguous non-empty sequence of elements within an array.



   Example 1:

Input: strength = [1,3,1,2]
Output: 44
Explanation: The following are all the contiguous groups of wizards:
- [1] from [1,3,1,2] has a total strength of min([1]) * sum([1]) = 1 * 1 = 1
- [3] from [1,3,1,2] has a total strength of min([3]) * sum([3]) = 3 * 3 = 9
- [1] from [1,3,1,2] has a total strength of min([1]) * sum([1]) = 1 * 1 = 1
- [2] from [1,3,1,2] has a total strength of min([2]) * sum([2]) = 2 * 2 = 4
- [1,3] from [1,3,1,2] has a total strength of min([1,3]) * sum([1,3]) = 1 * 4 = 4
- [3,1] from [1,3,1,2] has a total strength of min([3,1]) * sum([3,1]) = 1 * 4 = 4
- [1,2] from [1,3,1,2] has a total strength of min([1,2]) * sum([1,2]) = 1 * 3 = 3
- [1,3,1] from [1,3,1,2] has a total strength of min([1,3,1]) * sum([1,3,1]) = 1 * 5 = 5
- [3,1,2] from [1,3,1,2] has a total strength of min([3,1,2]) * sum([3,1,2]) = 1 * 6 = 6
- [1,3,1,2] from [1,3,1,2] has a total strength of min([1,3,1,2]) * sum([1,3,1,2]) = 1 * 7 = 7
The sum of all the total strengths is 1 + 9 + 1 + 4 + 4 + 4 + 3 + 5 + 6 + 7 = 44.

Example 2:

Input: strength = [5,4,6]
Output: 213
Explanation: The following are all the contiguous groups of wizards: 
- [5] from [5,4,6] has a total strength of min([5]) * sum([5]) = 5 * 5 = 25
- [4] from [5,4,6] has a total strength of min([4]) * sum([4]) = 4 * 4 = 16
- [6] from [5,4,6] has a total strength of min([6]) * sum([6]) = 6 * 6 = 36
- [5,4] from [5,4,6] has a total strength of min([5,4]) * sum([5,4]) = 4 * 9 = 36
- [4,6] from [5,4,6] has a total strength of min([4,6]) * sum([4,6]) = 4 * 10 = 40
- [5,4,6] from [5,4,6] has a total strength of min([5,4,6]) * sum([5,4,6]) = 4 * 15 = 60
The sum of all the total strengths is 25 + 16 + 36 + 36 + 40 + 60 = 213.



Constraints:

1 <= strength.length <= 105
1 <= strength[i] <= 109

*/


#include"head.h"
class Solution {
	public:
		typedef long long ll;
		static const int mod=1e9+7;
		int totalStrength(vector<int>& strength) {
			const int n=strength.size();

			vector<int> presum(n),sum(n);
			presum[0]=sum[0]=strength[0];

			for(int i=1;i<n;i++)
			{
				presum[i]=(presum[i-1]+strength[i])%mod;
				sum[i]=(sum[i-1]+presum[i])%mod;
			}

			stack<int> st;
			vector<int> l(n),r(n);
			strength.push_back(0);

			for(int i=0;i<=n;i++)
			{
				while(!st.empty()&&strength[i]<=strength[st.top()])
				{
					int top=st.top();
					st.pop();

					r[top]=i-1;
					if(st.empty()) 
						l[top]=0;
					else
						l[top]=st.top()+1;
				}
				st.push(i);
			}
			int res=0;
			for(int i=0;i<n;i++)
			{
				int w=strength[i];
				ll rsum=calc(i,r[i],sum),lcnt=i-l[i]+1;
				ll lsum=calc(l[i]-1,i-1,sum),rcnt=r[i]-i+1;

				res=(res+rsum*lcnt%mod*w)%mod;
				res=(res-lsum*rcnt%mod*w)%mod;
			}

			return (res+mod)%mod;
		}
		int calc(int l,int r,const vector<int> &s)
		{
			if(r<0) return 0;
			if(l<=0) return s[r];

			return (s[r]-s[l-1])%mod;
		}
};


int main() 
{
	Solution s;
	vector<int> v={1,3,1,2};
	cout<<s.totalStrength(v)<<endl;
	v.clear();v={5,4,6};
	cout<<s.totalStrength(v)<<endl;
	return 0;
}
