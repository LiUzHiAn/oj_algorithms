#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 100
void print_permutation(int n, int* A, int cursor,int* sequence)
{
	// n�Ǵ���������г��ȣ�A���ź����������̽�����У�cursorΪδ���򼯺ϵĵ�һ��
	if (cursor == n)  // ǰ��n-1�����ź��ˣ���Ȼȫ�ź���
	{
		for (int i = 0;i < n;i++)
		{
			cout<< A[i]<<" ";
		}
		cout <<endl;
	}
	else
	{
		for (int j = 0;j < n;j++) // ������A��cusor��������sequenc[j]
		{
			if(j==0||sequence[j]!=sequence[j-1])
			{ 
				// cnt1����A����cursorǰ��sequenc[j]���ֵĴ���
				int cnt1=0;
				// cnt2����sequenc��sequenc[j]���ֵ��ܴ���
				int cnt2 = 0;
				for (int k = 0;k < cursor;k++)
				{
					if (A[k] == sequence[j])  // �����ǰ��������г��ֹ�׼����A��cusor���ŵ�����sequenc[j]
					{
						cnt1++;
					}
				}
				for (int k = 0;k < n;k++)
				{
					if (sequence[k] == sequence[j])  // ͳ��sequenc��sequenc[j]���ֵ��ܴ���
					{
						cnt2++;
					}
				}
				if (cnt1< cnt2) 
				{
					A[cursor]=sequence[j]; // �Ͱ�A��cusor������Ϊj
					print_permutation(n,A,cursor+1, sequence);  // �ݹ鴦����һλ���
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
	// Ҳ����ʹ��c++ STL�еĿ⺯��
	sort(sequence,sequence+n);  // �ȶ�ԭ���н�������
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