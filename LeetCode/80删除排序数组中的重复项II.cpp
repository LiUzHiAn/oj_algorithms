#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if(nums.size()<=2)
			return nums.size();

		int left=1;
		int cnt=1;
		int right=1;
		while (right < nums.size())
		{
			if(nums[right]==nums[right-1])  // 如果和前一个数相等
			{
				if (cnt < 2)
				{
					nums[left]=nums[right];
					left++;
					cnt++;
				}
				right++;
			}
			else
			{

				nums[left] = nums[right];
				left++;
				cnt=1;
				right++;
			}
				
		}
		return left;
	}
};
int main()
{
	int a[]={1,1,1,2,2,3};
	Solution s;
	vector<int> v(a, a + 6);
	int rs=s.removeDuplicates(v);
	for (int i = 0;i < rs;i++)
	{
		cout<<v[i]<<" ";
	}
	return 0;
}