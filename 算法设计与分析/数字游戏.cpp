#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[]={1,2,3,4,5,6,7,8,9};
	while (next_permutation(a, a + 9))  // 直接用STL中全排列函数next_permutation()
	{
		if(a[2]==1|| a[6] == 1)
			continue;
		int m,n,p,q,s;
		m = 10 * a[0] + a[1];
		n = a[2];
		p = 100 * a[3] + 10 * a[4] + a[5];
		q = a[6];
		s = a[7] * 10 + a[8];
		if ( m*n+p/q-s== 0)
		{
			cout<< m<<"*"<< n << "+" << p<< "/" << q<< "-" <<s<< "==" << 0<<endl;
		}
	}
	
}