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
		// �ȶ����е�����
		sort(a,a+n);
		int pos=0,res=0;
		while (pos<n-1)
		{	
			int pre=a[pos];
			while(a[pos+1]-pre<=r && pos+1<=n-1)  // һֱ�����ߣ�֪���ߵ���һ���޷����ǵĵ�
				pos++;
			// ��pos��������һ�α��
			res++;
			// ����pos��r��Χ�ڵĵ�������ǣ���Ϊ�Ǵ������̽�����ģ�ֻҪ�����ұߵĵ㼴�ɣ�
			pre=a[pos];
			while(a[pos+1]-pre<=r && pos + 1 <= n - 1)
				pos++;

			// ������һ����
			pos++;
		}
		if(pos==n-1)  // �����ʣ�����һ����û�����Ǿ�ֱ��+1
			res++;
		cout<<res<<endl;
		cin >> r >> n;
	}
	return 0;
}