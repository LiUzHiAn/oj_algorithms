#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 100
void print_permutation(int n, int* A, int cursor,int* sequence)
{
	// n是代排序的序列长度，A是排好序或正在试探的序列，cursor为未排序集合的第一个
	if (cursor == n)  // 前面n-1个都排好了，自然全排好了
	{
		for (int i = 0;i < n;i++)
		{
			cout<< A[i]<<" ";
		}
		cout <<endl;
	}
	else
	{
		for (int j = 0;j < n;j++) // 尝试在A【cusor】放数字sequenc[j]
		{
			if(j==0||sequence[j]!=sequence[j-1])
			{ 
				// cnt1保存A数组cursor前面sequenc[j]出现的次数
				int cnt1=0;
				// cnt2保存sequenc中sequenc[j]出现的总次数
				int cnt2 = 0;
				for (int k = 0;k < cursor;k++)
				{
					if (A[k] == sequence[j])  // 如果在前面的序列中出现过准备在A【cusor】放的数字sequenc[j]
					{
						cnt1++;
					}
				}
				for (int k = 0;k < n;k++)
				{
					if (sequence[k] == sequence[j])  // 统计sequenc中sequenc[j]出现的总次数
					{
						cnt2++;
					}
				}
				if (cnt1< cnt2) 
				{
					A[cursor]=sequence[j]; // 就把A【cusor】设置为j
					print_permutation(n,A,cursor+1, sequence);  // 递归处理下一位情况
				}
			}
		}
	}

}


int main()
{
	
	int A[MAX_N]={0};
	int sequence[MAX_N]={1,2,3,4};
	int n=4;
	// print_permutation(n,A,0, sequence); 
	// 也可以使用c++ STL中的库函数
	sort(sequence,sequence+n);  // 先对原序列进行排序
	do
	{
		for (int i = 0;i < n;i++)
		{
			cout<<sequence[i]<< " ";
		}
		cout<<endl;
	} while (next_permutation(sequence,sequence+n));
	
	return 0;
}