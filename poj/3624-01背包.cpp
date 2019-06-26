#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 3402
#define MAX_W 12880
int weight[MAX_N + 1], v[MAX_N + 1];  // ÿ������������ͼ�ֵ
// int dp[MAX_N + 1][MAX_W + 1];		// ��̬�滮�������飬dp[i][j]��ʾ��ǰi�����壬���ز�����jʱ������ܼ�ֵ

int dp[MAX_W + 1];
/* �����ת�Ʒ���Ϊ:
*	if(weight[i]>j)  // ��i�����屾��ͳ�����������
*		dp[i][j]=dp[i-1][j]
*	else			// ��i+1������Ž�ȥ���ᳬ�أ�Ҳ���Կ���ȡ���߲�ȡ�����
*		dp[i][j] = max{ dp[i-1][j-w[i]]+v[i], dp[i-1][j] }
*	
*	��������������ڴ����ƣ��ʻ���һά���鼴�ɣ�����ע��Ҫ�Ӻ���ǰ��ʼ����
*/
int main()
{
	
	// ��������
	int n,max_weight;
	cin>>n>>max_weight;
	for (int i = 1;i <= n;i++)
	{
		cin>>weight[i]>>v[i];
	}

	// ��ʼ��dp����
	memset(dp,0,sizeof(int)*(MAX_W+1));

	for (int i = 1;i <= n;i++)
	{
		// ��1ά������ʱ��Ҫ�Ӻ���ǰ����
		for (int j = max_weight;j >= weight[i];j--)
		{
			dp[j] = max(dp[j - weight[i]] + v[i], dp[j]);
		}
	}
	// cout<<dp[n][max_weight];
	cout << dp[max_weight];
	return 0;
}