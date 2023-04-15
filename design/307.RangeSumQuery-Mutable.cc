/*
   Given an integer array nums, handle multiple queries of the following types:

   Update the value of an element in nums.
   Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.

   Implement the NumArray class:

   NumArray(int[] nums) Initializes the object with the integer array nums.
   void update(int index, int val) Updates the value of nums[index] to be val.
   int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).



   Example 1:

   Input
   ["NumArray", "sumRange", "update", "sumRange"]
   [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
   Output
   [null, 9, null, 8]

   Explanation
   NumArray numArray = new NumArray([1, 3, 5]);
   numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
   numArray.update(1, 2);   // nums = [1, 2, 5]
   numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8



Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
0 <= index < nums.length
-100 <= val <= 100
0 <= left <= right < nums.length
At most 3 * 104 calls will be made to update and sumRange.

*/


#include"head.h"
class NumArray {
	public:
		vector<int> t,sum,nums;
		int n;
		NumArray(const vector<int>& nums) {
		n=nums.size();
		this->nums=nums;
		sum=vector<int> (n+1,0);
		t=vector<int> (n+1,0);
		for(int i=0;i<n;i++)
			sum[i+1]=sum[i]+nums[i];
		}

		void update(int index, int val) {
		for(int i=index+1;i<=n;i+=i&-i)
			t[i]+=val-nums[index];

		nums[index]=val;
		}

		int prefixSum(int x)
		{
			int res=0;
			for(;x;x-=x&-x)
				res+=t[x];
			return res;
		}
		int sumRange(int left, int right) {
		return prefixSum(right+1)-prefixSum(left)+sum[right+1]-sum[left];		
		}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main() 
{
	vector<int> v={1,3,5};
	NumArray n(v);
	cout<<n.sumRange(0,2)<<endl;
	n.update(1,2);
	cout<<n.sumRange(0,2)<<endl;
	NumArray n1({-1});
	cout<<n.sumRange(0,0)<<endl;
	n.update(0,1);
	cout<<n.sumRange(0,0)<<endl;
	return 0;
}
