
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (!n)
			return;
		if (!m)
			nums1 = nums2;
		int i = m - 1, j = n - 1, k = m + n - 1;  // 从后往前遍历
		while (i >= 0 && j >= 0)
		{
			if (nums1[i]<nums2[j])
				nums1[k--] = nums2[j--];
			else
				nums1[k--] = nums1[i--];
		}
		while (i >= 0)
			nums1[k--] = nums1[i--];
		while (j >= 0)
			nums1[k--] = nums2[j--];
	}
};
int main()
{
	
	Solution s;
	vector<int> numm1,numm2;
	numm1.push_back(1);
	numm1.push_back(2);
	numm1.push_back(4);
	numm1.push_back(5);
	numm1.push_back(6);
	numm1.push_back(0);

	numm2.push_back(3);
	
	s.merge(numm1,5,numm2,1);

	for (int i = 0;i < 6;i++)
	{
		cout << numm1[i] << " ";
	}
	return 0;
}