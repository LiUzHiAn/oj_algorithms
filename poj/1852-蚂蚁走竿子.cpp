#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_ANTS 1000000
int positon[MAX_ANTS];

int main()
{
	// 思路是：
	// ① 当每只蚂蚁都朝着距离竿子端点最近的那个端点的方向走，这样可以所有蚂蚁最快都掉下，且不会相遇。
	// 这时，最短时间就是距离竿子端点最短的那只蚂蚁所走的时间，即min{a1,a2...an},其中ai表示第i只蚂蚁到最近竿子端点的长度
	// ② 当每只蚂蚁都朝着距离竿子端点最远的那个端点的方向走，这样可以所有蚂蚁最慢掉下，虽然会相遇，但是可以画个图，蚂蚁相遇和不相遇是一样的时间。
	// 这时，最长时间就是max{a1,a2...an},其中ai表示第i只蚂蚁到最远竿子端点的长度
	
	// 有点奇怪，在POJ上C++能AC，G++会超时
	int caseNum;
	cin>> caseNum;
	while (caseNum--)
	{
		int poleLen,antsNum;
		cin>>poleLen>>antsNum;
		
		for(int i=0;i<antsNum;i++)
			cin>>positon[i];

		int minTime=0,maxTime=0;
		for (int j = 0;j < antsNum;j++)
		{
			minTime = max(min(positon[j], poleLen - positon[j]), minTime);
			maxTime = max(max(positon[j], poleLen - positon[j]), maxTime);
		}
		cout<<minTime<<" "<<maxTime<<endl;
	}

	return 0;

}