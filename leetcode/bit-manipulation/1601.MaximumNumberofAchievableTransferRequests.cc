/*
   We have n buildings numbered from 0 to n - 1. Each building has a number of employees. It's transfer season, and some employees want to change the building they reside in.

   You are given an array requests where requests[i] = [fromi, toi] represents an employee's request to transfer from building fromi to building toi.

   All buildings are full, so a list of requests is achievable only if for each building, the net change in employee transfers is zero. This means the number of employees leaving is equal to the number of employees moving in. For example if n = 3 and two employees are leaving building 0, one is leaving building 1, and one is leaving building 2, there should be two employees moving to building 0, one employee moving to building 1, and one employee moving to building 2.

   Return the maximum number of achievable requests.



   Example 1:

Input: n = 5, requests = [[0,1],[1,0],[0,1],[1,2],[2,0],[3,4]]
Output: 5
Explantion: Let's see the requests:
From building 0 we have employees x and y and both want to move to building 1.
From building 1 we have employees a and b and they want to move to buildings 2 and 0 respectively.
From building 2 we have employee z and they want to move to building 0.
From building 3 we have employee c and they want to move to building 4.
From building 4 we don't have any requests.
We can achieve the requests of users x and b by swapping their places.
We can achieve the requests of users y, a and z by swapping the places in the 3 buildings.

Example 2:

Input: n = 3, requests = [[0,0],[1,2],[2,1]]
Output: 3
Explantion: Let's see the requests:
From building 0 we have employee x and they want to stay in the same building 0.
From building 1 we have employee y and they want to move to building 2.
From building 2 we have employee z and they want to move to building 1.
We can achieve all the requests.

Example 3:

Input: n = 4, requests = [[0,3],[3,1],[1,2],[2,0]]
Output: 4



Constraints:

1 <= n <= 20
1 <= requests.length <= 16
requests[i].length == 2
0 <= fromi, toi < n

*/
#include"head.h"
class Solution {
	public:
		int maximumRequests(int n, vector<vector<int>>& requests) {
			return bitTravelOpt(n,requests);
			return bitTravel(n,requests);
		}
		int bitTravel(int n, vector<vector<int>>& requests) {
			int len=requests.size(),res=0;
			for(int i=0;i<(1<<len);i++)
				res=max(res,check(n,requests,i));
			return res;
		}
		int bitTravelOpt(int n, vector<vector<int>>& requests) {
			int res=0;
			vector<int> in(n,0),out(n,0); //in represnt indegree,out represent outdegree
			for(int i=0;i<requests.size();i++)
				if(requests[i][0]==requests[i][1])
					res++;
				else
					in[requests[i][1]]++,out[requests[i][0]]++;

			vector<vector<int>> newrequests;
			for(int k=0;k<requests.size();k++)
			{
				int i=requests[k][0],o=requests[k][1];
				if(i==o||!in[i]||!out[o]||!in[o]||!out[i])
					continue;
				newrequests.push_back(requests[k]);
			}

			int r=0,len=newrequests.size();
			for(int i=0;i<(1<<len);i++)
				r=max(r,check(n,newrequests,i));
			return res+r;
		}
		int check(int n,vector<vector<int>> &requests,int state)
		{
			vector<int> in(n,0),out(n,0); //in represnt indegree,out represent outdegree
			int start=0,res=0;
			while(state)
			{
				if(state&1)
				{
					in[requests[start][1]]++;
					out[requests[start][0]]++;
					res++;
				}
				state>>=1; start++;
			}
			if(in!=out)
				return -1;
			return res;
		}

};
int main() 
{
	Solution s;
	vector<vector<int> > v={{0,1},{1,0},{0,1},{1,2},{2,0},{3,4}};
	cout<<s.maximumRequests(5,v)<<endl;
	v.clear();v={{0,0},{1,2},{2,1}};
	cout<<s.maximumRequests(3,v)<<endl;
	v.clear();v={{0,3},{3,1},{1,2},{2,0}};
	cout<<s.maximumRequests(4,v)<<endl;
	return 0;
}
