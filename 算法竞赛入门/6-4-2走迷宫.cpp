#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct Node
{
	int row;
	int col;
};
#define MAXN 100
#define MAXM 100
int visit[MAXN][MAXM];
Node father[MAXN][MAXM];
queue<Node> q;
char* direction="UDLR";  // 四个方向
int dx[4] = {-1,1,0,0};	 // 四个方向对应的x方向增量
int dy[4] = {0,0,-1,1 };  // 四个方向对应的y方向增量
int maze[MAXN][MAXM];	// 迷宫各个点是否能走
int dist[MAXN][MAXM];	// 每个点到入口的最短距离
int last_dir[MAXN][MAXM];	// 每个点是从其父节点的经过何种方向走到的（有4种可能的取值）
int ROW,COL, xs , ys,  xt , yt; // 程序输入的行数、列数、开始点横纵坐标、终止点横纵坐标
void bfs(int row, int col)
{
/*从第row行第col列开始进行bfs遍历，，注意，改点为入口点*/
	Node n;
	n.row=row;
	n.col=col;
	visit[row][col]=1;	// 设置已被访问
	father[row][col]=n;	// 设置父亲节点为自己
	q.push(n);
	while (!q.empty())
	{
		Node front=q.front(); // 从队列头取出一个节点
		q.pop();
		// 依次遍历该结点的四个方向，是否走的通
		for (int i = 0;i < 4;i++)
		{
			int x=front.row+dx[i];
			int y= front.col + dy[i];
			// 如果某个方向的一点没出界，且没访问过，并且可以走
			if (x >= 0 && x<ROW && y >= 0 && y < COL && !visit[x][y] && maze[x][y])
			{
				Node node;
				node.row=x;
				node.col=y;
				visit[x][y]=1;
				father[x][y]=front;
				dist[x][y]=dist[front.row][front.col]+1;  // 到入口最短距离为其父节点到入口最短距离+1
				last_dir[x][y]=i;	
				q.push(node); // 把改点推入队列
			}
		}
	}

}

void print_path(int row, int col)
{
	stack<char> path;		// 用来保存输出路径
	/*从第row行第col列开始往前进行路径遍历，注意，改点为出口点*/
	while (true)
	{
		int father_row = father[row][col].row;
		int father_col = father[row][col].col;
		// 遍历的终止条件为到了入口点，还记得吗？入口点的父亲节点就是自己 ==> Line 27
		if (father_row == row && father_col == col)  //到了入口点
		{
			break;
		}
		else //没到入口点
		{
			path.push(direction[last_dir[row][col]]); // 记录该点是怎么从父亲节点过来的
			row=father_row;
			col=father_col;
		}
	}
	while (!path.empty())  // 输出路径
	{
		cout<<path.top();
		path.pop();
	}
}

int main()
{
	cin >> ROW >> COL >> xs >> ys >> xt >> yt;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL ;j++) {
			cin >> maze[i][j];
		}
	}
	memset(visit, 0, sizeof(visit)); 
	bfs(xs,ys);
	cout << endl;
	print_path(xt,yt);
	cout << endl;
	return 0;
}