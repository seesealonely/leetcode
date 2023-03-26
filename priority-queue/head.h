#ifndef _HEAD
#define _HEAD
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<utility>
#include<algorithm>
#include<numeric>
#include<cctype>
#include<climits>
#include<cmath>
#include<sstream>
#include<stack>
#include<set>
#include<queue>
#ifdef c11 
#define c11
#include<unordered_set>
#include<unordered_map>
#endif
using namespace std;
typedef long long ll;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 // Definition for binary tree with next pointer.
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };
ListNode *buildList();
ListNode *buildList(bool in);
TreeNode *buildTree();
void  show(TreeNode *root);
void show(vector<TreeNode *> res);
void show(ListNode *head);
void show(vector<bool> v);
void show(vector<int> v);
void show(vector<double> v);
void show(vector<ll> v);
void show(vector<vector<ll>>  v);
void show(vector<string> v);
void show(vector<vector<string> > v);
void show(vector<vector<int> > v);
TreeLinkNode *buildTree(bool i);
void  show(TreeLinkNode *root);
void show(vector<char> s);
#endif
