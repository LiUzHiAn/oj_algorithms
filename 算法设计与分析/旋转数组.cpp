#include<iostream>
using namespace std;
#define MAX_SIZE 10
int arr[MAX_SIZE][MAX_SIZE];


/*
* ��һ��size*size�׵����������������֣��ӣ�begin��begin������ʼ������
  ��һ�����ִ�number��ʼ����ε���
*/
void fill_in(int number, int begin, int size)
{
	if(size == 0)
		return;
	if (size == 1)
	{
		arr[begin][begin]=number;
		return;
	}
	int i=begin,j=begin;
	// �Լ���һȦ���ٷ��δ���
	// ������
	for (int k = 0;k < size - 1;k++)
	{
		arr[i][j] = number++;
		i++;
	}
	// ������
	for (int k = 0;k < size - 1;k++)
	{
		arr[i][j] = number++;
		j++;
	}
	// ������
	for (int k = 0;k < size - 1;k++)
	{
		arr[i][j] = number++;
		i--;
	}
	// ������
	for (int k = 0;k < size - 1;k++)
	{
		arr[i][j] = number++;
		j--;
	}

	fill_in(number,begin+1,size-2);
}
int main()
{	
	
	int N;
	cin>>N;
	fill_in(1,0,N);

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}