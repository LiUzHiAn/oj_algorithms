#include<iostream>
using namespace std;

#define MAX_M 10
#define MAX_N 10

int dp[MAX_M+1][MAX_N+1];

int main()
{
	int t;
	cin>>t;
	for (int k = 0;k < t;k++)  // t个case
	{
		memset(dp, 0, sizeof(dp));  // 清空
		int m, n;
		cin >> m >> n;
		dp[0][0] = 1;
		for (int i = 0;i <= m;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				// 动态转移方程思路：
				// 1. 如果将m分成n组，但是m小于n，那等价于将m分成m组（将空的组撤掉）
				// 2. 如果所有分的小组中都大于等于1，都减去一个1不影响结果，则dp[m][n]等价于dp[m-n][n]
				//	  如果有一个分组中有0，那相当于减少一个分组，则dp[m][n]等价于dp[m][n-1]
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