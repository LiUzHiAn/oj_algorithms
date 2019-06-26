#include<iostream>
#include<string>
using namespace std;
#define MAXN 500
int mat[MAXN][MAXN];	// �����״̬������,0��ʾ��ɫ��1��ʾ��ɫ
int visit[MAXN][MAXN];  // ������Ƿ�����������

void dfs(int row,int col) // ������ȱ���
{
	if (!mat[row][col] || visit[row][col])		// �ǰ�ɫ�򱻷��ʹ�
		return;

	visit[row][col]=1;
	// �������α�������Χ8��
	dfs(row - 1, col - 1);
	dfs(row , col - 1);
	dfs(row + 1, col - 1);
	dfs(row + 1, col);
	dfs(row + 1, col + 1);
	dfs(row , col + 1);
	dfs(row - 1, col + 1);
	dfs(row - 1, col);
}

int main()
{
	// �������ݹ���
	int n;
	cin>>n;
	for (int i = 0;i < n;i++)
	{
		string str;
		cin>>str;
		for (int j = 0;j < n;j++)
		{
			mat[i+1][j+1]=str[j]-'0';  // ��ֹdfs����ʱ���ӳ��磬�������������һ������
		}
	}
	int cnt=0;
	for (int row = 1;row <= n;row++)
	{
		for (int col = 1;col <= n;col++)
		{
			if (!visit[row][col] && mat[row][col])
			{
				cnt++;
				dfs(row,col);
			}
		}
	}
	cout<<cnt;
	return 0;
}

//6
//100100
//001010
//000000
//110000
//111000
//010100