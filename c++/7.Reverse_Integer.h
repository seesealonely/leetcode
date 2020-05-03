#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
class Solution {
	public:
		int reverse(int x) {
			char s[15],tmp;
			long result=x;
			if(result<0)
			{
				memset(s,'\0',15);
				sprintf(s,"%ld",-result);
					for(int begin=0,end=strlen(s)-1;begin<end;++begin,--end)
					{
						tmp=s[begin];
						s[begin]=s[end];
						s[end]=tmp;
					}
			result=atol(s);	
			if(result>((1<<31)-1))
					return 0;
			else return -result;

			}
			else if(result>0)
			{
				memset(s,'\0',15);
				sprintf(s,"%ld",result);
					for(int begin=0,end=strlen(s)-1;begin<end;++begin,--end)
					{
						tmp=s[begin];
						s[begin]=s[end];
						s[end]=tmp;
					}
				result=atol(s);
			if(result>((1<<31)-1))
					return 0;
			else return result;
			}
			else return x;
		}
};
