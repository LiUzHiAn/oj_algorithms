#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_N 101

int t[MAX_N][MAX_N];
int maxAdd[MAX_N][MAX_N];
int n;
int path[MAX_N][MAX_N];  // ������¼ÿһ����ô������

void input()
{
	memset(t,0,sizeof(t));
	memset(maxAdd, 0, sizeof(maxAdd));
	memset(path, 0, sizeof(path));
	cin>>n;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= i;j++)	
		{
			cin >> t[i][j];
		}
			
	}
}

/*
*	˼·����DP������ײ㿪ʼ��maxAdd[i][j]=t[i][j]+max{maxAdd[i+1][j],maxAdd[i+1][j+1]}
*/
int main()
{
	input();
	// dp��ʼ�����һ��
	for(int i=1;i<=n;i++)
		maxAdd[n][i]=t[n][i];
	for (int i = n - 1;i >= 1;i--)
	{
		for (int j = 1;j <= i;j++)
		{
			if (maxAdd[i + 1][j] > maxAdd[i + 1][j + 1])  // ѡ��һ���jλ��
			{
				maxAdd[i][j] = t[i][j] +maxAdd[i + 1][j];
				path[i][j]=j;
			}
			else
			{
				maxAdd[i][j] = t[i][j] + maxAdd[i + 1][j+1];
				path[i][j] = j+1;
			}
		}
	}

	// �������·��
	//int next_pos=path[1][1];
	//cout<<t[1][1];
	//for (int i = 2;i <= n;i++)
	//{
	//	cout<<"-->"<<t[i][next_pos];
	//	next_pos = path[i][next_pos];
	//}
	//cout<<"\n";

	cout<<maxAdd[1][1];
	return 0;
}