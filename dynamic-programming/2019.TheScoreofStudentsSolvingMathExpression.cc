/*
   You are given a string s that contains digits 0-9, addition symbols '+', and multiplication symbols '*' only, representing a valid math expression of single digit numbers (e.g., 3+5*2). This expression was given to n elementary school students. The students were instructed to get the answer of the expression by following this order of operations:

   Compute multiplication, reading from left to right; Then,
   Compute addition, reading from left to right.

   You are given an integer array answers of length n, which are the submitted answers of the students in no particular order. You are asked to grade the answers, by following these rules:

   If an answer equals the correct answer of the expression, this student will be rewarded 5 points;
   Otherwise, if the answer could be interpreted as if the student applied the operators in the wrong order but had correct arithmetic, this student will be rewarded 2 points;
   Otherwise, this student will be rewarded 0 points.

   Return the sum of the points of the students.



   Example 1:

Input: s = "7+3*1*2", answers = [20,13,42]
Output: 7
Explanation: As illustrated above, the correct answer of the expression is 13, therefore one student is rewarded 5 points: [20,13,42]
A student might have applied the operators in this wrong order: ((7+3)*1)*2 = 20. Therefore one student is rewarded 2 points: [20,13,42]
The points for the students are: [2,5,0]. The sum of the points is 2+5+0=7.

Example 2:

Input: s = "3+5*2", answers = [13,0,10,13,13,16,16]
Output: 19
Explanation: The correct answer of the expression is 13, therefore three students are rewarded 5 points each: [13,0,10,13,13,16,16]
A student might have applied the operators in this wrong order: ((3+5)*2 = 16. Therefore two students are rewarded 2 points: [13,0,10,13,13,16,16]
The points for the students are: [5,0,0,5,5,2,2]. The sum of the points is 5+0+0+5+5+2+2=19.

Example 3:

Input: s = "6+0*1", answers = [12,9,6,4,8,6]
Output: 10
Explanation: The correct answer of the expression is 6.
If a student had incorrectly done (6+0)*1, the answer would also be 6.
By the rules of grading, the students will still be rewarded 5 points (as they got the correct answer), not 2 points.
The points for the students are: [0,0,5,0,0,5]. The sum of the points is 10.



Constraints:

3 <= s.length <= 31
s represents a valid expression that contains only digits 0-9, '+', and '*' only.
All the integer operands in the expression are in the inclusive range [0, 9].
1 <= The count of all operators ('+' and '*') in the math expression <= 15
Test data are generated such that the correct answer of the expression is in the range of [0, 1000].
n == answers.length
1 <= n <= 104
0 <= answers[i] <= 1000

*/

#define c11
#include"head.h"
class Solution {
	public:
		static const int N=17;
		vector<int> dp[N][N];
		int calc(const string &s)
		{
			stack<int> st;
			st.push(s[0]-'0');

			for(int i=1;i<s.size();i+=2)
				if(s[i]=='+') st.push(s[i+1]-'0');
				else st.top()*=s[i+1]-'0';

			int res=0;
			while(!st.empty())
			{
				res+=st.top();
				st.pop();
			}
			return res;
		}
		int scoreOfStudents(string s, vector<int>& answers) {
		int cal=calc(s);
		vector<int> nums;
		vector<char> ops;

		for(int i=0;i<s.size();i++)
			if(isdigit(s[i])) nums.push_back(s[i]-'0');
			else ops.push_back(s[i]);

		const int n=nums.size();
		for(int i=0;i<n;i++)
			dp[i][i].push_back(nums[i]);

		for(int len=2;len<=n;len++)
			for(int i=0;i<n-len+1;i++)
			{
				int j=i+len-1;
				for(int k=i;k<j;k++)
					for(int p=0;p<dp[i][k].size();p++)
						for(int q=0;q<dp[k+1][j].size();q++)
						{
							int t=ops[k]=='+'?dp[i][k][p]+dp[k+1][j][q]:dp[i][k][p]*dp[k+1][j][q];
							if(t>1000)
								break;
							dp[i][j].push_back(t);
						}
				sort(dp[i][j].begin(),dp[i][j].end());
				dp[i][j].resize(unique(dp[i][j].begin(),dp[i][j].end())-dp[i][j].begin());
			}
		unordered_set<int> p(dp[0][n-1].begin(),dp[0][n-1].end());
		int res=0;
		for(int i=0;i<answers.size();i++)
			if(answers[i]==cal) res+=5;
			else if(p.find(answers[i])!=p.end()) res+=2;
		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> answers={20,13,42};
	cout<<s.scoreOfStudents("7+3*1*2",answers)<<endl;
	answers.clear();answers={13,0,10,13,13,16,16};
	cout<<s.scoreOfStudents("3+5*2",answers)<<endl;
	answers.clear();answers={12,9,6,4,8,6};
	cout<<s.scoreOfStudents("6+0*1",answers)<<endl;
	return 0;
}
