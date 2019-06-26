#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_CELL 100

char map[MAX_CELL][MAX_CELL];  // 每个格子的字母
bool visited[30];			  // 26个英文字母是否已经访问过
int res=1;
int temp=1;					// 起始位置也算1步
pair<int, int> direction[4];  // 上下左右
int r, c;					// 行、列数
/*
*	思路：深度优先搜索+回溯
*		规则是，对当前点的4个方向分别进行试探(注意边界判断)。
*		设置一个全局变量res来保存最优情况。
*		4个方向，哪个方向试探的结果如果比res大，就走那个方向。
*		每个方向试探完后，都回归原来的状态。
*/
void input()
{
	memset(visited, false,sizeof(visited));
	memset(map,0, sizeof(map));
	cin>>r>>c;
	char ch;
	for (int i = 0;i < r*c;i++)
	{
		cin>>ch;
		map[i/c][i % c]=ch;
	}
	
	direction[0] = make_pair(-1, 0);
	direction[1] = make_pair(1, 0);
	direction[2] = make_pair(0, -1);
	direction[3] = make_pair(0, 1);
}

void dfs(int row, int col)
{
	for (int i = 0;i < 4;i++)
	{
		int x =row+direction[i].first;
		int y = col + direction[i].second;
		// 没越界并且那个点上的字母没被访问过
		if (x >= 0 && x < r && y >= 0 && y < c && !visited[map[x][y]-'A'])
		{	
				visited[map[x][y] - 'A']=true;  // 设置为访问过
				temp++;
				dfs(x, y);

				res=max(res,temp);
				
				// 回溯
				temp--;
				visited[map[x][y] - 'A'] = false;  // 重新标记为未访问
		}
	}
}

int main()

{
	
	input();
	 
	// 从左上角开始搜索  // 起始位置也算1步
	visited[map[0][0] - 'A']=true;  
	dfs(0,0);
	cout<<res;
	return 0;
}