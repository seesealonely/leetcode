/*
   Alice is texting Bob using her phone. The mapping of digits to letters is shown in the figure below.

   In order to add a letter, Alice has to press the key of the corresponding digit i times, where i is the position of the letter in the key.

   For example, to add the letter 's', Alice has to press '7' four times. Similarly, to add the letter 'k', Alice has to press '5' twice.
   Note that the digits '0' and '1' do not map to any letters, so Alice does not use them.

   However, due to an error in transmission, Bob did not receive Alice's text message but received a string of pressed keys instead.

   For example, when Alice sent the message "bob", Bob received the string "2266622".

   Given a string pressedKeys representing the string received by Bob, return the total number of possible text messages Alice could have sent.

   Since the answer may be very large, return it modulo 109 + 7.



   Example 1:

Input: pressedKeys = "22233"
Output: 8
Explanation:
The possible text messages Alice could have sent are:
"aaadd", "abdd", "badd", "cdd", "aaae", "abe", "bae", and "ce".
Since there are 8 possible messages, we return 8.

Example 2:

Input: pressedKeys = "222222222222222222222222222222222222"
Output: 82876089
Explanation:
There are 2082876103 possible text messages Alice could have sent.
Since we need to return the answer modulo 109 + 7, we return 2082876103 % (109 + 7) = 82876089.



Constraints:

1 <= pressedKeys.length <= 105
pressedKeys only consists of digits from '2' - '9'.

*/


#include"head.h"
class Solution {
    public:
        int countTexts(string pressedKeys) {
            const int n=pressedKeys.size(),mod=1e9+7;
            vector<int> dp(n+1,0);
            dp[0]=1;
            for(int i=1;i<=n;i++)
            {
                dp[i]=dp[i-1];
                char c=pressedKeys[i-1];
                int step=0;
                if(c=='7'||c=='9')
                    step=3;
                else
                    step=2;
                for(int j=2;i-j>=0&&step--&&pressedKeys[i-j]==c;j++)
                    dp[i]=(dp[i]+dp[i-j])%mod;
            }
        return dp[n];
        }
};


int main() 
{
    Solution s;
    cout<<s.countTexts("22233")<<endl;
    cout<<s.countTexts("222222222222222222222222222222222222")<<endl;
    cout<<s.countTexts("344644885")<<endl;
    return 0;
}
