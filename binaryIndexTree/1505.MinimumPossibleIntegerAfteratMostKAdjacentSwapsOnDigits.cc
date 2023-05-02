/*
   You are given a string num representing the digits of a very large integer and an integer k. You are allowed to swap any two adjacent digits of the integer at most k times.

   Return the minimum integer you can obtain also as a string.



   Example 1:

Input: num = "4321", k = 4
Output: "1342"
Explanation: The steps to obtain the minimum integer from 4321 with 4 adjacent swaps are shown.

Example 2:

Input: num = "100", k = 1
Output: "010"
Explanation: It's ok for the output to have leading zeros, but the input is guaranteed not to have any leading zeros.

Example 3:

Input: num = "36789", k = 1000
Output: "36789"
Explanation: We can keep the number without any swaps.



Constraints:

1 <= num.length <= 3 1505.MinimumPossibleIntegerAfteratMostKAdjacentSwapsOnDigits.cc head.cc head.h head.o lib.a l.sh 104
num consists of only digits and does not contain leading zeros.
1 <= k <= 109

*/


#include"head.h"
class Solution {
	public:
		vector<int> t;
		void update(int x,int n,int y)
		{
			for(;x<=n;x+=x&-x)
				t[x]+=y;
		}

		int query(int x)
		{
			int sum=0;
			for(;x;x-=x&-x)
				sum+=t[x];
			return sum;
		}
		string minInteger(string num, int k) {
			const int n=num.size();
			vector<queue<int>> v(10);

			for(int i=0;i<n;i++)
				v[num[i]-'0'].push(i);

			t.resize(n+1,0);

			for(int i=0;i<n;i++)
				for(int j=0;j<10;j++)
				{
					if(v[j].empty())  continue;

					int x=v[j].front();
					int offset=query(x+1);

					if(x-offset<=k)
					{
						num[i]=j+'0';
						k-=x-offset;

						update(x+1,n,1);

						v[j].pop();
						break;
					}
				}
			return num;
		}
};


int main() 
{
	Solution s;
	cout<<s.minInteger("4321",4)<<endl;
	cout<<s.minInteger("100",1)<<endl;
	cout<<s.minInteger("36789",1000)<<endl;
	return 0;
}
