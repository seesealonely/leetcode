#include<iostream>
#include<vector>
using namespace std;
class Solution {
	public:
		bool searchMatrix(vector<vector<int> >& matrix, int target) {
			int row=matrix.size();       
			int col=matrix[0].size();
			for(int begin=0,end=row*col-1;begin<=end;)
			{
			int mid=(begin+end)>>1;
			if(matrix[mid/col][mid%col]>target) end=mid-1;
			else if(matrix[mid/col][mid%col]<target)begin=mid+1;
			else return true;
			} 
			return false;
		}
};
