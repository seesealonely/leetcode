/*
Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

 

Example 1:

Input: A = "ab", B = "ba"
Output: true

Example 2:

Input: A = "ab", B = "ab"
Output: false

Example 3:

Input: A = "aa", B = "aa"
Output: true

Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true

Example 5:

Input: A = "", B = "aa"
Output: false

 

Note:

    0 <= A.length <= 20000
    0 <= B.length <= 20000
    A and B consist only of lowercase letters.

*/

#include"859.BuddyStrings.h"

int main()
{
	Solution s;	
	cout<<s.buddyStrings("ab","ba")<<endl;
	cout<<s.buddyStrings("ab","ab")<<endl;
	cout<<s.buddyStrings("aa","aa")<<endl;
	cout<<s.buddyStrings("","aa")<<endl;
	cout<<s.buddyStrings("aaaaaaabc","aaaaaaacb")<<endl;
	cout<<s.buddyStrings("abcd","badc")<<endl;
	return 0;
}
