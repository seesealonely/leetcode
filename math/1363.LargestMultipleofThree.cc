/*
   Given an array of digits digits, return the largest multiple of three that can be formed by concatenating some of the given digits in any order. If there is no answer return an empty string.

   Since the answer may not fit in an integer data type, return the answer as a string. Note that the returning answer must not contain unnecessary leading zeros.



   Example 1:

Input: digits = [8,1,9]
Output: "981"

Example 2:

Input: digits = [8,6,7,1,0]
Output: "8760"

Example 3:

Input: digits = [1]
Output: ""



Constraints:

1 <= digits.length <= 104
0 <= digits[i] <= 9

*/


#include"head.h"
class Solution {
	public:
		string largestMultipleOfThree(vector<int>& digits) {
			int one1=10,one2=10,two1=10,two2=0,n=digits.size(),sum=0;
			sort(digits.begin(),digits.end());

			for(int i=0;i<n;i++)
			{
				int x=digits[i];
				sum+=x;
				if(x%3==1)
				{
					if(one1>x)
						one2=one1,one1=x;
					else if(one2>x)
						one2=x;
				}
				else if(x%3==2)
				{
					if(two1>x)
						two2=two1,two1=x;
					else if(two2>x)
						two2=x;
				}
			}
			string res;
			if(sum%3==0)
			{
				for(int i=0;i<n;i++)
					res+=to_string(digits[i]);
			}
			else if(sum%3==1)
			{
				if(one1<10)
				{
					for(int i=0;i<n;i++)
					{
						if(digits[i]==one1)
						{
							one1=10;
							continue;
						}
						res+=to_string(digits[i]);
					}
				}
				else if(two1<10&&two2<10)
				{
					for(int i=0;i<n;i++)
					{
						if(digits[i]==two1)
						{
							two1=10;
							continue;
						}
						else if(digits[i]==two2)
						{
							two2=10;
							continue;
						}
						res+=to_string(digits[i]);
					}
				}	
			}
			else
			{
				if(two1<10)
				{
					for(int i=0;i<n;i++)
					{
						if(digits[i]==two1)
						{
							two1=10;
							continue;
						}
						res+=to_string(digits[i]);
					}
				}
				else if(one1<10&&one2<10)
				{
					for(int i=0;i<n;i++)
					{
						if(digits[i]==one1)
						{
							one1=10;
							continue;
						}
						else if(digits[i]==one2)
						{
							one2=10;
							continue;
						}
						res+=to_string(digits[i]);
					}
				}
			}

			while(res.size()>1&&res.back()=='0')
				res.pop_back();
			reverse(res.begin(),res.end());

			return res;
		}
};


int main() 
{
	Solution s;
	vector<int> v={8,1,9};
	cout<<s.largestMultipleOfThree(v)<<endl;
	v.clear();v={8,6,7,1,0};
	cout<<s.largestMultipleOfThree(v)<<endl;
	v.clear();v={1};
	cout<<s.largestMultipleOfThree(v)<<endl;
	v.clear();v={0,0,0,0,0,0};
	cout<<s.largestMultipleOfThree(v)<<endl;
	return 0;
}
