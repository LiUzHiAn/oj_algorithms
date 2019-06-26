#include<iostream>

using namespace std;

int my_pow(int x)
{
	return x*x;
}
/*
* 大整数幂运算求模
*/
int get_mod(int a, int n, int m)
{
	// 主要思路就是，根据(a*b)mod c=[(a mod c)*(b mod c)] mod c
	// 不断折半。
	if(n==0)
		return 1;
	if(n%2)
		return my_pow(get_mod(a,n/2,m))%m;  // 折半思想
	else
	{
		return a*get_mod(a, n-1, m) % m;
	}
}

int main()
{
	int a,m,n;
	cin>>a>>n>>m;
	cout<< get_mod(a,n,m);
}