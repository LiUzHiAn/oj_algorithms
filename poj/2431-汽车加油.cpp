#include<iostream>
#include<queue>
using namespace std;

#define MAX_N 10000 
int n, l, p;
struct node
{
	int a, b; // A是每个加油站距离车起点的距离，B是每个加油站的供油量
}stop[MAX_N+1];

bool cmp(node p1, node p2)
{
	return p1.a<p2.a;
}
/*
*	一般思路是：每到一个加油站，就考虑是加还是不加油
*	非常规思路：因为假设了汽车的油桶无限大，每经过一次加油站，可以认为有了一次加油的机会（即只要以后缺油了，可以随时补加上）
*/

void input()
{
	cin >> n;
	for (int i = 0;i <n;i++) 
	{
		cin >> stop[i].a >> stop[i].b;
	}
	cin >> l >> p;
	for (int i = 0;i <n;i++)
	{
		stop[i].a = l - stop[i].a;  // 这里改一下是因为题目中的A[i]是每个加油站离终点的距离
	}
	sort(stop, stop + n, cmp);  // !!!!一定要记得sort，数据不是按序输入的，奇坑！！！

	// 把终点也当成加油站（油量为0）
	stop[n].a=l;
	stop[n].b=0;
}
int main()
{
	
	input();
	priority_queue<int> q;

	int add_gas_times=0,cur_pos=0,gas_remain=p;

	for (int i = 0;i <=n;i++)   
	{
		int d=stop[i].a-cur_pos;  // 到下一站的距离，也是耗油量
		
		// 如果到不了下一站，中途肯定要加油
		while (gas_remain - d < 0) 
		{
			if (!q.empty())  // 还有油可以加
			{
				gas_remain+=q.top();
				add_gas_times++;
				q.pop();
			}
			else  // 没有油加了，并且到不了下一站
			{
				cout<<-1;
				return 0;
			}
		}
		gas_remain-=d;
		cur_pos= stop[i].a;
		// 到站后把这一栈可以的加油量放到堆中
		q.push(stop[i].b);
	}
	cout << add_gas_times;
	return 0;
}



