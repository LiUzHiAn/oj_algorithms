#include<iostream>
#include<stdio.h>
using namespace std;


int get_next(int n)
{
	char num[5];
	// 把数字存入字符数组
	sprintf_s(num,"%d",n);
	int len=strlen(num);
	// 冒泡排序  升序
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
	// 最小数
	sscanf_s(num, "%d", &b);
	// 字符串反转
	for (int i = 0;i < len / 2;i++)
	{
		char tmp=num[i];
		num[i]=num[len-1-i];
		num[len - 1 - i]=tmp;
	}
	// 最大数
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
		// 如果结果和上一次输入相同就退出
		if (step_result == n)
		{
			break;
		}
		n=step_result;
	}
	return 0;
}