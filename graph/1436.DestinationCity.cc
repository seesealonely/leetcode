/*
   You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.

   It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.



   Example 1:

Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo"
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".

Example 2:

Input: paths = [["B","C"],["D","B"],["C","A"]]
Output: "A"
Explanation: All possible trips are:
"D" -> "B" -> "C" -> "A".
"B" -> "C" -> "A".
"C" -> "A".
"A".
Clearly the destination city is "A".

Example 3:

Input: paths = [["A","Z"]]
Output: "Z"



Constraints:

1 <= paths.length <= 100
paths[i].length == 2
1 <= cityAi.length, cityBi.length <= 10
cityAi != cityBi
All strings consist of lowercase and uppercase English letters and the space character.

*/

#define c11
#include"head.h"
class Solution {
    public:
        string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> in,out;
        for(int i=0;i<paths.size();i++)
            out[paths[i][0]]++,in[paths[i][1]]++;

        for(unordered_map<string,int>::iterator it=in.begin();it!=in.end();it++)
            if(it->second==1&&out[it->first]==0)
                return it->first;

        return "";
        }
};


int main() 
{
    Solution s;
    vector<vector<string>> v={{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}};
    cout<<s.destCity(v)<<endl;
    v.clear();v={{"B","C"},{"D","B"},{"C","A"}};
    cout<<s.destCity(v)<<endl;
    v.clear();v={{"A","Z"}};
    cout<<s.destCity(v)<<endl;
    return 0;
}
