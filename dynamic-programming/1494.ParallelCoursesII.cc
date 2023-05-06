/*
   You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given an array relations where relations[i] = [prevCoursei, nextCoursei], representing a prerequisite relationship between course prevCoursei and course nextCoursei: course prevCoursei has to be taken before course nextCoursei. Also, you are given the integer k.

   In one semester, you can take at most k courses as long as you have taken all the prerequisites in the previous semesters for the courses you are taking.

   Return the minimum number of semesters needed to take all courses. The testcases will be generated such that it is possible to take every course.



   Example 1:

Input: n = 4, relations = [[2,1],[3,1],[1,4]], k = 2
Output: 3
Explanation: The figure above represents the given graph.
In the first semester, you can take courses 2 and 3.
In the second semester, you can take course 1.
In the third semester, you can take course 4.

Example 2:

Input: n = 5, relations = [[2,1],[3,1],[4,1],[1,5]], k = 2
Output: 4
Explanation: The figure above represents the given graph.
In the first semester, you can only take courses 2 and 3 since you cannot take more than two per semester.
In the second semester, you can take course 4.
In the third semester, you can take course 1.
In the fourth semester, you can take course 5.



Constraints:

1 <= n <= 15
1 <= k <= n
0 <= relations.length <= n * (n-1) / 2
relations[i].length == 2
1 <= prevCoursei, nextCoursei <= n
prevCoursei != nextCoursei
All the pairs [prevCoursei, nextCoursei] are unique.
The given graph is a directed acyclic graph.

*/


#include"head.h"
class Solution {
	public:
		int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
			int N=1<<n;
			vector<int> precourse(n);
			for(int i=0;i<relations.size();i++)
				precourse[relations[i][1]-1]|=(1<<(relations[i][0]-1));

			vector<int> prebit(N),success(N);
			for(int mask=0;mask<N;mask++)
				if(countBit(mask)<=k)
				{
					for(int i=0;i<n;i++)
						if(mask&(1<<i))
							prebit[mask]|=precourse[i];
					success[mask]=((mask&prebit[mask])==0);
				}

			vector<int> dp(N,INT_MAX>>1);
			dp[0]=0;
			for(int mask=0;mask<N;mask++)
				for(int submask=mask;submask;submask=mask&(submask-1))
					if(success[submask]&&((mask&prebit[submask])==prebit[submask]))
						dp[mask]=min(dp[mask],dp[mask^submask]+1);

			return dp[N-1];
		}
		int countBit(int mask)
		{
			int res=0;
			while(mask)
			{
				if(mask&1) res++;
				mask>>=1;
			}
			return res;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> relations={{2,1},{3,1},{1,4}};
	cout<<s.minNumberOfSemesters(4,relations,2)<<endl;
	relations.clear();relations={{2,1},{3,1},{4,1},{1,5}};
	cout<<s.minNumberOfSemesters(5,relations,2)<<endl;
	return 0;
}
