#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_N 1000
#define MAX_T 2000
#define MAX_COST 999999   // ��Ŀ˵�˱ߵ�ȡֵΪ1-100�������ֺ�����

int g[MAX_N][MAX_N];   // �ڽӾ���
bool used[MAX_N];	   // Դ�㵽�����������̾����Ƿ��Ѿ�ȷ�� 
int dis[MAX_N];		   // Դ�㵽�����������̾���

int n,e;				// ������������

void input()
{
	// �������������
	fill(g[0],g[0]+ MAX_N*MAX_N, MAX_COST);
	fill(used, used + MAX_N, false);
	fill(dis, dis + MAX_N, MAX_COST);
	for (int i = 0;i < n;i++)  // �㵽�Լ��ľ���Ϊ0
	{
		 g[i][i]=0;
	}
	cin>>e>>n;
	int from,to,cost;
	for (int i = 0;i < e;i++)
	{
		cin>>from>>to>>cost;
		// ��Ŀ�����Ǵ�1��ʼ�±��, ��Ҫע������ظ��ߵ�����
		if (cost < g[from - 1][to - 1])
			g[from - 1][to - 1] = g[to - 1][from - 1] = cost;
	}
}
// ��������Ϊstart�ĵ㵽�����������̾���
void solve(int start)
{
	
	for (int i = 0;i < n;i++)
	{
		dis[i]=g[start][i];
	}
	used[start] = true;
	for (int i = 0;i < n-1;i++)  // ��������ֻҪѭ��n-1�μ���
	{
		// ����С����ת��
		int this_node_index=-1;
		int min_cost= MAX_COST;
		// ����һ��dis[],�ҵ���С�����Ӧ����ת���
		for (int j = 0;j < n;j++)
		{
			// ��С��ת���ѡ������������õ�û��ȷ�������ҵ�Դ�������С
			if (dis[j] < min_cost && used[j]==false)
			{
				min_cost=dis[j];
				this_node_index=j;
			}
		}
		used[this_node_index] = true;  // ��ת������Ϊȷ��

		// �Ƚ�Դ�㵽������ľ����Ƿ�ͨ����ת���С
		for (int k = 0;k < n;k++)
		{
			dis[k] = min(dis[this_node_index] + g[this_node_index][k], dis[k]);
		}
	}
}
int main()
{
	input();
	solve(n - 1);
	cout<<dis[0];  // �������һ�������̾���
	return 0;
}