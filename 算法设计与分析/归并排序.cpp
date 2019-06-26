#include<iostream>
#define MAX_SIZE 1000
using namespace std;


void merge(int a[], int temp[], int s, int m, int t)
/* 将排好序的a[s]~a[m] 和 a[m+1]~a[t]归并到temp[]数组中  */
{
	int i = s, j = m + 1;  // 双指针
	int k = s;		// 结果保存指针
	while (i <= m & j <= t)
	{
		if (a[i] < a[j])  // 谁小取谁
		{
			temp[k] = a[i];
			i++;
			k++;
		}
		else
		{
			temp[k] = a[j];
			j++;
			k++;
		}
	}
	// 把剩余的部分全部放到后面
	while (i <= m)
		temp[k++] = a[i++];
	while (j <= t)
		temp[k++] = a[j++];
}

void mergeSort(int a[], int s, int t)
{
	int temp[MAX_SIZE];  //  中间用于保存记录的数组
	if(s==t)
		return;
	int m=(s+t)/2;
	mergeSort(a,s,m);		// 对左半部分排序
	mergeSort(a, m+1, t);	// 对右半部分排序
	merge(a,temp,s,m,t);	// 对左右两个子序列归并起来,结果暂存在temp中
	for (int i = s;i <= t;i++)  // 一定注意，这里是把才能从排好序的a[s]~a[t]归并起来
		a[i]=temp[i];


}

int main(int argc,char* argv[])
{
	int a[9]={3,4,5,1,6,2,9,7,7};
	mergeSort(a,0,8);
	for (int i = 0;i < 8;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
 }