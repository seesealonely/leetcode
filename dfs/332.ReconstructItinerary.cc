/*
   You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

   All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

   For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].

   You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.



   Example 1:

Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]

Example 2:

Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.



Constraints:

1 <= tickets.length <= 300
tickets[i].length == 2
fromi.length == 3
toi.length == 3
fromi and toi consist of uppercase English letters.
fromi != toi

*/

#define c11
#include"head.h"
class Solution {
	public:
		unordered_map<string,multiset<string>> g;
		vector<string> res;
		vector<string> findItinerary(vector<vector<string>>& tickets) {
		for(int i=0;i<tickets.size();i++)
			g[tickets[i][0]].insert(tickets[i][1]);

		dfs("JFK");

		return vector<string> (res.rbegin(),res.rend());

		}
		void dfs(string cur)
		{
			while(g[cur].size())
			{
				string next=*g[cur].begin();
				g[cur].erase(g[cur].begin());
				dfs(next);
			}
			res.push_back(cur);
		}
};


int main() 
{
	Solution s;
	vector<vector<string>>  tickets = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
	show(s.findItinerary(tickets));
	tickets.clear();tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
	show(s.findItinerary(tickets));
	return 0;
}
