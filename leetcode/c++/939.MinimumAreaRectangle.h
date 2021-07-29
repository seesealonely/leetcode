/*


   Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points, with sides parallel to the x and y axes.

   If there isn't any rectangle, return 0.



   Example 1:

Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4

Example 2:

Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2



Note:

1 <= points.length <= 500
0 <= points[i][0] <= 40000
0 <= points[i][1] <= 40000
All points are distinct.

*/
#define c11
#include"head.h"
class Solution {
	public:
		int minAreaRect(vector<vector<int>>& points) {
		unordered_map<int,unordered_set<int> > hash;
		for(int i=0;i<points.size();i++)
		{
					hash[points[i][0]].insert(points[i][1]);
		}
		int res=INT_MAX;
		for(int i=0;i<points.size();i++)
			for(int j=i+1;j<points.size();j++)
			{
				vector<int>  o=points[i];
				vector<int>  t=points[j];
				if(o[0]==t[0]||o[1]==t[1])
					continue;
				if(hash[o[0]].count(t[1]) && hash[t[0]].count(o[1]))
					res=min(res,abs(o[0]-t[0])*abs(o[1]-t[1]));
			}
			return res==INT_MAX?0:res;
		}
};
