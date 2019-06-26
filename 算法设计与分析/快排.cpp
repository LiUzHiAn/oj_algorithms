#include<iostream>
using namespace std;

void swap_value(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int a[], int begin, int end)
/* 快速排序的分割成左右两部分，返回中间值的索引 */
{
	int i=begin,j=end;  // 双指针
	while (i<j)
	{
		while(i<j && a[i]<=a[j])  // 左侧的值小
			j--;
		if (i < j)
		{
			swap_value(&a[i], &a[j]);
			i++;
		}
		while (i<j && a[j] >= a[i])  // 右侧的值大
			i++;
		if (i < j)
		{
			swap_value(&a[i], &a[j]);
			j--;
		}
	}
	return i;
}

void quickSort(int a[], int begin, int end)
{
	int pivot;
	if (begin < end)
	{
		pivot=partition(a,begin,end);
		quickSort(a,begin,pivot-1);			// 左半部分排序 
		quickSort(a, pivot + 1,end);		// 右半部分排序
	}
}
int main()
{
	int a[9] = { 3,4,5,1,6,2,9,7,7 };
	quickSort(a, 0, 8);
	for (int i = 0;i < 8;i++)
	{
		cout << a[i] << " ";
	}
}