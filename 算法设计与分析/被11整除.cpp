#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int sum=0;
	while (1)
	{
		int p=n / 100;
		sum+=n%100;

		if (p < 100)
		{
			sum += p;
			break;
		}
		n=p;
	}
	if(sum%11==0)
		cout<<"yes";
	else
		cout<<"no";

	return 0;
}