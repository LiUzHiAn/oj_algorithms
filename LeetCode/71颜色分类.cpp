#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		/*设置两个变量r1,r2，含义是r1,左边(包含r1)的变量值都小于1，r2左边(包含r2)的变量值都小于2。
		那么初始时他俩都是-1(实际上是左边界-1)，代表他俩所包裹的范围是空。*/
		int r1=-1,r2=-1;
		for (int i=0;i<nums.size();i++)
		{
			if (nums[i] < 2)   
			{
				r2++;
				// 交换
				int temp= nums[i];
				nums[i]=nums[r2];
				nums[r2]=temp;

				if (nums[r2] < 1)
				{
					r1++;
					// 交换
					int temp = nums[r2];
					nums[r2] = nums[r1];
					nums[r1] = temp;
				}
			}

		}
	}
};

int main()
{
	Solution s;
	vector<int> v;
	v.push_back(2);
	v.push_back(0);
	v.push_back(2);
	v.push_back(1);
	v.push_back(1);
	v.push_back(0);

	s.sortColors(v);
	for (vector<int>::iterator it = v.begin();it!= v.end();it++)
	{
		cout<<*it<<" "; 
	}

	return 0;
}