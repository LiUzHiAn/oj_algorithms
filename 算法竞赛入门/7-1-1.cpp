#include<iostream>
#include <iomanip>   // ���������ʽ
using namespace std;


int main()
{
	int a,b,n;
	int exist[10]; // �ж�0~9�Ƿ񶼳�����
	int sum=0;
	cin>>n;
	for (a = 12345;a<= 98765;a++)
	{
		sum=0;
		if(a%n!=0) continue;
		b=a/n;
		memset(exist,0,sizeof(exist)); // ���
		int tem_a=a,tem_b=b;
		for (int i = 0;i < 5;i++)
		{
			exist[tem_a % 10]=1;
			exist[tem_b % 10] = 1;
			tem_a= tem_a /10;
			tem_b= tem_b /10;
		}
		for (int j = 0;j < 10;j++)
		{
			sum+=exist[j];
		}
		if (sum == 10)
		{
			cout.fill('0');
			cout<<setw(5)<<a<<"/" << setw(5) <<b<<"="<<n<<endl;
		}
	}
}