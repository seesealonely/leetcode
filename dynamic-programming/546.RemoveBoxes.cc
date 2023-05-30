/*
   You are given several boxes with different colors represented by different positive numbers.

   You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (i.e., composed of k boxes, k >= 1), remove them and get k * k points.

   Return the maximum points you can get.



   Example 1:

Input: boxes = [1,3,2,2,2,3,4,3,1]
Output: 23
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
----> [1, 3, 3, 3, 1] (1*1=1 points) 
----> [1, 1] (3*3=9 points) 
----> [] (2*2=4 points)

Example 2:

Input: boxes = [1,1,1]
Output: 9

Example 3:

Input: boxes = [1]
Output: 1



Constraints:

1 <= boxes.length <= 100
1 <= boxes[i] <= 100

*/


#include"head.h"
class Solution {
	public:
		int removeBoxes(vector<int>& boxes) {
		const int MIN=-1e5;
		int n=boxes.size();

		vector<vector<vector<int>>> f(n,vector<vector<int>>(n,vector<int>(n+1,MIN)));
		vector<vector<int>> g(n,vector<int>(n,MIN));

		for(int i=0;i<n;i++)
		{
			f[i][i][1]=1;
			g[i][i]=1;
			if(i>0) g[i][i-1]=0;
		}

		for(int len=2;len<=n;len++)
			for(int i=0;i<n-len+1;i++)
			{
				int j=i+len-1;
				f[i][j][1]=g[i+1][j]+1;

				for(int e=i+1;e<=j;e++)
					if(boxes[i]==boxes[e])
						for(int k=2;k<=len;k++)
							f[i][j][k]=max(f[i][j][k],
									g[i+1][e-1]+f[e][j][k-1]-(k-1)*(k-1)+k*k);
				g[i][j]=max(g[i][j],*max_element(f[i][j].begin(),f[i][j].end()));
			}

		return g[0][n-1];
		}
};


int main() 
{
	Solution s;
	vector<int> boxes = {1,3,2,2,2,3,4,3,1};
	cout<<s.removeBoxes(boxes)<<endl;
	boxes.clear();boxes={1,1,1};
	cout<<s.removeBoxes(boxes)<<endl;
	boxes.clear();boxes={1};
	cout<<s.removeBoxes(boxes)<<endl;
	return 0;
}
