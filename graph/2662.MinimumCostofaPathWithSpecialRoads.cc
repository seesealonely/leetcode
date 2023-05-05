/*
   You are given an array start where start = [startX, startY] represents your initial position (startX, startY) in a 2D space. You are also given the array target where target = [targetX, targetY] represents your target position (targetX, targetY).

   The cost of going from a position (x1, y1) to any other position in the space (x2, y2) is |x2 - x1| + |y2 - y1|.

   There are also some special roads. You are given a 2D array specialRoads where specialRoads[i] = [x1i, y1i, x2i, y2i, costi] indicates that the ith special road can take you from (x1i, y1i) to (x2i, y2i) with a cost equal to costi. You can use each special road any number of times.

   Return the minimum cost required to go from (startX, startY) to (targetX, targetY).



   Example 1:

Input: start = [1,1], target = [4,5], specialRoads = [[1,2,3,3,2],[3,4,4,5,1]]
Output: 5
Explanation: The optimal path from (1,1) to (4,5) is the following:
- (1,1) -> (1,2). This move has a cost of |1 - 1| + |2 - 1| = 1.
- (1,2) -> (3,3). This move uses the first special edge, the cost is 2.
- (3,3) -> (3,4). This move has a cost of |3 - 3| + |4 - 3| = 1.
- (3,4) -> (4,5). This move uses the second special edge, the cost is 1.
So the total cost is 1 + 2 + 1 + 1 = 5.
It can be shown that we cannot achieve a smaller total cost than 5.

Example 2:

Input: start = [3,2], target = [5,7], specialRoads = [[3,2,3,4,4],[3,3,5,5,5],[3,4,5,6,6]]
Output: 7
Explanation: It is optimal to not use any special edges and go directly from the starting to the ending position with a cost |5 - 3| + |7 - 2| = 7.



Constraints:

start.length == target.length == 2
1 <= startX <= targetX <= 105
1 <= startY <= targetY <= 105
1 <= specialRoads.length <= 200
specialRoads[i].length == 5
startX <= x1i, x2i <= targetX
startY <= y1i, y2i <= targetY
1 <= costi <= 105

*/


#include"head.h"
class Solution {
	public:
		static const int N=402;
		int w[N][N];
		int idx,x[N],y[N],begin,end;
		int dis[N];
		bool vis[N];
		string encode(const vector<int>&p)
		{
			return to_string(p[0])+"@"+to_string(p[1]);
		}
		int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
		memset(w,0x3f,sizeof(w));

		unordered_map<string,int> seen;

		specialRoads.push_back({start[0],start[1],target[0],target[1],INT_MAX});

		idx=0;
		for(int i=0;i<specialRoads.size();i++)
		{
			vector<int> s=specialRoads[i];
			string xx=encode({s[0],s[1]});
			string yy=encode({s[2],s[3]});
			if(seen.find(xx)==seen.end())
			{
				x[idx]=s[0],y[idx]=s[1];
				if(s[0]==start[0]&&s[1]==start[1]) begin=idx;
				if(s[0]==target[0]&&s[1]==target[1]) end=idx;
				seen[xx]=idx++;
			}

			if(seen.find(yy)==seen.end())
			{
				x[idx]=s[2],y[idx]=s[3];
				if(s[2]==start[0]&&s[3]==start[1]) begin=idx;
				if(s[2]==target[0]&&s[3]==target[1]) end=idx;
				seen[yy]=idx++;
			}

			int u=seen[xx],v=seen[yy];
			w[u][v]=min(w[u][v],s[4]);
		}

		for(int i=0;i<idx;i++)
			for(int j=0;j<idx;j++)
				w[i][j]=min(w[i][j],abs(x[i]-x[j])+abs(y[i]-y[j]));

		memset(dis,0x3f,sizeof(dis));
		memset(vis,false,sizeof(vis));
		dis[begin]=0;
		for(int j=0;j<idx;j++)
		{
			int mx=-1,mv=INT_MAX;
			for(int i=0;i<idx;i++)
				if(vis[i]==false&&mv>dis[i])
				{
					mv=dis[i];
					mx=i;
				}

			if(mx==-1)
				break;

			vis[mx]=true;
			for(int i=0;i<idx;i++)
				dis[i]=min(dis[i],dis[mx]+w[mx][i]);
		}

		return dis[end];
		}
};


int main() 
{
	Solution s;
	vector<int> st={1,1},t={4,5};
	vector<vector<int>> sp={{1,2,3,3,2},{3,4,4,5,1}};
	cout<<s.minimumCost(st,t,sp)<<endl;
	st.clear();st={3,2};
	t.clear();t={5,7};
	sp.clear();sp={{3,2,3,4,4},{3,3,5,5,5},{3,4,5,6,6}};
	cout<<s.minimumCost(st,t,sp)<<endl;
	return 0;
}
