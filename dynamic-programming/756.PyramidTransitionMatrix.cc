/*
   You are stacking blocks to form a pyramid. Each block has a color, which is represented by a single letter. Each row of blocks contains one less block than the row beneath it and is centered on top.

   To make the pyramid aesthetically pleasing, there are only specific triangular patterns that are allowed. A triangular pattern consists of a single block stacked on top of two blocks. The patterns are given as a list of three-letter strings allowed, where the first two characters of a pattern represent the left and right bottom blocks respectively, and the third character is the top block.

   For example, "ABC" represents a triangular pattern with a 'C' block stacked on top of an 'A' (left) and 'B' (right) block. Note that this is different from "BAC" where 'B' is on the left bottom and 'A' is on the right bottom.

   You start with a bottom row of blocks bottom, given as a single string, that you must use as the base of the pyramid.

   Given bottom and allowed, return true if you can build the pyramid all the way to the top such that every triangular pattern in the pyramid is in allowed, or false otherwise.



   Example 1:

Input: bottom = "BCD", allowed = ["BCC","CDE","CEA","FFF"]
Output: true
Explanation: The allowed triangular patterns are shown on the right.
Starting from the bottom (level 3), we can build "CE" on level 2 and then build "E" on level 1.
There are three triangular patterns in the pyramid, which are "BCC", "CDE", and "CEA". All are allowed.

Example 2:

Input: bottom = "AAAA", allowed = ["AAB","AAC","BCD","BBE","DEF"]
Output: false
Explanation: The allowed triangular patterns are shown on the right.
Starting from the bottom (level 4), there are multiple ways to build level 3, but trying all the possibilites, you will get always stuck before building level 1.



Constraints:

2 <= bottom.length <= 6
0 <= allowed.length <= 216
allowed[i].length == 3
The letters in all input strings are from the set {'A', 'B', 'C', 'D', 'E', 'F'}.
All the values of allowed are unique.

*/
#define c11
#include"head.h"
class Solution {
	public:
		bool pyramidTransition(string bottom, vector<string>& allowed) {
			unordered_map<char,unordered_set<string>> h;
			for(int i=0;i<allowed.size();i++)
				h[allowed[i][2]].insert(allowed[i].substr(0,2));

			const int n=bottom.size();
			vector<vector<vector<bool>>> dp(n,vector<vector<bool>>(n,vector<bool>(6,false)));
		
			for(int i=0;i<n;i++)
				dp[n-1][i][bottom[i]-'A']=true;
			for(int i=n-2;i>=0;i--)
				for(int j=0;j<=i;j++)
					for(char c='A';c<='F';c++)
					{
						if(!h.count(c))
							continue;
						for(unordered_set<string>::iterator it=h[c].begin();it!=h[c].end();it++)
							if(dp[i+1][j][(*it)[0]-'A']&&dp[i+1][j+1][(*it)[1]-'A'])
								dp[i][j][c-'A']=true;
					}

			for(int i=0;i<6;i++)
				if(dp[0][0][i])
					return true;
			return false;
		}
};
int main() 
{
	Solution s;
	vector<string> v={"BCC","CDE","CEA","FFF"};
	cout<<s.pyramidTransition("BCD",v)<<endl;
	v.clear();v={"AAB","AAC","BCD","BBE","DEF"};
	cout<<s.pyramidTransition("AAAA",v)<<endl;
	return 0;
}
