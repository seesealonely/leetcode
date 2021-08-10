/*
   Given two positive integers n and k, the binary string Sn is formed as follows:

   S1 = "0"
   Si = Si-1 + "1" + reverse(invert(Si-1)) for i > 1

   Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).

   For example, the first 4 strings in the above sequence are:

   S1 = "0"
   S2 = "011"
   S3 = "0111001"
   S4 = "011100110110001"

   Return the kth bit in Sn. It is guaranteed that k is valid for the given n.



   Example 1:

Input: n = 3, k = 1
Output: "0"
Explanation: S3 is "0111001". The first bit is "0".

Example 2:

Input: n = 4, k = 11
Output: "1"
Explanation: S4 is "011100110110001". The 11th bit is "1".

Example 3:

Input: n = 1, k = 1
Output: "0"

Example 4:

Input: n = 2, k = 3
Output: "1"



Constraints:

1 <= n <= 20
1 <= k <= 2n - 1
*/
#include"head.h"
class Solution {
	public:
		char findKthBit(int n, int k) {
			return binary(n,k);
			return origin(n,k);
		}
		char binary(int n, int k) {
			if(k==1||n==1) return '0';
			int len=(1<<n)-1,m=len/2+1;
			if(k==m)
				return '1';
			if(k<m)
				return binary(n-1,k);
			else
				return binary(n-1,len-(k-1))^1;
		}
		char origin(int n, int k) {
		string s="0";
		for(int i=0;i<n;i++)
			s=reverse(s);
		return s[k-1];	
		}
		string  reverse(string &s)
		{
			int n=s.size();
			s+="1";
			string res;
			for(int i=0;i<n;i++)
				res+=s[i]=='0'?'1':'0';
			for(int l=0,r=n-1;l<r;l++,r--)
			{char t=res[l];res[l]=res[r];res[r]=t;}
			return res=s+res;
		}
};
