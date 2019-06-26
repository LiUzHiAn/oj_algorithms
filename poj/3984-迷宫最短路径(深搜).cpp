#include<iostream>
using namespace std;
#include<queue>
#include<stack>

typedef pair<int,int> point; // ����һ��pair

// int  maze[5][5];  // �Թ���״̬  1��ʾǽ�ڣ�0��ʾ�����ߵ�·
int maze[5][5] = {

	0, 1, 0, 0, 0,

	0, 1, 0, 1, 0,

	0, 0, 0, 0, 0,

	0, 1, 1, 1, 0,

	0, 0, 0, 1, 0,

};

// dx��dy��ͬʱȡ��ͬ�±�ģ����磨dx[0],dy[0]���ͱ�ʾ��һ�������ߵĵ�
int dx[4]={0,0,-1,1};   // 4�������dx
int dy[4]={-1,1,0,0};	// 4�������dy

point pre[5][5];  // ��¼һ�����ǰ���������յ㿪ʼ�������·��������
int dis[5][5];  // ��ʼ�㵽����ÿ�������,��ʼ��ʱ����Ϊ�����


/*
	˼·�ǣ�����ʼ�㿪ʼBFS�����ʼ�㵽�������е�����·����������ô�������յ�·�������pre������ÿ�����ǰ��
*/
int main()
{
	// ��ʼ����������
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
		// ��������յ��ֹͣ��Ѱ��
		if (x == 4 && y == 4)
		{
			break;
		}
		// ��ʼ������4������
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
	

	// ��һ��ջ�����·�������յ㿪ʼһֱ��ǰ����㣬�ŵ�ջ�У�������
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

	// �������
	while (!path.empty())
	{
		point p=path.top();
		cout<<'('<<p.first<<", "<< p.second << ')'<<endl;
		path.pop();
	}
	return 0;
}