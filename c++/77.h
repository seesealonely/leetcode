#include<iostream>
#include<vector>
using namespace std;
/*
   */
   void dfs(int begin,vector<int> &temp,vector<vector<int> > &res,int n,int k)
   {
   if(k==temp.size())
   {
   res.push_back(temp);
   return;
   }
   for(int i=begin;i<=n;i++)
   {
   temp.push_back(i);
   dfs(i+1,temp,res,n,k);
   temp.pop_back();
   }
   }
   class Solution {
   public:
   vector<vector<int> > combine(int n, int k)
   {
   vector<vector<int> > res;
   vector<int> temp;
   dfs(1,temp,res,n,k);
   return res;
   }
   };
