#include<iostream>
#include<queue>
using namespace std;
#define MAX_N 100010

bool vis[MAX_N];
int step[MAX_N];
/*
*	˼·�����⿴��������׷ţ��Ȼ��һֱ��̽�������ң�����*2˲�ƣ���ʵ����ת��һ��ͼ�ı���
*		�൱�ڵ�n�͵�n-1��n+1��2*n�������ڵģ�Ȼ�����ʼ�㿪ʼ���������������һ�������յ���˳�	��
*		������ǧ��ע��visit�����жϺ͸��µ�ʱ�������������Ԫ���൱���Ѿ������ˣ�ֻ�ǻ�û�е����� ������
*/
int main()
{
	fill(vis,vis+MAX_N,false);
	queue<int> q;
	int n,k;
	cin>>n>>k;
	if (n >= k)  // ���ũ����ţ���棬ֻ��һ��һ����ǰ�ƶ�
	{
		cout<<n-k;
		return 0;
	}
	step[n]=0;
	vis[n] = true;

	q.push(n);
	int now, next;
	while (!q.empty())
	{
		now=q.front();
		q.pop();
		for (int i = 0;i < 3;i++)
		{
			if(i==0) next=now-1;
			else if (i == 1) next = now + 1;
			else if(i==2) next=2*now;
			
			if(next<0||next>MAX_N)
				continue;	
			if (!vis[next])
			{
				vis[next]=true;
				q.push(next);
				step[next]=step[now]+1;
			}
			if (next == k)
			{
				cout << step[k];
				return 0;
			}
		}
	}
	return 0;
}
