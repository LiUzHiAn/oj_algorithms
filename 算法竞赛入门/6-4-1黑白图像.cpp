#include<iostream>
#include<string>
using namespace std;
#define MAXN 500
int mat[MAXN][MAXN];	// 保存块状态的数组,0表示白色，1表示黑色
int visit[MAXN][MAXN];  // 保存块是否曾被遍历过

void dfs(int row,int col) // 深度优先遍历
{
	if (!mat[row][col] || visit[row][col])		// 是白色或被访问过
		return;

	visit[row][col]=1;
	// 否则依次遍历其周围8块
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
	// 输入数据过程
	int n;
	cin>>n;
	for (int i = 0;i < n;i++)
	{
		string str;
		cin>>str;
		for (int j = 0;j < n;j++)
		{
			mat[i+1][j+1]=str[j]-'0';  // 防止dfs遍历时格子出界，在整个格子外加一层留白
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