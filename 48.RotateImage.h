#include<iostream>
#include<vector>
using namespace std;
class Solution
{
	public:
		void rotate(vector<vector<int> >& matrix) 
		{
			int temp=0;
			for(int i=0;i<matrix.size();++i)
				for(int j=i;j<matrix[0].size();++j)
				{
					temp=matrix[i][j];
					matrix[i][j]=matrix[j][i];
					matrix[j][i]=temp;
				}       
			for(int i=0;i<matrix.size();++i)
				for(int j=0;j<matrix.size()/2;++j)
				{
					temp=matrix[i][j];
					matrix[i][j]=matrix[i][matrix.size()-j-1];
					matrix[i][matrix.size()-j-1]=temp;
				}       
		}
		void show(vector<vector<int> >& matrix) 
		{
			cout<<"############################"<<endl;
			for(int i=0;i<3;++i)
			{
				for(int j=0;j<3;++j)
					cout<<matrix[i][j]<<" ";
				cout<<endl;
			}
			cout<<"############################"<<endl;
		}
};
