/*
   Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

   Integers in each row are sorted in ascending from left to right.
   Integers in each column are sorted in ascending from top to bottom.

   For example,

   Consider the following matrix:

   [
   [1,   4,  7, 11, 15],
   [2,   5,  8, 12, 19],
   [3,   6,  9, 16, 22],
   [10, 13, 14, 17, 24],
   [18, 21, 23, 26, 30]
   ]

   Given target = 5, return true.

   Given target = 20, return false.
   */

#include"240.Searcha2DMatrixII.h"

int main()
{
	int vv1[]={1,   4,  7, 11, 15};	
	vector<int> v1(vv1,vv1+5);
	int vv2[]={2,   5,  8, 12, 19 };
	vector<int> v2(vv2,vv2+5);
	int vv3[]={3,   6,  9, 16, 22};
	vector<int> v3(vv3,vv3+5);
	int vv4[]={10, 13, 14, 17, 24};
	vector<int> v4(vv4,vv4+5);
	int vv5[]={18, 21, 23, 26, 30};
	vector<int> v5(vv5,vv5+5);
	vector<vector<int> >v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);
	Solution s;
	cout<<s.searchMatrix(v,10)<<endl;
	cout<<s.searchMatrix(v,20)<<endl;
	cout<<s.searchMatrix(v,5)<<endl;
	cout<<s.searchMatrix(v,2000)<<endl;
	return 0;
}
