#include<iostream>
#include<string>
using  namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
 	int map[26]={0};
	for(int i=0;i<magazine.size();++i)
	++map[magazine[i]-'a'];
	for(int i=0;i<ransomNote.size();++i)
	if(--map[ransomNote[i]-'a']<0)
	return false;
	return true;
    }
};
