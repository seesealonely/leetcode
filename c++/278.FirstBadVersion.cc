/*
 You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API. 
*/

#include"278.FirstBadVersion.h"

int main()
{
	Solution s;
	cout<<s.firstBadVersion(1)<<endl;
	cout<<s.firstBadVersion(2)<<endl;
	cout<<s.firstBadVersion(3)<<endl;
	cout<<s.firstBadVersion(4)<<endl;
	cout<<s.firstBadVersion(5)<<endl;
	cout<<s.firstBadVersion(6)<<endl;
	cout<<s.firstBadVersion(7)<<endl;
	cout<<s.firstBadVersion(8)<<endl;
	return 0;
}
