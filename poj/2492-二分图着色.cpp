/*
*	思路：这道题是图的二分着色问题，可以采取dfs遍历的方式。
*	每次取一个点，然后给它的邻点画不同颜色，邻点的邻点又画不同颜色，直到遍历完或者中途产生冲突退出。
*	
*	坑点：题目没说给出的图一定是连通图，可能有多个子图，这里采用了一个set来保存还没着色的点，
*		在遍历的时候，如果着色了，就将之从集合中剔除。
*/


#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
#define MAX_NODE 2000
#define MAX_EDGE 1000000

// 用邻接表的方式来表示图，每个点都有一个vector来保存它能到的边
vector<int> graph[MAX_NODE+1];
// 每个结点的颜色，-1为白色，1为黑色，0为未着色
int color[MAX_NODE];
// 每个样本中的结点数和边数
int node_num, edge_num;

set<int> s; // 还没着色的点

void input()
{
	memset(color,0, sizeof(color));  // 清空着色情况
	for(int i=0;i<MAX_NODE + 1;i++)  // 清空邻接表
		graph[i].clear();
	s.clear();						//	清空还未着色的点
	cin>>node_num>>edge_num;
	for (int i = 1;i <= node_num;i++)  // 初始化时所有点都还没着色
	{
		s.insert(i);
	}
	int from,to;
	for (int i = 0;i < edge_num;i++)
	{
		cin>>from>>to;
		graph[from].push_back(to);
		graph[to].push_back(from);   // 双向边
	}
}

// 从第i个结点开始着色
bool dfs(int i)
{
	queue<int> q;
	q.push(i);
	color[i]=1; // 给第一个结点着黑色 （黑白无所谓）
	s.erase(i); // 这个点已经着过色了
	// dfs遍历着色
	while (!q.empty())
	{
		int from=q.front();
		q.pop();
		for (int j = 0;j < graph[from].size();j++)
		{
			// 如果相邻的结点没着色，给相邻点着相反的颜色
			if(color[graph[from][j]]==0)
			{	
				color[graph[from][j]]=-color[from]; 
				q.push(graph[from][j]);  // 把当前点的其他邻点取出放到队列中
				s.erase(graph[from][j]);  // 把没着色集合中的点删去
			}
			// 如果相邻的结点已经着了同样的颜色，返回false
			if (color[graph[from][j]] == color[from])
				return false;
		}
	}
	return true;
}

int main()
{	
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		input();
		// 这里采用一个集合是因为题目中没说这个图是否是连通图

		bool exitFlag = false;
		while (!s.empty())
		{
			// 只要有一次着色时失败（即子图着色失败），整合图着色肯定也是失败的
			if (!dfs(*s.begin()))
			{
				exitFlag = true;
				break;
			}
		}
		if (exitFlag) // 着色失败
		{
			cout << "Scenario #" << i << ":" << endl;
			cout << "Suspicious bugs found!" << endl;
			cout<<endl;
		}
			
		else  // 着色成功
		{
			cout << "Scenario #" << i << ":" << endl;
			cout << "No suspicious bugs found!" << endl;
			cout << endl;
		}		
	}
	return 0;
}