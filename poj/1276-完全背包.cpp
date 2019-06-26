#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 10
#define MAX_CASH 100000 
int cash_num[MAX_N + 1], cash_value[MAX_N + 1];  // 每种钞票的数量和面值

// int dp[MAX_N + 1][MAX_CASH + 1];		// 动态规划的数数组，dp[i][j]表示从前i种钞票，总面值不超过j时，最大总面值
int dp[MAX_CASH + 1];

/* 动归的转移方程为:
*	if(w[i]>j)  // 第i种钞票本身面值就超过了总面值
*		dp[i][j]=dp[i-1][j]
*	else			// 第i种钞票本身面值没有超过了总面值，可以考虑取第i种多张或者不取的情况
*		dp[i][j] = max{ dp[i-1][j- k* w[i]]+v[i]（0<k<j/cash_value[i]）, dp[i-1][j] }
*
*   这里值得注意的是，我们其实并不真的需要去遍历一个k的循环，可以采用连续更新dp[i][j]的方式，
*	即else部分的转移方程变为：
*			dp[i][j] = max{ dp[i][j- w[i]]+v[i], dp[i-1][j] }
*
*	但由于这道题有内存限制，故换用一维数组即可，且这里一定要从前开始往后多次更新
*/
int main()
{

	// 输入数据
	int n, max_cash;
	cin >> max_cash >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> cash_num[i] >> cash_value[i];
	}

	// 初始化dp数组
	memset(dp, 0, sizeof(dp));

	for (int i = 1;i <= n;i++)
	{
		// 用1维的数组时，要从前往后更新
		for (int j = cash_value[i];j <= max_cash;j++)
		{
			if (cash_num[i] > 0)  // 要有该面值的钞票剩余
			{
				dp[j] = max(dp[j - cash_value[i]] + cash_value[i], dp[j]);
				j/cash_num[i]--;
			}
			else
			{
				break;
			}
				
		}
	}
	// cout<<dp[n][max_weight];
	cout << dp[max_cash];
	return 0;
}
