/*
   Design a HashSet without using any built-in hash table libraries.

   Implement MyHashSet class:

   void add(key) Inserts the value key into the HashSet.
   bool contains(key) Returns whether the value key exists in the HashSet or not.
   void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.

    

   Example 1:

   Input
   ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
   [[], [1], [2], [1], [3], [2], [2], [2], [2]]
   Output
   [null, null, null, true, false, null, true, null, false]

   Explanation
   MyHashSet myHashSet = new MyHashSet();
   myHashSet.add(1); // set = [1]
   myHashSet.add(2); // set = [1, 2]
   myHashSet.contains(1); // return True
   myHashSet.contains(3); // return False, (not found)
   myHashSet.add(2); // set = [1, 2]
   myHashSet.contains(2); // return True
   myHashSet.remove(2); // set = [1]
   myHashSet.contains(2); // return False, (already removed)

    

Constraints:

0 <= key <= 106
At most 104 calls will be made to add, remove, and contains.

*/


#include"head.h"
const int N=1e4+2;
class MyHashSet {
    public:
        MyHashSet() {

        }

        int find(const vector<int> &l,int val)
        {
            for(int i=0;i<l.size();i++)
                if(l[i]==val)
                    return i;

            return -1;
        }
        void add(int key) {
            int k=key%N;
            int i=find(link[k],key);

            if(i==-1)
            {
                link[k].push_back(key);
                cout<<key<<endl;
            }

        }

        void remove(int key) {
            int k=key%N;
            int i=find(link[k],key);

            if(i!=-1)
            {
                link[k].erase(link[k].begin()+i);
            cout<<link[k][i]<<endl;
            }

        }

        bool contains(int key) {
            int k=key%N;
            int i=find(link[k],key);

            cout<<(i!=-1)<<endl;
            return i!=-1;
        }
    private:
        vector<int> link[N];
};


int main() 
{
    MyHashSet s;
    s.add(1);
    s.add(2);
    s.contains(1);
    s.contains(3);
    s.add(2);
    s.contains(2);
    s.remove(2);
    s.contains(2);
    return 0;
}
