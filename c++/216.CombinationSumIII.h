/*


Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]


Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]

*/

#include"head.h"

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
     vector<vector<int> > res;   
     vector<int> oneRes;   
	dfs(res,oneRes,k,n);
	return res;
    }
private:
void dfs(vector<vector<int> > &res,vector<int> oneRes,int k,int n)
{
	if(k==oneRes.size()||n==0) res.push_back(oneRes);
	if(k<oneRes.size())
	{
		for(int i=oneRes.size()?1:oneRes[oneRes.size()-1];i<9;++i)
		{
			if(n-i<0) break;
			oneRes.push_back(i);
			dfs(res,oneRes,k,n-i);
			oneRes.pop_back();
		}
	}
}
};
