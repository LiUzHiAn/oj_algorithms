#include<iostream>
#include<queue>
using namespace std;
#define MAX_N 100010

bool vis[MAX_N];
int step[MAX_N];
/*
*	思路：这题看似是人在追牛，然后一直试探向左，向右，还是*2瞬移，其实可以转成一个图的遍历
*		相当于点n和点n-1、n+1，2*n都是相邻的，然后从起始点开始，广度优先搜索，一旦到了终点就退出	、
*		！！！千万注意visit数组判断和更新的时机，队列里面的元素相当于已经遍历了，只是还没有弹出来 ！！！
*/
int main()
{
	fill(vis,vis+MAX_N,false);
	queue<int> q;
	int n,k;
	cin>>n>>k;
	if (n >= k)  // 如果农夫在牛后面，只能一步一步往前移动
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
