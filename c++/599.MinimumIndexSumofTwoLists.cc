/*
 Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

Example 1:

Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".

Example 2:

Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).

Note:

    The length of both lists will be in the range of [1, 1000].
    The length of strings in both lists will be in the range of [1, 30].
    The index is starting from 0 to the list length minus 1.
    No duplicates in both lists.

*/
#include"599.MinimumIndexSumofTwoLists.h"
int main()
{
	vector<string> l1,l2;
	l1.push_back("Shogun");
	l1.push_back("Tapioca Express");
	l1.push_back("Burger King");
	l1.push_back("KFC");
	l2.push_back("Piatti");
	l2.push_back("The Grill at Torrey Pines");
	l2.push_back("Hungry Hunter Steakhouse");
	l2.push_back("Shogun");
	Solution s;
	show(s.findRestaurant(l1,l2));
	return 0;
}
