/*
*/

#include"head.h"

class Solution {
public:
    vector<vector<int> > flipAndInvertImage(vector<vector<int> >& A) {
 	for(int i=0;i<A.size();i++)
		for(int j=0;j<A[i].size()/2;j++)
		swap(A,i,j);
 	for(int i=0;i<A.size();i++)
		for(int j=0;j<A[i].size();j++)
		A[i][j]=!A[i][j];
	return A;
    }
inline	void swap(vector<vector<int> > &v,int i,int  j)
	{
		int tmp=v[i][j];
		v[i][j]=v[i][v[i].size()-j-1];
		v[i][v.size()-j-1]=tmp;
	}
};
