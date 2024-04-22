/*
   You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

   We define the right direction as positive x-axis (increasing x-coordinate) and the left direction as negative x-axis (decreasing x-coordinate). Similarly, we define the up direction as positive y-axis (increasing y-coordinate) and the down direction as negative y-axis (decreasing y-coordinate)

   You have to place n people, including Alice and Bob, at these points such that there is exactly one person at every point. Alice wants to be alone with Bob, so Alice will build a rectangular fence with Alice's position as the upper left corner and Bob's position as the lower right corner of the fence (Note that the fence might not enclose any area, i.e. it can be a line). If any person other than Alice and Bob is either inside the fence or on the fence, Alice will be sad.

   Return the number of pairs of points where you can place Alice and Bob, such that Alice does not become sad on building the fence.

   Note that Alice can only build a fence with Alice's position as the upper left corner, and Bob's position as the lower right corner. For example, Alice cannot build either of the fences in the picture below with four corners (1, 1), (1, 3), (3, 1), and (3, 3), because:

   With Alice at (3, 3) and Bob at (1, 1), Alice's position is not the upper left corner and Bob's position is not the lower right corner of the fence.
   With Alice at (1, 3) and Bob at (1, 1), Bob's position is not the lower right corner of the fence.



   Example 1:

Input: points = [[1,1],[2,2],[3,3]]
Output: 0
Explanation: There is no way to place Alice and Bob such that Alice can build a fence with Alice's position as the upper left corner and Bob's position as the lower right corner. Hence we return 0.

Example 2:

Input: points = [[6,2],[4,4],[2,6]]
Output: 2
Explanation: There are two ways to place Alice and Bob such that Alice will not be sad:
- Place Alice at (4, 4) and Bob at (6, 2).
- Place Alice at (2, 6) and Bob at (4, 4).
You cannot place Alice at (2, 6) and Bob at (6, 2) because the person at (4, 4) will be inside the fence.

Example 3:

Input: points = [[3,1],[1,3],[1,1]]
Output: 2
Explanation: There are two ways to place Alice and Bob such that Alice will not be sad:
- Place Alice at (1, 1) and Bob at (3, 1).
- Place Alice at (1, 3) and Bob at (1, 1).
You cannot place Alice at (1, 3) and Bob at (3, 1) because the person at (1, 1) will be on the fence.
Note that it does not matter if the fence encloses any area, the first and second fences in the image are valid.



Constraints:

2 <= n <= 1000
points[i].length == 2
-109 <= points[i][0], points[i][1] <= 109
All points[i] are distinct.

*/


#include"head.h"
class Solution {
	public:
		int numberOfPairs(vector<vector<int>>& points) {
		const int n=points.size();
		vector<int> xs,ys;
		for(int i=0;i<n;i++)
		{
			xs.push_back(points[i][0]);
			ys.push_back(points[i][1]);
		}

		sort(xs.begin(),xs.end());
		const int cx=unique(xs.begin(),xs.end())-xs.begin();
		xs.resize(cx);

		sort(ys.begin(),ys.end());
		const int cy=unique(ys.begin(),ys.end())-ys.begin();
		ys.resize(cy);

		vector<vector<int>> sum(cx+1,vector<int>(cy+1,0));
		for(int i=0;i<n;i++)
		{
			points[i][0]=lower_bound(xs.begin(),xs.end(),points[i][0])-xs.begin()+1;
			points[i][1]=lower_bound(ys.begin(),ys.end(),points[i][1])-ys.begin()+1;
			++sum[points[i][0]][points[i][1]];
		}
		for(int i=1;i<=cx;i++)
			for(int j=1;j<=cy;j++)
				sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];

		int res=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(i==j)
					continue;
				int x1=points[i][0],y1=points[i][1];
				int x2=points[j][0],y2=points[j][1];
				
				if(!(x1<=x2&&y1>=y2))
					continue;

				if(sum[x2][y1]-sum[x1-1][y1]-sum[x2][y2-1]+sum[x1-1][y2-1]==2)
					++res;
			}
		return res;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> points = {{1,1},{2,2},{3,3}};
	cout<<s.numberOfPairs(points)<<endl;
	points.clear();points = {{6,2},{4,4},{2,6}};
	cout<<s.numberOfPairs(points)<<endl;
	points.clear();points = {{3,1},{1,3},{1,1}};
	cout<<s.numberOfPairs(points)<<endl;
	return 0;
}
