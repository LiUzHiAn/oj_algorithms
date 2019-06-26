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
char* direction="UDLR";  // �ĸ�����
int dx[4] = {-1,1,0,0};	 // �ĸ������Ӧ��x��������
int dy[4] = {0,0,-1,1 };  // �ĸ������Ӧ��y��������
int maze[MAXN][MAXM];	// �Թ��������Ƿ�����
int dist[MAXN][MAXM];	// ÿ���㵽��ڵ���̾���
int last_dir[MAXN][MAXM];	// ÿ�����Ǵ��丸�ڵ�ľ������ַ����ߵ��ģ���4�ֿ��ܵ�ȡֵ��
int ROW,COL, xs , ys,  xt , yt; // �����������������������ʼ��������ꡢ��ֹ���������
void bfs(int row, int col)
{
/*�ӵ�row�е�col�п�ʼ����bfs��������ע�⣬�ĵ�Ϊ��ڵ�*/
	Node n;
	n.row=row;
	n.col=col;
	visit[row][col]=1;	// �����ѱ�����
	father[row][col]=n;	// ���ø��׽ڵ�Ϊ�Լ�
	q.push(n);
	while (!q.empty())
	{
		Node front=q.front(); // �Ӷ���ͷȡ��һ���ڵ�
		q.pop();
		// ���α����ý����ĸ������Ƿ��ߵ�ͨ
		for (int i = 0;i < 4;i++)
		{
			int x=front.row+dx[i];
			int y= front.col + dy[i];
			// ���ĳ�������һ��û���磬��û���ʹ������ҿ�����
			if (x >= 0 && x<ROW && y >= 0 && y < COL && !visit[x][y] && maze[x][y])
			{
				Node node;
				node.row=x;
				node.col=y;
				visit[x][y]=1;
				father[x][y]=front;
				dist[x][y]=dist[front.row][front.col]+1;  // �������̾���Ϊ�丸�ڵ㵽�����̾���+1
				last_dir[x][y]=i;	
				q.push(node); // �Ѹĵ��������
			}
		}
	}

}

void print_path(int row, int col)
{
	stack<char> path;		// �����������·��
	/*�ӵ�row�е�col�п�ʼ��ǰ����·��������ע�⣬�ĵ�Ϊ���ڵ�*/
	while (true)
	{
		int father_row = father[row][col].row;
		int father_col = father[row][col].col;
		// ��������ֹ����Ϊ������ڵ㣬���ǵ�����ڵ�ĸ��׽ڵ�����Լ� ==> Line 27
		if (father_row == row && father_col == col)  //������ڵ�
		{
			break;
		}
		else //û����ڵ�
		{
			path.push(direction[last_dir[row][col]]); // ��¼�õ�����ô�Ӹ��׽ڵ������
			row=father_row;
			col=father_col;
		}
	}
	while (!path.empty())  // ���·��
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