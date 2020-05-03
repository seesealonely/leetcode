/*
   Given a string s, partition s such that every substring of the partition is a palindrome.

   Return all possible palindrome partitioning of s.

   For example, given s = "aab",
   Return

   [
   ["aa","b"],
   ["a","a","b"]
   ]
   */

#include"131.PalindromePartitioning.h"

int main()
{
	string ss("aaaab");
	Solution s;
	vector<vector<string> > res=s.partition(ss);
	s.show(res);
	return 0;
}
