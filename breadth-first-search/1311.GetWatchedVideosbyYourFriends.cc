/*
   There are n people, each person has a unique id between 0 and n-1. Given the arrays watchedVideos and friends, where watchedVideos[i] and friends[i] contain the list of watched videos and the list of friends respectively for the person with id = i.

   Level 1 of videos are all watched videos by your friends, level 2 of videos are all watched videos by the friends of your friends and so on. In general, the level k of videos are all watched videos by people with the shortest path exactly equal to k with you. Given your id and the level of videos, return the list of videos ordered by their frequencies (increasing). For videos with the same frequency order them alphabetically from least to greatest.



   Example 1:

Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 1
Output: ["B","C"]
Explanation:
You have id = 0 (green color in the figure) and your friends are (yellow color in the figure):
Person with id = 1 -> watchedVideos = ["C"]
Person with id = 2 -> watchedVideos = ["B","C"]
The frequencies of watchedVideos by your friends are:
B -> 1
C -> 2

Example 2:

Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 2
Output: ["D"]
Explanation:
You have id = 0 (green color in the figure) and the only friend of your friends is the person with id = 3 (yellow color in the figure).



Constraints:

n == watchedVideos.length == friends.length
2 <= n <= 100
1 <= watchedVideos[i].length <= 100
1 <= watchedVideos[i][j].length <= 8
0 <= friends[i].length < n
0 <= friends[i][j] < n
0 <= id < n
1 <= level < n
if friends[i] contains j, then friends[j] contains i

*/

#define c11
#include"head.h"
class Solution {
	public:
		vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
			const int n=watchedVideos.size();
			unordered_map<string,int> cnt;

			vector<int> dis(n,INT_MAX);
			dis[id]=0;
			queue<int> q;
			q.push(id);

			while(!q.empty())
			{
				int x=q.front();
				q.pop();

				if(dis[x]==level)
				{
					for(int i=0;i<watchedVideos[x].size();i++)
						cnt[watchedVideos[x][i]]++;
					continue;
				}

				for(int i=0;i<friends[x].size();i++)
					if(dis[friends[x][i]]>dis[x]+1)
					{
						dis[friends[x][i]]=dis[x]+1;
						q.push(friends[x][i]);
					}
			}

			vector<pair<int,string>> p;
			for(unordered_map<string,int>::iterator it=cnt.begin();it!=cnt.end();it++)
				p.push_back({it->second,it->first});

			sort(p.begin(),p.end());

			vector<string> res;
			for(int i=0;i<p.size();i++)
				res.push_back(p[i].second);

			return res;
		}
};


int main() 
{
	Solution s;
	vector<vector<string>> w={{"A","B"},{"C"},{"B","C"},{"D"}};
	vector<vector<int>> f={{1,2},{0,3},{0,3},{1,2}};
	show(s.watchedVideosByFriends(w,f,0,1));
	show(s.watchedVideosByFriends(w,f,0,2));
	return 0;
}
