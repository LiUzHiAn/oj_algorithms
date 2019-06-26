#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_NODE 50
#define MAX_EDGE 666666



struct Edge
{
	int from;
	int to;
	int weight;
};

int parent[MAX_NODE + 1];
Edge e[MAX_EDGE];
int n,edges_num;

bool cmp(Edge a, Edge b)
{
	return a.weight<b.weight;
}

int find(int i)  // �ҵ�i���������Ƚ�㣨��ʵ��������һ����������Ǹ��㼯�ϣ�
{
	while (parent[i] > 0)
	{
		i=parent[i];
	}
	return i;
}


// ��³˹�����㷨��С������
int main()
{
	while (1)
	{	
		// ��������
		cin >> n ;
		if (n == 0)
			break ;
		cin >> edges_num;
		memset(e,0,sizeof(e));
		memset(parent, 0, sizeof(parent));

		int to,from,weight;
		for (int i = 0;i < edges_num;i++)
		{
			cin>>from>>to>>weight;
			e[i].from=from;
			e[i].to = to;
			e[i].weight = weight;
		}

		// �����еı߽���һ������
		sort(e,e+edges_num,cmp);
		// ֻҪѡn-1���߾�����С��������
		int k=1;
		int sum=0;
		int p,q;
		for (int i = 0;k <= n - 1;i++)
		{
			
			p = find(e[i].from);
			q = find(e[i].to);
			if (q != p)
			{
				parent[q]=p;
				sum+=e[i].weight;
				k++;
			}
		}
		cout<<sum<<"\n";
	}
	
	return 0;
}