/*
   Your music player contains N different songs and she wants to listen to L (not necessarily different) songs during your trip.  You create a playlist so that:

   Every song is played at least once
   A song can only be played again only if K other songs have been played

   Return the number of possible playlists.  As the answer can be very large, return it modulo 10^9 + 7.



   Example 1:

Input: N = 3, L = 3, K = 1
Output: 6
Explanation: There are 6 possible playlists. [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1].

Example 2:

Input: N = 2, L = 3, K = 0
Output: 6
Explanation: There are 6 possible playlists. [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2, 1], [2, 1, 2], [1, 2, 2]

Example 3:

Input: N = 2, L = 3, K = 1
Output: 2
Explanation: There are 2 possible playlists. [1, 2, 1], [2, 1, 2]



Note:

0 <= K < N <= L <= 100

*/

#include"head.h"

class Solution {
	public:
		int numMusicPlaylists(int N, int L, int K) {
			long mod=1e9+7;        
			vector<vector<long> > dp(L+1,vector<long> (N+1,0));
			dp[0][0]=1;
			for(int i=1;i<=L;i++)
				for(int j=1;j<=N;j++)
					dp[i][j]=(dp[i-1][j]*max(0,(j-K))+dp[i-1][j-1]*(N-(j-1)))%mod;
			return(int) dp[L][N];
		}
};
