/*
   There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

   After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

   When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

   For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

   You are given a string dominoes representing the initial state where:

   dominoes[i] = 'L', if the ith domino has been pushed to the left,
   dominoes[i] = 'R', if the ith domino has been pushed to the right, and
   dominoes[i] = '.', if the ith domino has not been pushed.

   Return a string representing the final state.



   Example 1:

Input: dominoes = "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.

Example 2:

Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."



Constraints:

n == dominoes.length
1 <= n <= 105
dominoes[i] is either 'L', 'R', or '.'.

*/
#include"head.h"
class Solution {
	public:
		string pushDominoes(string dominoes) {
		return simulation(dominoes);
		}
		string simulation(string dominoes) {
			int n=dominoes.size();
			vector<int> L(n,INT_MAX),R(n,INT_MAX);
			for(int i=0;i<n;i++)
			{
				if(dominoes[i]=='L')
				{
					L[i]=0;
					for(int j=i-1;j>=0&&dominoes[j]=='.';j--)
						L[j]=L[j+1]+1;
				}
				else if(dominoes[i]=='R')
				{
					R[i]=0;
					for(int j=i+1;j<n&&dominoes[j]=='.';j++)
						R[j]=R[j-1]+1;
				}
			}
			for(int i=0;i<n;i++)
				if(L[i]<R[i])
					dominoes[i]='L';
				else if(L[i]>R[i])
					dominoes[i]='R';
			return dominoes;
		}
};
