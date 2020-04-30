/*
 Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

Example 1:

Input: 12
Output: 21

Example 2:

Input: 21
Output: -1

*/

#include"head.h"

class Solution {
public:
    int nextGreaterElement(int n) {
	char *s=(char*)malloc (30*sizeof(char));
	memset(s,'\0',30);
	sprintf(s,"%d",n);
	int len=strlen(s);	
	if(len==1) return -1;
	int decreasingNum=len-2;
	while(decreasingNum>=0&&s[decreasingNum]>=s[decreasingNum+1]) decreasingNum--;        
	if(decreasingNum==-1) return -1;
	reverseChar(s,decreasingNum+1,len-1);
	for(int bigger=decreasingNum+1;bigger<len;++bigger)
	if(s[bigger]>s[decreasingNum])
	{
		swap(s[decreasingNum],s[bigger]);
		break;
	}
	long res=atol(s);
	return res==n||res>INT_MAX?-1:res;
    }
void reverseChar(char *s,int begin,int end)
	{
	char temp;
	for(;begin<end;begin++,end--)
	{
	temp=s[begin];
		s[begin]=s[end];
		s[end]=temp;
}
}
};
