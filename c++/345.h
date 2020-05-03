#include<iostream>
#include<string>
using namespace std;
bool isvowels(char c)
{
	if(c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='u'||c=='U'||c=='o'||c=='O')
		return false;
	else return true;
}
class Solution {
	public:
		string reverseVowels(string s) {
			char tmp;
			for(int begin=0,end=(s.size()-1);begin<end;begin++,end--)
			{
				while(isvowels(s[begin])&&(begin<end)) begin++;
				while(isvowels(s[end])&&(begin<end)) end--;
				tmp=s[begin];
				s[begin]=s[end];
				s[end]=tmp;
			}
			return s;
		}
};
