/*
   There are n mountains in a row, and each mountain has a height. You are given an integer array height where height[i] represents the height of mountain i, and an integer threshold.

   A mountain is called stable if the mountain just before it (if it exists) has a height strictly greater than threshold. Note that mountain 0 is not stable.

   Return an array containing the indices of all stable mountains in any order.



   Example 1:

Input: height = [1,2,3,4,5], threshold = 2

Output: [3,4]

Explanation:

Mountain 3 is stable because height[2] == 3 is greater than threshold == 2.
Mountain 4 is stable because height[3] == 4 is greater than threshold == 2.

Example 2:

Input: height = [10,1,10,1,10], threshold = 3

Output: [1,3]

Example 3:

Input: height = [10,1,10,1,10], threshold = 10

Output: []



Constraints:

2 <= n == height.length <= 100
1 <= height[i] <= 100
1 <= threshold <= 100

*/


#include"head.h"
class Solution {
	public:
		vector<int> stableMountains(vector<int>& height, int threshold) {
			vector<int> res;
			for(int i=0;i+1<height.size();i++)
				if(height[i]>threshold)
					res.push_back(i+1);
			return res;
		}
};


int main() 
{
	Solution s;
	vector<int>  height = {1,2,3,4,5};
	show(s.stableMountains(height,2));
	height.clear();height={10,1,10,1,10};
	show(s.stableMountains(height,3));
	show(s.stableMountains(height,10));
	return 0;
}
