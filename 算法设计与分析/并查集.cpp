#include<iostream>
using namespace std;
#define MAX_SIZE 1000

int parent[MAX_SIZE];  // ÿ������ϼ�
int depth[MAX_SIZE];   // ���ĸ߶�

// ��ʼ��n��Ԫ��
void init(int n)
{
	for (int i = 0;i < n;i++)
	{
		parent[i]=i;
		depth[i]=1;
	}
}
 
// �ҽ��x�ĸ��ڵ�(�Ľ�ѹ��·���㷨)
int find(int x)
{
	if(parent[x]==x) // ��ǰ�����Ǹ����
		return x;
	else
		// �ݹ飬�ҵ����ڵ�ĸ��ڵ�
		// ����ǰ��㸸���ֱ��Ϊ�����
		return parent[x]=find(parent[x]);
}

// ��x��y�������������Ϻϲ�
void unite(int x, int y)
{
	int xroot=find(x);
	int yroot = find(y);
	if (xroot==yroot)   // ������������һ���飬ʲô������
		return;
	// ���߶�С�����ҵ��߶ȴ������
	if(depth[xroot]<depth[yroot])
		parent[xroot]=yroot;
	else
	{
		if(depth[xroot]==depth[yroot])
			depth[xroot]++;
		parent[yroot]=xroot;
	}
}

// �ж�x����y����Ƿ�����ͬһ����
bool same_set(int x, int y)
{
	return find(x)==find(y);
}
int  main()
{
	return 0;
}