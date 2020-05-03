/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

*/
#include"120.Triangle.h"
int main()
{
	vector<vector<int> > t;
	vector<int> sub;
	sub.push_back(2);
	t.push_back(sub);
	sub.clear();
	sub.push_back(3);
	sub.push_back(4);
	t.push_back(sub);
	sub.clear();
	sub.push_back(6);
	sub.push_back(5);
	sub.push_back(7);
	t.push_back(sub);
	sub.clear();
	sub.push_back(4);
	sub.push_back(1);
	sub.push_back(8);
	sub.push_back(3);
	t.push_back(sub);
	Solution s;
	cout<<s.minimumTotal(t)<<endl;
	return 0;
}
