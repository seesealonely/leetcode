#include<iostream>
#include<vector>
using namespace std;
class Solution {
	public:
		void rotate(vector<int>& nums, int k) {
		int end=nums.size();
		reverse(nums,0,end-1);
		reverse(nums,0,k%end-1);
		reverse(nums,k%end,end-1);
		for(int i=0;i<end;i++)
		cout<<nums[i]<<" ";
		cout<<endl;
		}
	private:
	void reverse(vector<int> &nums,int begin,int end)
	{
		int temp;
		for(;begin<end;begin++,end--)
		{
			temp=nums[begin];
			nums[begin]=nums[end];
			nums[end]=temp;
		}
	}
};
