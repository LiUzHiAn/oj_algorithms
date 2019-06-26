#include<iostream>
using namespace std;

/*
* 将表a分成b、c两个表，b中内容全大于0，c中内容全小于0
*/
void partition(int a[],int n)
{
	int left=0;
	int right=n-1;  // 双指针
	while(left!=right)
	{ 
		if (a[left] > 0 && a[right] > 0)
		{
			left++;  // 左指针右移
		}
		if (a[left] > 0 && a[right] < 0)
		{
			left++;  // 左指针右移
			right--; // 右指针左移
		}
		if (a[left] < 0 && a[right] > 0)
		{
			// 先交换
			int temp=a[left];
			a[left]=a[right];
			a[right]=temp;
			// 指针移动
			left++;  // 左指针右移
			right--; // 右指针左移
		}
		if (a[left] < 0 && a[right] < 0)
		{
			right--; // 右指针左移
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