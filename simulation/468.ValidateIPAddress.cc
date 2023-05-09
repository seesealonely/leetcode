/*
   Given a string queryIP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or "Neither" if IP is not a correct IP of any type.

   A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros. For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses while "192.168.01.1", "192.168.1.00", and "192.168@1.1" are invalid IPv4 addresses.

   A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:

   1 <= xi.length <= 4
   xi is a hexadecimal string which may contain digits, lowercase English letter ('a' to 'f') and upper-case English letters ('A' to 'F').
   Leading zeros are allowed in xi.

   For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.



   Example 1:

Input: queryIP = "172.16.254.1"
Output: "IPv4"
Explanation: This is a valid IPv4 address, return "IPv4".

Example 2:

Input: queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
Output: "IPv6"
Explanation: This is a valid IPv6 address, return "IPv6".

Example 3:

Input: queryIP = "256.256.256.256"
Output: "Neither"
Explanation: This is neither a IPv4 address nor a IPv6 address.



Constraints:

queryIP consists only of English letters, digits and the characters '.' and ':'.

*/


#include"head.h"
class Solution {
	public:
		string validIPAddress(string queryIP) {
		if(ipv4(queryIP)) return "IPv4";
		if(ipv6(queryIP)) return "IPv6";
		return "Neither";
		}
		bool ipv4(string add)
		{
			vector<string> ip;
			split(add,ip,'.');
			if(ip.size()!=4) return false;

			for(int i=0;i<ip.size();i++)
			{
				if(ip[i].size()==0||(ip[i].size()>1&&ip[i][0]=='0')||ip[i].size()>3) return false;

				for(int j=0;j<ip[i].size();j++)
					if(!isdigit(ip[i][j])) return false;

				int digit=stoi(ip[i]);
				if(digit<0||digit>255) return false;
			}
			return true;
		}
		bool ipv6(string add)
		{
			vector<string> ip;
			split(add,ip,':');
			if(ip.size()!=8) return false;

			for(int i=0;i<ip.size();i++)
			{
				if(ip[i].size()==0||ip[i].size()>4) return false;
				for(int j=0;j<ip[i].size();j++)
				{
					int c=ip[i][j];
					if(c<'0'||c>'9'&&c<'A'||c>'F'&&c<'a'||c>'f') return false;
				}
			}
			return true;
		}
		void split(string s,vector<string> &ip,char c)
		{
			stringstream ss(s);
			string cur;
			while(getline(ss,cur,c)) ip.push_back(cur);
			if(s.size()>0&&s.back()==c) ip.push_back({});
		}
};


int main() 
{
	Solution s;
	cout<<s.validIPAddress("172.16.254.1")<<endl;
	cout<<s.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334")<<endl;
	return 0;
}
