/*
   Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.



   Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.

Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.

Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.



Constraints:

n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] is either '0' or '1'.
All the strings of nums are unique.

*/
#include"head.h"
class Solution {
	public:
		string findDifferentBinaryString(vector<string>& nums) {
			set<string> s(nums.begin(),nums.end());
			const int n=nums[0].size();
			string res(n,'0');
			for(set<string>::iterator it=s.begin();it!=s.end();it++)
				if(*it==res)
					res=addOne(res,n);
				else
					break;
			return res;
		}
		string addOne(string &s,const int n)
		{
			int i=n-1;
			for(;i>=0;i--)
				if(s[i]=='0')
					break;
			return s.substr(0,i)+'1'+string(n-i-1,'0');
		}
};
int main() 
{
	Solution s;
	vector<string> v={"01","10"};
	cout<<s.findDifferentBinaryString(v)<<endl;
	v.clear();v={"00","01"};
	cout<<s.findDifferentBinaryString(v)<<endl;
	v.clear();v={"111","011","001"};
	cout<<s.findDifferentBinaryString(v)<<endl;
	return 0;
}
