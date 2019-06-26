#include<iostream>
#define MAX_SIZE 1000
using namespace std;


void merge(int a[], int temp[], int s, int m, int t)
/* ���ź����a[s]~a[m] �� a[m+1]~a[t]�鲢��temp[]������  */
{
	int i = s, j = m + 1;  // ˫ָ��
	int k = s;		// �������ָ��
	while (i <= m & j <= t)
	{
		if (a[i] < a[j])  // ˭Сȡ˭
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
	// ��ʣ��Ĳ���ȫ���ŵ�����
	while (i <= m)
		temp[k++] = a[i++];
	while (j <= t)
		temp[k++] = a[j++];
}

void mergeSort(int a[], int s, int t)
{
	int temp[MAX_SIZE];  //  �м����ڱ����¼������
	if(s==t)
		return;
	int m=(s+t)/2;
	mergeSort(a,s,m);		// ����벿������
	mergeSort(a, m+1, t);	// ���Ұ벿������
	merge(a,temp,s,m,t);	// ���������������й鲢����,����ݴ���temp��
	for (int i = s;i <= t;i++)  // һ��ע�⣬�����ǰѲ��ܴ��ź����a[s]~a[t]�鲢����
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