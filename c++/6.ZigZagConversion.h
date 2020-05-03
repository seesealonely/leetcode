/*
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
*/

#include"head.h"

class Solution {
public:
    string convert(string s, int numRows) {
	if(numRows<=1) return s;
	string *line=new string[numRows];        
	int index=0,step=1,len=s.size();
	for(int i=0;i<len;++i)
	{
		line[index].push_back(s[i]);
		if(index==0)
		step=1;
		else if(index==numRows-1)
		step=-1;
		index+=step;
	}
	string res;
	for(int i=0;i<numRows;++i) res+=line[i];
	return res;
    }
};
