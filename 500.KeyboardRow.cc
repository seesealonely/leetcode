/*
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below. 
*/

#include"500.KeyboardRow.h"

int main()
{
	vector<string> v;
	v.push_back("Hello"); 
	v.push_back("Alaska"); 
	v.push_back("Dad"); 
	v.push_back("Peace"); 
	Solution s;
	s.show(s.findWords(v));
}
