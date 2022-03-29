/*
   You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.

   Given the string command, return the Goal Parser's interpretation of command.



   Example 1:

Input: command = "G()(al)"
Output: "Goal"
Explanation: The Goal Parser interprets the command as follows:
G -> G
() -> o
(al) -> al
The final concatenated result is "Goal".

Example 2:

Input: command = "G()()()()(al)"
Output: "Gooooal"

Example 3:

Input: command = "(al)G(al)()()G"
Output: "alGalooG"



Constraints:

1 <= command.length <= 100
command consists of "G", "()", and/or "(al)" in some order.

*/


#include"head.h"
class Solution {
    public:
        string interpret(string command) {
            string res;
            for(int i=0;i<command.size();i++)
            {
                if(command[i]=='G')
                    res+="G";
                else if(i+1<command.size()&&command[i]=='('&&command[i+1]==')')
                    res+="o";
                else if(i+3<command.size()&&command[i]=='('&&command[i+1]=='a'&&command[i+2]=='l'&&command[i+3]==')')
                    res+="al";
            }
            return res;
        }
};


int main() 
{
    Solution s;
    cout<<s.interpret("G()(al)")<<endl;
    cout<<s.interpret("G()()()()(al)")<<endl;
    cout<<s.interpret("(al)G(al)()()G")<<endl;
    return 0;
}
