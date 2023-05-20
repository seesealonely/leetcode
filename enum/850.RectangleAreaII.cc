/*
   You are given a 2D array of axis-aligned rectangles. Each rectangle[i] = [xi1, yi1, xi2, yi2] denotes the ith rectangle where (xi1, yi1) are the coordinates of the bottom-left corner, and (xi2, yi2) are the coordinates of the top-right corner.

   Calculate the total area covered by all rectangles in the plane. Any area covered by two or more rectangles should only be counted once.

   Return the total area. Since the answer may be too large, return it modulo 109 + 7.



   Example 1:

Input: rectangles = [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
Output: 6
Explanation: A total area of 6 is covered by all three rectangles, as illustrated in the picture.
From (1,1) to (2,2), the green and red rectangles overlap.
From (1,0) to (2,3), all three rectangles overlap.

Example 2:

Input: rectangles = [[0,0,1000000000,1000000000]]
Output: 49
Explanation: The answer is 1018 modulo (109 + 7), which is 49.



Constraints:

1 <= rectangles.length <= 200
rectanges[i].length == 4
0 <= xi1, yi1, xi2, yi2 <= 109
xi1 <= xi2
yi1 <= yi2

*/


#include"head.h"
class Solution {
	public:
		typedef long long int ll;
		vector<vector<int>> rectangles;
		const int mod=1e9+7;
		int rectangleArea(vector<vector<int>>& rectangles) {
		this->rectangles=rectangles;

		vector<int> lines;
		for(int i=0;i<rectangles.size();i++)
		lines.push_back(rectangles[i][0]),lines.push_back(rectangles[i][2]);

		sort(lines.begin(),lines.end());

		ll res=0;
		for(int i=1;i<lines.size();i++)
			if(lines[i-1]!=lines[i])
				res=(res+calc(lines[i-1],lines[i]))%mod;

		return  res%mod;
		}
		class Node{
			public:
				int l,r;
			bool operator<(const Node &p) const 
			{
				if(l!=p.r) return l<p.l;
				return r<p.r;
			}
		};
		ll calc(int l,int r)
		{
			vector<Node> cur;

			for(int i=0;i<rectangles.size();i++)
				if(rectangles[i][0]<=l&&r<=rectangles[i][2])
					cur.push_back({rectangles[i][1],rectangles[i][3]});

			sort(cur.begin(),cur.end());

			int tot=0,s=-1,e=-1;

			for(int i=0;i<cur.size();i++)
			{
				Node seg=cur[i];
				if(seg.l>e) tot+=e-s,s=seg.l;
				e=max(e,seg.r);
			}

			tot+=e-s;
			return (ll)tot*(r-l);
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> rectangles = {{0,0,2,2},{1,0,2,3},{1,0,3,1}};
	cout<<s.rectangleArea(rectangles)<<endl;
	rectangles.clear();rectangles={{0,0,1000000000,1000000000}};
	cout<<s.rectangleArea(rectangles)<<endl;
	return 0;
}
