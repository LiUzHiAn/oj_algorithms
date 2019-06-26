#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 1000
#define MAX_R 1000

int a[MAX_N];

int main()
{
	int r,n;
	cin>>r>>n;
	while(!(r==-1&&n==-1))
	{
		for(int i=0;i<n;i++)
			cin>>a[i];
		// 先对所有点排序
		sort(a,a+n);
		int pos=0,res=0;
		while (pos<n-1)
		{	
			int pre=a[pos];
			while(a[pos+1]-pre<=r && pos+1<=n-1)  // 一直往下走，知道走到第一个无法覆盖的点
				pos++;
			// 在pos这个点进行一次标记
			res++;
			// 将在pos的r范围内的点跳过标记（因为是从左边试探过来的，只要考虑右边的点即可）
			pre=a[pos];
			while(a[pos+1]-pre<=r && pos + 1 <= n - 1)
				pos++;

			// 考虑下一个点
			pos++;
		}
		if(pos==n-1)  // 如果还剩下最后一个点没处理，那就直接+1
			res++;
		cout<<res<<endl;
		cin >> r >> n;
	}
	return 0;
}