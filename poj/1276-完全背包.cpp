#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 10
#define MAX_CASH 100000 
int cash_num[MAX_N + 1], cash_value[MAX_N + 1];  // ÿ�ֳ�Ʊ����������ֵ

// int dp[MAX_N + 1][MAX_CASH + 1];		// ��̬�滮�������飬dp[i][j]��ʾ��ǰi�ֳ�Ʊ������ֵ������jʱ���������ֵ
int dp[MAX_CASH + 1];

/* �����ת�Ʒ���Ϊ:
*	if(w[i]>j)  // ��i�ֳ�Ʊ������ֵ�ͳ���������ֵ
*		dp[i][j]=dp[i-1][j]
*	else			// ��i�ֳ�Ʊ������ֵû�г���������ֵ�����Կ���ȡ��i�ֶ��Ż��߲�ȡ�����
*		dp[i][j] = max{ dp[i-1][j- k* w[i]]+v[i]��0<k<j/cash_value[i]��, dp[i-1][j] }
*
*   ����ֵ��ע����ǣ�������ʵ���������Ҫȥ����һ��k��ѭ�������Բ�����������dp[i][j]�ķ�ʽ��
*	��else���ֵ�ת�Ʒ��̱�Ϊ��
*			dp[i][j] = max{ dp[i][j- w[i]]+v[i], dp[i-1][j] }
*
*	��������������ڴ����ƣ��ʻ���һά���鼴�ɣ�������һ��Ҫ��ǰ��ʼ�����θ���
*/
int main()
{

	// ��������
	int n, max_cash;
	cin >> max_cash >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> cash_num[i] >> cash_value[i];
	}

	// ��ʼ��dp����
	memset(dp, 0, sizeof(dp));

	for (int i = 1;i <= n;i++)
	{
		// ��1ά������ʱ��Ҫ��ǰ�������
		for (int j = cash_value[i];j <= max_cash;j++)
		{
			if (cash_num[i] > 0)  // Ҫ�и���ֵ�ĳ�Ʊʣ��
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
