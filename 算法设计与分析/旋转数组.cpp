#include<iostream>
using namespace std;
#define MAX_SIZE 10
int arr[MAX_SIZE][MAX_SIZE];


/*
* 在一个size*size阶的正方形蛇形填数字，从（begin，begin）处开始填数字
  第一个数字从number开始填，依次递增
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
	// 自己填一圈，再分治处理
	// 往下填
	for (int k = 0;k < size - 1;k++)
	{
		arr[i][j] = number++;
		i++;
	}
	// 往右填
	for (int k = 0;k < size - 1;k++)
	{
		arr[i][j] = number++;
		j++;
	}
	// 往上填
	for (int k = 0;k < size - 1;k++)
	{
		arr[i][j] = number++;
		i--;
	}
	// 往左填
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