/*
   You are given a 0-indexed array words containing n strings.

   Let's define a join operation join(x, y) between two strings x and y as concatenating them into xy. However, if the last character of x is equal to the first character of y, one of them is deleted.

   For example join("ab", "ba") = "aba" and join("ab", "cde") = "abcde".

   You are to perform n - 1 join operations. Let str0 = words[0]. Starting from i = 1 up to i = n - 1, for the ith operation, you can do one of the following:

   Make stri = join(stri - 1, words[i])
   Make stri = join(words[i], stri - 1)

   Your task is to minimize the length of strn - 1.

   Return an integer denoting the minimum possible length of strn - 1.



   Example 1:

Input: words = ["aa","ab","bc"]
Output: 4
Explanation: In this example, we can perform join operations in the following order to minimize the length of str2:
str0 = "aa"
str1 = join(str0, "ab") = "aab"
str2 = join(str1, "bc") = "aabc"
It can be shown that the minimum possible length of str2 is 4.

Example 2:

Input: words = ["ab","b"]
Output: 2
Explanation: In this example, str0 = "ab", there are two ways to get str1:
join(str0, "b") = "ab" or join("b", str0) = "bab".
The first string, "ab", has the minimum length. Hence, the answer is 2.

Example 3:

Input: words = ["aaa","c","aba"]
Output: 6
Explanation: In this example, we can perform join operations in the following order to minimize the length of str2:
str0 = "aaa"
str1 = join(str0, "c") = "aaac"
str2 = join("aba", str1) = "abaaac"
It can be shown that the minimum possible length of str2 is 6.





Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 50
Each character in words[i] is an English lowercase letter

*/


#include"head.h"
class Solution {
	public:
		int minimizeConcatenatedLength(vector<string>& words) {
			const int N=26;
			int f[N][N],g[N][N];

			memset(f,0x3f,sizeof(f));
			memset(g,0x3f,sizeof(f));

			f[words[0].front()-'a'][words[0].back()-'a']=words[0].size();

			for(int i=1;i<words.size();i++)
			{
				int len=words[i].size();
				int s=words[i].front()-'a';
				int e=words[i].back()-'a';

				for(int j=0;j<26;j++)
					for(int k=0;k<26;k++)
					{
						g[j][e]=min(g[j][e],f[j][k]+len-(s==k));
						g[s][k]=min(g[s][k],f[j][k]+len-(e==j));
					}
				memcpy(f,g,sizeof(f));
				memset(g,0x3f,sizeof(g));
			}

			int res=INT_MAX;
			for(int i=0;i<26;i++)
				for(int j=0;j<26;j++)
					res=min(res,f[i][j]);
			return res;
		}
};


int main() 
{
	Solution s;
	vector<string> words={"aa","ab","bc"};
	cout<<s.minimizeConcatenatedLength(words)<<endl;
	words.clear();words={"ab","b"};
	cout<<s.minimizeConcatenatedLength(words)<<endl;
	words.clear();words={"aaa","c","aba"};
	cout<<s.minimizeConcatenatedLength(words)<<endl;
	return 0;
}
