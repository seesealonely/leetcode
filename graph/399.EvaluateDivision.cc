/*
   You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

   You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

   Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.



Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation:
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]

Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]

Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]



Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj consist of lower case English letters and digits.

*/

#define c11
#include"head.h"
class Solution {
	public:
		vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
			unordered_set<string> nums;
			unordered_map<string,unordered_map<string,double>> dis;

			for(int i=0;i<equations.size();i++)
			{
				string x=equations[i][0],y=equations[i][1];
				double val=values[i];
				dis[x][y]=val,dis[y][x]=1/val;
				nums.insert(x),nums.insert(y);
			}

			for(unordered_set<string>::iterator k=nums.begin();k!=nums.end();k++)
			for(unordered_set<string>::iterator i=nums.begin();i!=nums.end();i++)
			for(unordered_set<string>::iterator j=nums.begin();j!=nums.end();j++)
				if(dis[*i][*k]&&dis[*k][*j]) dis[*i][*j]=dis[*i][*k]*dis[*k][*j];

			vector<double> res;
			for(int i=0;i<queries.size();i++)
			{
				string x=queries[i][0],y=queries[i][1];
				res.push_back(dis[x][y]?dis[x][y]:-1);
			}

			return res;
		}
};


int main() 
{
	Solution s;
	vector<vector<string>> e={{"a","b"},{"b","c"}},q={{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
	vector<double> v={2.0,3.0};
	show(s.calcEquation(e,v,q));
	return 0;
}
