#include<queue>
#include<functional>
#include<iostream>
using namespace std;

/*
*	�����˼·�ǳ�����Huffman����ÿ�ν�һ��ľ���г�����ʱ����ѡȡ��С�ʹ�С������ľ�塣
*	Ȼ���ÿ���г�������ԭ���Ǹ����뵽����ľ���У��ظ��ò�����
*
*	����ܹؼ��ĵط����������С�ʹ�С����ľ�壬��3��ʵ�ְ취
*	1. ÿ�ζ�����ѡǰ������������ʱ�临�Ӷ�̫�ߣ�
*	2. ��һ������ά������һ�����ź���Ȼ��ѡ����С�ʹ�С��������ǵĺͣ���Ϊx����x������ĵ�3��Ԫ�ؿ�ʼ��������
*	3. ֱ����STL�е����ȶ��У�priority_queue��Ĭ����һ������Ĵ���ѣ������Ҫ���򣬿�����functional�е�greater
*/
int main()
{
	priority_queue<int,vector<int>,greater<int>> q;
	int N;
	cin>>N;

	// �ӵ㣬����һ��Ҫ��long long
	long long  ans=0;

	int L_i;
	for (int i = 0;i < N;i++)
	{
		cin>>L_i;
		q.push(L_i);
	}
	while (q.size()>=2)
	{
		int min1=q.top();
		q.pop();
		int min2 = q.top();
		q.pop();
		ans +=(min1+min2);
		
		q.push(min1+min2);
	}

	cout<<ans;
	return 0;
}