/*
   You are given two string arrays creators and ids, and an integer array views, all of length n. The ith video on a platform was created by creator[i], has an id of ids[i], and has views[i] views.

   The popularity of a creator is the sum of the number of views on all of the creator's videos. Find the creator with the highest popularity and the id of their most viewed video.

   If multiple creators have the highest popularity, find all of them.
   If multiple videos have the highest view count for a creator, find the lexicographically smallest id.

   Return a 2D array of strings answer where answer[i] = [creatori, idi] means that creatori has the highest popularity and idi is the id of their most popular video. The answer can be returned in any order.



   Example 1:

Input: creators = ["alice","bob","alice","chris"], ids = ["one","two","three","four"], views = [5,10,5,4]
Output: [["alice","one"],["bob","two"]]
Explanation:
The popularity of alice is 5 + 5 = 10.
The popularity of bob is 10.
The popularity of chris is 4.
alice and bob are the most popular creators.
For bob, the video with the highest view count is "two".
For alice, the videos with the highest view count are "one" and "three". Since "one" is lexicographically smaller than "three", it is included in the answer.

Example 2:

Input: creators = ["alice","alice","alice"], ids = ["a","b","c"], views = [1,2,2]
Output: [["alice","b"]]
Explanation:
The videos with id "b" and "c" have the highest view count.
Since "b" is lexicographically smaller than "c", it is included in the answer.



Constraints:

n == creators.length == ids.length == views.length
1 <= n <= 105
1 <= creators[i].length, ids[i].length <= 5
creators[i] and ids[i] consist only of lowercase English letters.
0 <= views[i] <= 105

*/

#define c11
#include"head.h"
class Solution {
	public:
		vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
		typedef long long ll;
		class cr
		{
			public:
				string c,id;
				ll sum,max;
		};
		vector<vector<string>> res;
		unordered_map<string,cr> h;
		ll mx=0LL;
		for(int i=0;i<ids.size();i++)
		{
			if(h.count(creators[i])==0)
			{
				cr cur;
				cur.c=creators[i];
				cur.id=ids[i];
				cur.sum=cur.max=views[i];
				h[creators[i]]=cur;
				mx=max(mx,(ll)views[i]);
				continue;
			}
			
			h[creators[i]].c=creators[i];
			h[creators[i]].sum+=views[i];
			mx=max(mx,h[creators[i]].sum);
			if(h[creators[i]].max<views[i]||h[creators[i]].max==views[i]&&h[creators[i]].id>ids[i])
			{
				h[creators[i]].id=ids[i];
				h[creators[i]].max=views[i];
			}
		}

		for(unordered_map<string,cr>::iterator it=h.begin();it!=h.end();it++)
			if(it->second.sum==mx)
			{
				vector<string> cur;
				cur.push_back(it->first);
				cur.push_back(it->second.id);
				res.push_back(cur);
			}

		return res;
		}
};


int main() 
{
	Solution s;
	vector<string> c={"alice","bob","alice","chris"},ids={"one","two","three","four"};;
	vector<int> v={5,10,5,4};
	show(s.mostPopularCreator(c,ids,v));
	c.clear();c={"alice","alice","alice"};
	ids.clear();ids={"a","b","c"};
	v.clear();v={1,2,2};
	show(s.mostPopularCreator(c,ids,v));
	return 0;
}
