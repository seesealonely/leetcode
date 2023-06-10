/*
   We define str = [s, n] as the string str which consists of the string s concatenated n times.

   For example, str == ["abc", 3] =="abcabcabc".

   We define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1.

   For example, s1 = "abc" can be obtained from s2 = "abdbec" based on our definition by removing the bolded underlined characters.

   You are given two strings s1 and s2 and two integers n1 and n2. You have the two strings str1 = [s1, n1] and str2 = [s2, n2].

   Return the maximum integer m such that str = [str2, m] can be obtained from str1.



   Example 1:

Input: s1 = "acb", n1 = 4, s2 = "ab", n2 = 2
Output: 2

Example 2:

Input: s1 = "acb", n1 = 1, s2 = "acb", n2 = 1
Output: 1



Constraints:

1 <= s1.length, s2.length <= 100
s1 and s2 consist of lowercase English letters.
1 <= n1, n2 <= 106

*/


#include"head.h"
class Solution {
	public:
		int getMaxRepetitions(string s1, int n1, string s2, int n2) {
			const int len=s2.size();
			vector<int> dp(len,0);
			for(int i=0;i<len;i++)
			{
				int p=i;
				for(int j=0;j<s1.size();j++)
					if(s1[j]==s2[p])
					{
						p=(p+1)%len;
						dp[i]++;
					}
			}

			int sum=0,idx=0;
			for(int i=0;i<n1;i++)
			{
				sum+=dp[idx];
				idx=(idx+dp[idx])%len;
			}
			return sum/len/n2;
		}
};


int main() 
{
	Solution s;
	cout<<s.getMaxRepetitions("acb",4,"ab",2)<<endl;
	cout<<s.getMaxRepetitions("acb",1,"acb",1)<<endl;
	return 0;
}
