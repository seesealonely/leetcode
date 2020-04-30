/*
*/

#include"head.h"

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
	string mos[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};        
	map<string,int> m;
	string one;
	for(int i=0;i<words.size();i++)
	{
		for(int j=0;j<words[i].size();j++)
		one+=mos[words[i][j]-'a'];	
		m[one]++;
		one.clear();	
	}
	return m.size();
    }
};
