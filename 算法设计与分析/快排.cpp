#include<iostream>
using namespace std;

void swap_value(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int a[], int begin, int end)
/* ��������ķָ�����������֣������м�ֵ������ */
{
	int i=begin,j=end;  // ˫ָ��
	while (i<j)
	{
		while(i<j && a[i]<=a[j])  // ����ֵС
			j--;
		if (i < j)
		{
			swap_value(&a[i], &a[j]);
			i++;
		}
		while (i<j && a[j] >= a[i])  // �Ҳ��ֵ��
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
		quickSort(a,begin,pivot-1);			// ��벿������ 
		quickSort(a, pivot + 1,end);		// �Ұ벿������
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