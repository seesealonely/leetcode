/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order. 
*/
/*
 For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5]. 
*/
#include"head.h"
class Solution {
public:
	void show(vector<int> res)
	{
	for(int i=0;i<res.size();++i)
	cout<<res[i]<<" ";
	cout<<endl;
	}
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
	vector<int> res;
 	if(matrix.size()==0) return res;       
	int rowBegin=0,rowEnd=matrix.size()-1,colBegin=0,colEnd=matrix[0].size()-1,i=0;
	while(rowBegin<=rowEnd&&colBegin<=colEnd)
	{
		for(i=colBegin;i<=colEnd;++i)
			res.push_back(matrix[rowBegin][i]);
		++rowBegin;
		for(i=rowBegin;i<=rowEnd;++i)
			res.push_back(matrix[i][colEnd]);
		--colEnd;
		for(i=colEnd;i>=colBegin;--i)
		 if (rowBegin <= rowEnd)
		res.push_back(matrix[rowEnd][i]);
		--rowEnd;
		if (colBegin <= colEnd)
		for(i=rowEnd;i>=rowBegin;--i)
		res.push_back(matrix[i][colBegin]);
		++colBegin;
	}
	return res;
    }
};
