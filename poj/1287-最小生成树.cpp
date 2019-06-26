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

int find(int i)  // 找第i个结点的祖先结点（其实就是在找一个结点属于那个点集合）
{
	while (parent[i] > 0)
	{
		i=parent[i];
	}
	return i;
}


// 克鲁斯卡尔算法最小生成树
int main()
{
	while (1)
	{	
		// 输入数据
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

		// 对所有的边进行一次排序
		sort(e,e+edges_num,cmp);
		// 只要选n-1条边就是最小生成树了
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