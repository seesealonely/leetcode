#include<iostream>
#include<string>
using namespace std;
class Solution {
	public:
		bool isPalindrome(string s) {
			for(int begin=0,end=s.size()-1;begin<end;begin++,end--)
			{
				while(!isalnum(s[begin])&&begin<end) 
				begin++;
				while(!isalnum(s[end])&&begin<end) 
				end--;
				if(toupper(s[begin])!=toupper(s[end])) 
				return false;
			}       
			return true;
		}
};
