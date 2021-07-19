/*
   You are given two images img1 and img2 both of size n x n, represented as binary, square matrices of the same size. (A binary matrix has only 0s and 1s as values.)

   We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image. After, the overlap of this translation is the number of positions that have a 1 in both images.

   (Note also that a translation does not include any kind of rotation.)

   What is the largest possible overlap?



   Example 1:

Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
Output: 3
Explanation: We slide img1 to right by 1 unit and down by 1 unit.

The number of positions that have a 1 in both images is 3. (Shown in red)

Example 2:

Input: img1 = [[1]], img2 = [[1]]
Output: 1

Example 3:

Input: img1 = [[0]], img2 = [[0]]
Output: 0



Constraints:

n == img1.length
n == img1[i].length
n == img2.length
n == img2[i].length
1 <= n <= 30
img1[i][j] is 0 or 1.
img2[i][j] is 0 or 1.

*/
#define c11
#include"head.h"
class Solution {
	public:
		int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
			vector<int> la,lb;
			int n=img1.size();
			unordered_map<int,int> count;
			for(int i=0;i<n*n;i++)
				if(img1[i/n][i%n]==1)
					la.push_back(i/n*100+i%n);
			for(int i=0;i<n*n;i++)
				if(img2[i/n][i%n]==1)
					lb.push_back(i/n*100+i%n);
			for(int i=0;i<la.size();i++)
				for(int j=0;j<lb.size();j++)
					count[la[i]-lb[j]]++;
			int res=0;
			for(unordered_map<int,int>::iterator it=count.begin();it!=count.end();it++)
				res=max(res,it->second);
			return res;
		}
};
