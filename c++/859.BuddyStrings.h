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

#include"head.h"

class Solution {
public:
    bool buddyStrings(string A, string B) {
	return firstWay(A,B);
    }
	bool firstWay(string A,string B)
	{
 	if(A.size()!=B.size())
	return false;       
	int index1=-1,index2=-1,change=0;
	char tmp;
	vector<int> count(26,0);
	bool canChange=false;	
	for(int i=0;i<A.size();i++)
	{
		if(++count[A[i]-'a']>=2)
			canChange=true;
		if(A[i]!=B[i])
		{
		change++;
		if(index1==-1) index1=i;	
		else index2=i;
		}
	}
	if((canChange&&index1==-1&&index2==-1)||(change==2&&A[index1]==B[index2]&&A[index2]==B[index1])) return true;
	else return false;
	}
	bool secondWay(string A,string B)
	{
 	if(A.size()!=B.size())
	return false;       
	int index1=-1,index2=-1,change=0;
	bool canChange=false;	
	for(int i=0;i<A.size();i++)
	{
		if(++count[A[i]-'a']>=2)
			canChange=true;
		if(A[i]!=B[i])
		{
		change++;
		if(index1==-1) index1=i;	
		else index2=i;
		}
	}
	if(index1!=-1&&index2!=-1)
	{
	char tmp=A[index1];
	A[index1]=A[index2];
	A[index2]=tmp;
	}
	if((canChange&&index1==-1&&index2==-1)||(change==2&&A[index1]==B[index2]&&A[index2]==B[index1])) return true;
	else return false;
	}
};
