#include<iostream>
using namespace std;
#define MAXN 100
#define MAXM 100

char yard[MAXN][MAXM];  // 院子的每个点
int M,N;

void dfs_travel(int row,int col)
{
	yard[row][col]='.'; // 将设置为‘.’
	// 遍历周围8个点
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
		思路是：从任意个为‘W’的点开始DFS，将其周围八8个点全部设置为‘.’，统计将所有格子都变成‘.’时的深搜的次数，就是水洼数
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
			if (yard[i][j] == 'W')  // 如果有水，就开始dfs
			{
				dfs_travel(i,j);
				pond_num++;
			}
		}
	}
	cout<<pond_num;
	return 0;
}