/*
   A certain bug's home is on the x-axis at position x. Help them get there from position 0.

   The bug jumps according to the following rules:

   It can jump exactly a positions forward (to the right).
   It can jump exactly b positions backward (to the left).
   It cannot jump backward twice in a row.
   It cannot jump to any forbidden positions.

   The bug may jump forward beyond its home, but it cannot jump to positions numbered with negative integers.

   Given an array of integers forbidden, where forbidden[i] means that the bug cannot jump to the position forbidden[i], and integers a, b, and x, return the minimum number of jumps needed for the bug to reach its home. If there is no possible sequence of jumps that lands the bug on position x, return -1.



   Example 1:

Input: forbidden = [14,4,18,1,15], a = 3, b = 15, x = 9
Output: 3
Explanation: 3 jumps forward (0 -> 3 -> 6 -> 9) will get the bug home.

Example 2:

Input: forbidden = [8,3,16,6,12,20], a = 15, b = 13, x = 11
Output: -1

Example 3:

Input: forbidden = [1,6,2,14,5,17,4], a = 16, b = 9, x = 7
Output: 2
Explanation: One jump forward (0 -> 16) then one jump backward (16 -> 7) will get the bug home.



Constraints:

1 <= forbidden.length <= 1000
1 <= a, b, forbidden[i] <= 2000
0 <= x <= 2000
All the elements in forbidden are distinct.
Position x is not forbidden.

*/

#define c11
#include"head.h"
class Solution {
	public:
		int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
#define N 6001
			unordered_set<int> f(forbidden.begin(),forbidden.end());

			queue<vector<int>> q;
			vector<vector<int>> dis(2,vector<int>(N,INT_MAX));

			q.push({0,0});

			dis[0][0]=0;
			while(!q.empty())
			{
				int step=q.front()[1],d=q.front()[0];
				q.pop();
				if(step==x) 
					return dis[d][step];	

				if(step+a<N&&f.find(step+a)==f.end()&&dis[0][step+a]>dis[d][step]+1)
				{
					dis[0][step+a]=dis[d][step]+1;
					q.push({0,step+a});
				}

				if(d==0&&step-b>=0&&f.find(step-b)==f.end()&&dis[1][step-b]>dis[d][step]+1)
				{
					dis[1][step-b]=dis[d][step]+1;
					q.push({1,step-b});
				}
			}
			return -1;
		}
};


int main() 
{
	Solution s;
	vector<int> v={14,4,18,1,15};
	cout<<s.minimumJumps(v,3,15,9)<<endl;
	v.clear();v={8,3,16,6,12,20};
	cout<<s.minimumJumps(v,15,13,11)<<endl;
	v.clear();v={1,6,2,14,5,17,4};
	cout<<s.minimumJumps(v,16,9,7)<<endl;
	return 0;
}
