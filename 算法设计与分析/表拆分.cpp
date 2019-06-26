#include<iostream>
using namespace std;

/*
* ����a�ֳ�b��c������b������ȫ����0��c������ȫС��0
*/
void partition(int a[],int n)
{
	int left=0;
	int right=n-1;  // ˫ָ��
	while(left!=right)
	{ 
		if (a[left] > 0 && a[right] > 0)
		{
			left++;  // ��ָ������
		}
		if (a[left] > 0 && a[right] < 0)
		{
			left++;  // ��ָ������
			right--; // ��ָ������
		}
		if (a[left] < 0 && a[right] > 0)
		{
			// �Ƚ���
			int temp=a[left];
			a[left]=a[right];
			a[right]=temp;
			// ָ���ƶ�
			left++;  // ��ָ������
			right--; // ��ָ������
		}
		if (a[left] < 0 && a[right] < 0)
		{
			right--; // ��ָ������
		}
	}
}

int main()
{
	int a[]={-1,1,3,-2,1,3,-2,5,5};
	partition(a,9);
	for (int i = 0;i < 9;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}