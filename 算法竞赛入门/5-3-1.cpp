#include<iostream>
#include<stdio.h>
using namespace std;


int get_next(int n)
{
	char num[5];
	// �����ִ����ַ�����
	sprintf_s(num,"%d",n);
	int len=strlen(num);
	// ð������  ����
	for (int i = 0;i < len;i++)
	{
		for (int j = i + 1;j < len;j++)
		{
			if (num[i]>num[j])
			{
				char tmp=num[j];
				num[j]=num[i];
				num[i]=tmp;
			}
		}
	}
	int b;
	// ��С��
	sscanf_s(num, "%d", &b);
	// �ַ�����ת
	for (int i = 0;i < len / 2;i++)
	{
		char tmp=num[i];
		num[i]=num[len-1-i];
		num[len - 1 - i]=tmp;
	}
	// �����
	int a;
	sscanf_s(num,"%d",&a);
	return a-b;
}
int main()
{
	int nums[2000];
	int n,step_result;
	cin>>n;
	nums[0]=n;
	cout<<n;
	while (true)
	{
		step_result=get_next(n);
		cout << "-->" <<step_result;
		// ����������һ��������ͬ���˳�
		if (step_result == n)
		{
			break;
		}
		n=step_result;
	}
	return 0;
}