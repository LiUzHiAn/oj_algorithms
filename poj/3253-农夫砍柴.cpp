#include<queue>
#include<functional>
#include<iostream>
using namespace std;

/*
*	这题的思路非常类似Huffman树，每次将一根木板切成两根时，都选取最小和次小的两根木板。
*	然后把每次切成两根的原来那根加入到所有木板中，重复该操作。
*
*	这里很关键的地方就是求解最小和次小长的木板，有3种实现办法
*	1. 每次都排序，选前两个（这样的时间复杂度太高）
*	2. 用一个数组维护，第一次先排好序，然后选出最小和次小，求出它们的和，记为x，将x在数组的第3个元素开始插入排序。
*	3. 直接用STL中的优先队列，priority_queue，默认是一个降序的大根堆，如果需要逆序，可以用functional中的greater
*/
int main()
{
	priority_queue<int,vector<int>,greater<int>> q;
	int N;
	cin>>N;

	// 坑点，这里一定要用long long
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