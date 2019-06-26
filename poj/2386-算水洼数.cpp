#include<iostream>
using namespace std;
#define MAXN 100
#define MAXM 100

char yard[MAXN][MAXM];  // Ժ�ӵ�ÿ����
int M,N;

void dfs_travel(int row,int col)
{
	yard[row][col]='.'; // ������Ϊ��.��
	// ������Χ8����
	for (int dx = -1;dx <= 1;dx++)
	{
		for (int dy = -1;dy <= 1;dy++)
		{
			int row_=row+dx;
			int col_=col+dy;
			if(row_>=0 && row_<N && col_>=0 && col_<M && yard[row_][col_]=='W')
				dfs_travel(row_,col_);
		}
	}
}
int main()
{
	/*
		˼·�ǣ��������Ϊ��W���ĵ㿪ʼDFS��������Χ��8����ȫ������Ϊ��.����ͳ�ƽ����и��Ӷ���ɡ�.��ʱ�����ѵĴ���������ˮ����
	*/
	cin>>N>>M;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			cin>>yard[i][j];
		}
	}

	int pond_num=0;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			if (yard[i][j] == 'W')  // �����ˮ���Ϳ�ʼdfs
			{
				dfs_travel(i,j);
				pond_num++;
			}
		}
	}
	cout<<pond_num;
	return 0;
}