/*
   You are given an array of strings products and a string searchWord.

   Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

   Return a list of lists of the suggested products after each character of searchWord is typed.



   Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
After typing mou, mous and mouse the system suggests ["mouse","mousepad"].

Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Explanation: The only word "havana" will be always suggested while typing the search word.



Constraints:

1 <= products.length <= 1000
1 <= products[i].length <= 3000
1 <= sum(products[i].length) <= 2 * 104
All the strings of products are unique.
products[i] consists of lowercase English letters.
1 <= searchWord.length <= 1000
searchWord consists of lowercase English letters.

*/


#include"head.h"
class Solution {
	public:
		vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
			const int p=products.size(),s=searchWord.size();

			sort(products.begin(),products.end());

			int l=0,r=p-1;

			vector<vector<string>>  res(s);
			for(int i=0;i<s;i++)
			{
				while(l<=r&&(products[l].size()<=i||products[l][i]!=searchWord[i]))
					l++;
				while(l<=r&&(products[r].size()<=i||products[r][i]!=searchWord[i]))
					r--;
				for(int j=l;j<=min(l+2,r);j++)
					res[i].push_back(products[j]);
			}
			return res;
		}
};


int main() 
{
	Solution s;
	vector<string> v={"mobile","mouse","moneypot","monitor","mousepad"};
	show(s.suggestedProducts(v,"mouse"));
	v.clear();v={"havana"};
	show(s.suggestedProducts(v,"havana"));
	v.clear();v={"bags","baggage","banner","box","cloths"};
	show(s.suggestedProducts(v,"bags"));
	return 0;
}
