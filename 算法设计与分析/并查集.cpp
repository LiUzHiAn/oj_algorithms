#include<iostream>
using namespace std;
#define MAX_SIZE 1000

int parent[MAX_SIZE];  // 每个点的上级
int depth[MAX_SIZE];   // 树的高度

// 初始化n个元素
void init(int n)
{
	for (int i = 0;i < n;i++)
	{
		parent[i]=i;
		depth[i]=1;
	}
}
 
// 找结点x的根节点(改进压缩路径算法)
int find(int x)
{
	if(parent[x]==x) // 当前结点就是根结点
		return x;
	else
		// 递归，找到父节点的根节点
		// 并另当前结点父结点直接为根结点
		return parent[x]=find(parent[x]);
}

// 将x和y所属的两个集合合并
void unite(int x, int y)
{
	int xroot=find(x);
	int yroot = find(y);
	if (xroot==yroot)   // 如果本身就属于一个组，什么都不干
		return;
	// 将高度小的树挂到高度大的树上
	if(depth[xroot]<depth[yroot])
		parent[xroot]=yroot;
	else
	{
		if(depth[xroot]==depth[yroot])
			depth[xroot]++;
		parent[yroot]=xroot;
	}
}

// 判断x结点和y结点是否属于同一集合
bool same_set(int x, int y)
{
	return find(x)==find(y);
}
int  main()
{
	return 0;
}