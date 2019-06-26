/*
*	˼·���������ͼ�Ķ�����ɫ���⣬���Բ�ȡdfs�����ķ�ʽ��
*	ÿ��ȡһ���㣬Ȼ��������ڵ㻭��ͬ��ɫ���ڵ���ڵ��ֻ���ͬ��ɫ��ֱ�������������;������ͻ�˳���
*	
*	�ӵ㣺��Ŀû˵������ͼһ������ͨͼ�������ж����ͼ�����������һ��set�����滹û��ɫ�ĵ㣬
*		�ڱ�����ʱ�������ɫ�ˣ��ͽ�֮�Ӽ������޳���
*/


#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
#define MAX_NODE 2000
#define MAX_EDGE 1000000

// ���ڽӱ�ķ�ʽ����ʾͼ��ÿ���㶼��һ��vector���������ܵ��ı�
vector<int> graph[MAX_NODE+1];
// ÿ��������ɫ��-1Ϊ��ɫ��1Ϊ��ɫ��0Ϊδ��ɫ
int color[MAX_NODE];
// ÿ�������еĽ�����ͱ���
int node_num, edge_num;

set<int> s; // ��û��ɫ�ĵ�

void input()
{
	memset(color,0, sizeof(color));  // �����ɫ���
	for(int i=0;i<MAX_NODE + 1;i++)  // ����ڽӱ�
		graph[i].clear();
	s.clear();						//	��ջ�δ��ɫ�ĵ�
	cin>>node_num>>edge_num;
	for (int i = 1;i <= node_num;i++)  // ��ʼ��ʱ���е㶼��û��ɫ
	{
		s.insert(i);
	}
	int from,to;
	for (int i = 0;i < edge_num;i++)
	{
		cin>>from>>to;
		graph[from].push_back(to);
		graph[to].push_back(from);   // ˫���
	}
}

// �ӵ�i����㿪ʼ��ɫ
bool dfs(int i)
{
	queue<int> q;
	q.push(i);
	color[i]=1; // ����һ������ź�ɫ ���ڰ�����ν��
	s.erase(i); // ������Ѿ��Ź�ɫ��
	// dfs������ɫ
	while (!q.empty())
	{
		int from=q.front();
		q.pop();
		for (int j = 0;j < graph[from].size();j++)
		{
			// ������ڵĽ��û��ɫ�������ڵ����෴����ɫ
			if(color[graph[from][j]]==0)
			{	
				color[graph[from][j]]=-color[from]; 
				q.push(graph[from][j]);  // �ѵ�ǰ��������ڵ�ȡ���ŵ�������
				s.erase(graph[from][j]);  // ��û��ɫ�����еĵ�ɾȥ
			}
			// ������ڵĽ���Ѿ�����ͬ������ɫ������false
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
		// �������һ����������Ϊ��Ŀ��û˵���ͼ�Ƿ�����ͨͼ

		bool exitFlag = false;
		while (!s.empty())
		{
			// ֻҪ��һ����ɫʱʧ�ܣ�����ͼ��ɫʧ�ܣ�������ͼ��ɫ�϶�Ҳ��ʧ�ܵ�
			if (!dfs(*s.begin()))
			{
				exitFlag = true;
				break;
			}
		}
		if (exitFlag) // ��ɫʧ��
		{
			cout << "Scenario #" << i << ":" << endl;
			cout << "Suspicious bugs found!" << endl;
			cout<<endl;
		}
			
		else  // ��ɫ�ɹ�
		{
			cout << "Scenario #" << i << ":" << endl;
			cout << "No suspicious bugs found!" << endl;
			cout << endl;
		}		
	}
	return 0;
}