/*
   Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

   Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:

Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]

*/
#define c11
#include"head.h"

class Solution {
	public:
		int numberOfBoomerangs(vector<pair<int, int>>& points) {
			int res=0;
			for(int i=0;i<points.size();i++)
			{
				unordered_map<int,int> hash;
				for(int j=0;j<points.size();j++)
				{
					if(i==j) continue;
					int d=distance(points[i],points[j]);
					hash[d]++;
				} 
				for(unordered_map<int,int>::iterator it=hash.begin();it!=hash.end();it++)
					res+=(it->second-1)*(it->second);
			}
			return res;
		}
		int distance(pair<int,int> i,pair<int,int> j)
		{
			int x=i.first-j.first;
			int y=i.second-j.second;
			return x*x+y*y;
		}
};
