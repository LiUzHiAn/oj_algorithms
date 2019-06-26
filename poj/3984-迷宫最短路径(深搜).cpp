#include<iostream>
using namespace std;
#include<queue>
#include<stack>

typedef pair<int,int> point; // 定义一个pair

// int  maze[5][5];  // 迷宫的状态  1表示墙壁，0表示可以走的路
int maze[5][5] = {

	0, 1, 0, 0, 0,

	0, 1, 0, 1, 0,

	0, 0, 0, 0, 0,

	0, 1, 1, 1, 0,

	0, 0, 0, 1, 0,

};

// dx和dy是同时取相同下标的，例如（dx[0],dy[0]）就表示走一个点的左边的点
int dx[4]={0,0,-1,1};   // 4个方向的dx
int dy[4]={-1,1,0,0};	// 4个方向的dy

point pre[5][5];  // 记录一个点的前驱，最后从终点开始输出就是路径的逆序
int dis[5][5];  // 起始点到其它每个点距离,初始化时设置为无穷大


/*
	思路是：从起始点开始BFS求出起始点到其它所有点的最短路径。至于怎么保存最终的路径嘛，就用pre来保存每个点的前驱
*/
int main()
{
	// 初始化距离数组
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			dis[i][j]=INT_MAX;
		}
	}
	queue<point> q;
	point start(0,0);
	q.push(start);  
	dis[0][0]=0;
	while (!q.empty())
	{
		point temp=q.front();
		q.pop();
		int x=temp.first,y=temp.second;
		// 如果到了终点就停止搜寻了
		if (x == 4 && y == 4)
		{
			break;
		}
		// 开始找它的4个方向
		for (int i = 0; i < 4; i++)
		{
			int x_ = x + dx[i];
			int y_ = y + dy[i];
			if (x_ >= 0 && x_ < 5 && y_ >= 0 && y_ < 5 && maze[x_][y_] == 0 && dis[x_][y_]==INT_MAX)
			{
				dis[x_][y_]=dis[x][y]+1;
				point pre_point(x,y);
				pre[x_][y_]=pre_point;
				q.push(point (x_,y_));
			}

		}
	}
	

	// 用一个栈来输出路径，从终点开始一直找前驱结点，放到栈中，最后输出
	stack<point> path;
	path.push(point (4,4));
	int x=4,y=4;
	while(!(x==0&&y==0))
	{
		point pre_point=pre[x][y];
		path.push(pre_point);
		x= pre_point.first;
		y = pre_point.second;
	}

	// 逆序输出
	while (!path.empty())
	{
		point p=path.top();
		cout<<'('<<p.first<<", "<< p.second << ')'<<endl;
		path.pop();
	}
	return 0;
}