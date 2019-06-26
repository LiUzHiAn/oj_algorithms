#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 3402
#define MAX_W 12880
int weight[MAX_N + 1], v[MAX_N + 1];  // 每个物体的重量和价值
// int dp[MAX_N + 1][MAX_W + 1];		// 动态规划的数数组，dp[i][j]表示从前i个物体，总重不超过j时，最大总价值

int dp[MAX_W + 1];
/* 动归的转移方程为:
*	if(weight[i]>j)  // 第i个物体本身就超过了总重量
*		dp[i][j]=dp[i-1][j]
*	else			// 第i+1个物体放进去不会超重，也可以考虑取或者不取的情况
*		dp[i][j] = max{ dp[i-1][j-w[i]]+v[i], dp[i-1][j] }
*	
*	但由于这道题有内存限制，故换用一维数组即可，不过注意要从后往前开始更新
*/
int main()
{
	
	// 输入数据
	int n,max_weight;
	cin>>n>>max_weight;
	for (int i = 1;i <= n;i++)
	{
		cin>>weight[i]>>v[i];
	}

	// 初始化dp数组
	memset(dp,0,sizeof(int)*(MAX_W+1));

	for (int i = 1;i <= n;i++)
	{
		// 用1维的数组时，要从后往前更新
		for (int j = max_weight;j >= weight[i];j--)
		{
			dp[j] = max(dp[j - weight[i]] + v[i], dp[j]);
		}
	}
	// cout<<dp[n][max_weight];
	cout << dp[max_weight];
	return 0;
}