#include<iostream>
using namespace std;

#define MAX_M 10
#define MAX_N 10

int dp[MAX_M+1][MAX_N+1];

int main()
{
	int t;
	cin>>t;
	for (int k = 0;k < t;k++)  // t��case
	{
		memset(dp, 0, sizeof(dp));  // ���
		int m, n;
		cin >> m >> n;
		dp[0][0] = 1;
		for (int i = 0;i <= m;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				// ��̬ת�Ʒ���˼·��
				// 1. �����m�ֳ�n�飬����mС��n���ǵȼ��ڽ�m�ֳ�m�飨���յ��鳷����
				// 2. ������зֵ�С���ж����ڵ���1������ȥһ��1��Ӱ��������dp[m][n]�ȼ���dp[m-n][n]
				//	  �����һ����������0�����൱�ڼ���һ�����飬��dp[m][n]�ȼ���dp[m][n-1]
				if(i<j)
					dp[i][j]=dp[i][i];
				else
					dp[i][j] = dp[i - j][j] + dp[i][j - 1];
				
			}
		}
		cout<<dp[m][n]<<endl;
	}
	
	return 0;
}