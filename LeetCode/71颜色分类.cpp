#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		/*������������r1,r2��������r1,���(����r1)�ı���ֵ��С��1��r2���(����r2)�ı���ֵ��С��2��
		��ô��ʼʱ��������-1(ʵ��������߽�-1)�����������������ķ�Χ�ǿա�*/
		int r1=-1,r2=-1;
		for (int i=0;i<nums.size();i++)
		{
			if (nums[i] < 2)   
			{
				r2++;
				// ����
				int temp= nums[i];
				nums[i]=nums[r2];
				nums[r2]=temp;

				if (nums[r2] < 1)
				{
					r1++;
					// ����
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