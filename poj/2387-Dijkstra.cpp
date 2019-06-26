#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_N 1000
#define MAX_T 2000
#define MAX_COST 999999   // 题目说了边的取值为1-100，可是又好像不是

int g[MAX_N][MAX_N];   // 邻接矩阵
bool used[MAX_N];	   // 源点到其它各点的最短距离是否已经确定 
int dis[MAX_N];		   // 源点到其它各点的最短距离

int n,e;				// 顶点数，边数

void input()
{
	// 先清空数组内容
	fill(g[0],g[0]+ MAX_N*MAX_N, MAX_COST);
	fill(used, used + MAX_N, false);
	fill(dis, dis + MAX_N, MAX_COST);
	for (int i = 0;i < n;i++)  // 点到自己的距离为0
	{
		 g[i][i]=0;
	}
	cin>>e>>n;
	int from,to,cost;
	for (int i = 0;i < e;i++)
	{
		cin>>from>>to>>cost;
		// 题目输入是从1开始下标的, 且要注意出现重复边的问题
		if (cost < g[from - 1][to - 1])
			g[from - 1][to - 1] = g[to - 1][from - 1] = cost;
	}
}
// 求解从索引为start的点到其它各点的最短距离
void solve(int start)
{
	
	for (int i = 0;i < n;i++)
	{
		dis[i]=g[start][i];
	}
	used[start] = true;
	for (int i = 0;i < n-1;i++)  // 除了自身，只要循环n-1次即可
	{
		// 求最小的中转点
		int this_node_index=-1;
		int min_cost= MAX_COST;
		// 遍历一遍dis[],找到最小距离对应的中转结点
		for (int j = 0;j < n;j++)
		{
			// 最小中转点的选择条件：如果该点没被确定，并且到源点距离最小
			if (dis[j] < min_cost && used[j]==false)
			{
				min_cost=dis[j];
				this_node_index=j;
			}
		}
		used[this_node_index] = true;  // 中转点设置为确定

		// 比较源点到其它点的距离是否通过中转点更小
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
	cout<<dis[0];  // 输出到第一个点的最短距离
	return 0;
}