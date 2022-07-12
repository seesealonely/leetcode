/*
   Given a m 1140.StoneGameII 1140.StoneGameII.cc 1187.MakeArrayStrictlyIncreasing 1187.MakeArrayStrictlyIncreasing.cc 1349.MaximumStudentsTakingExam.cc 1434.NumberofWaystoWearDifferentHatstoEachOther 1434.NumberofWaystoWearDifferentHatstoEachOther.cc 1493.LongestSubarrayof1sAfterDeletingOneElement 1493.LongestSubarrayof1sAfterDeletingOneElement.cc 1690.StoneGameVII 1690.StoneGameVII.cc 1707.MaximumXORWithanElementFromArray 1707.MaximumXORWithanElementFromArray.cc 1723.FindMinimumTimetoFinishAllJobs 1723.FindMinimumTimetoFinishAllJobs.cc 1883.MinimumSkipstoArriveatMeetingOnTime 1883.MinimumSkipstoArriveatMeetingOnTime.cc 1883.MinimumSkipstoArriveatMeetingOnTime.h 1909.RemoveOneElementtoMaketheArrayStrictlyIncreasing 1909.RemoveOneElementtoMaketheArrayStrictlyIncreasing.cc 1911.MaximumAlternatingSubsequenceSum 1911.MaximumAlternatingSubsequenceSum.cc 2063.VowelsofAllSubstrings 2063.VowelsofAllSubstrings.cc 2063.VowelsofAllSubstrings.h 2110.NumberofSmoothDescentPeriodsofaStock 2110.NumberofSmoothDescentPeriodsofaStock.cc 2110.NumberofSmoothDescentPeriodsofaStock.h 756.PyramidTransitionMatrix 756.PyramidTransitionMatrix.cc 877.StoneGame 877.StoneGame.cc head.cc head.h head.o l.sh makefile n matrix seats that represent seats distributions in a classroom. If a seat is broken, it is denoted by '#' character otherwise it is denoted by a '.' character.

   Students can see the answers of those sitting next to the left, right, upper left and upper right, but he cannot see the answers of the student sitting directly in front or behind him. Return the maximum number of students that can take the exam together without any cheating being possible..

   Students must be placed in seats in good condition.



   Example 1:

Input: seats = [["#",".","#","#",".","#"],
[".","#","#","#","#","."],
["#",".","#","#",".","#"]]
Output: 4
Explanation: Teacher can place 4 students in available seats so they don't cheat on the exam.

Example 2:

Input: seats = [[".","#"],
["#","#"],
["#","."],
["#","#"],
[".","#"]]
Output: 3
Explanation: Place all students in available seats.

Example 3:

Input: seats = [["#",".",".",".","#"],
[".","#",".","#","."],
[".",".","#",".","."],
[".","#",".","#","."],
["#",".",".",".","#"]]
Output: 10
Explanation: Place students in available seats in column 1, 3 and 5.



Constraints:

seats contains only characters '.' and'#'.
m == seats.length
n == seats[i].length
1 <= m <= 8
1 <= n <= 8

*/
#include"head.h"
class Solution {
	public:
		int maxStudents(vector<vector<char>>& seats) {
			const int r=seats.size(),c=seats[0].size();
			vector<vector<int>> dp(r+1,vector<int>((1<<c),0));

			for(int i=1;i<=r;i++)
			{
				int state=0;
				for(int j=0;j<seats[i-1].size();j++)
					if(seats[i-1][j]=='.') state=state<<1|1;
					else
						state<<=1;

				for(int j=state;j;j=(j-1)&state)
				{
					if(j&(j<<1)||j&(j>>1)) continue;
					int count=countBit(j);
					for(int k=0;k<(1<<c);k++)
					{
						if((k<<1)&j||(k>>1)&j) continue;
						dp[i][j]=max(dp[i][j],dp[i-1][k]+count);
					}
				}
					dp[i][0]=*max_element(dp[i-1].begin(),dp[i-1].end());
			}
				return *max_element(dp.back().begin(),dp.back().end());
		}
		int countBit(int n)
		{
			int res=0;
			while(n)
			{
				while((n&1)==0)
					n=n>>1;
				n=n>>1;
				res++;
			}
			return res;
		}
};
int main() 
{
	Solution s;
	vector<vector<char>> v= {{'#','.','#','#','.','#'},
                {'.','#','#','#','#','.'},
                {'#','.','#','#','.','#'}};
	cout<<s.maxStudents(v)<<endl;
	return 0;
}
