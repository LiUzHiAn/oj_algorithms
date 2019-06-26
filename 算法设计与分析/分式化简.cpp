#include<iostream>
using namespace std;

/*
* 欧几里得算法求最大公约数
*/
int gcd(int m, int n)
{
	int r=m%n;
	while (r != 0)
	{
		m=n;
		n=r;
		r=m%n;
	}
	return n;
}
int main()
{
	int a,b;
	cin>>a>>b;
	while (1)
	{
		int common= gcd(a, b);
		if (common != 1)
		{
			a/=common;
			b/=common;
		}
		else
		{
			break;
		}
	}
	cout<<endl<<a<<""<<b;
	return 0;
}