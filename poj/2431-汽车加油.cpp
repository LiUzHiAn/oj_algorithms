#include<iostream>
#include<queue>
using namespace std;

#define MAX_N 10000 
int n, l, p;
struct node
{
	int a, b; // A��ÿ������վ���복���ľ��룬B��ÿ������վ�Ĺ�����
}stop[MAX_N+1];

bool cmp(node p1, node p2)
{
	return p1.a<p2.a;
}
/*
*	һ��˼·�ǣ�ÿ��һ������վ���Ϳ����Ǽӻ��ǲ�����
*	�ǳ���˼·����Ϊ��������������Ͱ���޴�ÿ����һ�μ���վ��������Ϊ����һ�μ��͵Ļ��ᣨ��ֻҪ�Ժ�ȱ���ˣ�������ʱ�����ϣ�
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
		stop[i].a = l - stop[i].a;  // �����һ������Ϊ��Ŀ�е�A[i]��ÿ������վ���յ�ľ���
	}
	sort(stop, stop + n, cmp);  // !!!!һ��Ҫ�ǵ�sort�����ݲ��ǰ�������ģ���ӣ�����

	// ���յ�Ҳ���ɼ���վ������Ϊ0��
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
		int d=stop[i].a-cur_pos;  // ����һվ�ľ��룬Ҳ�Ǻ�����
		
		// �����������һվ����;�϶�Ҫ����
		while (gas_remain - d < 0) 
		{
			if (!q.empty())  // �����Ϳ��Լ�
			{
				gas_remain+=q.top();
				add_gas_times++;
				q.pop();
			}
			else  // û���ͼ��ˣ����ҵ�������һվ
			{
				cout<<-1;
				return 0;
			}
		}
		gas_remain-=d;
		cur_pos= stop[i].a;
		// ��վ�����һջ���Եļ������ŵ�����
		q.push(stop[i].b);
	}
	cout << add_gas_times;
	return 0;
}



