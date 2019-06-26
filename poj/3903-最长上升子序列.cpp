#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_L 100000

int sequence[MAX_L];
int dp[MAX_L+1];


/*
*	˼·�Ƕ��飺
*	��ⷽ��һ��DP[i]��ʾ�±��0��i�����е�����������г���
*		��ǰiλ�������������������£��ǵ�iλǰ������λ��Ϊj����ʱ��Ҫ�����ģ�.
*		���sequence[i]>sequence[j],��dp[i]=dp[j]+1,Ȼ�������j������һ��ȡ�����Ǹ���
*
*	��ⷽ������DP[i]��ʾ�����г���Ϊi�������������У���β��С���Ǹ����еĽ�β���ִ�С��dp�±��1��ʼ��
*		����״̬ת�Ʒ����������ģ�
*		�����֮ǰ����dp�У��ҵ���һ��dp[i]��ʹ��a[j]>dp[i],��ôdp[i+1]=min(dp[i+1],a[j])
*		��Ȼ��ҲҪע��ÿ�κ�dp[1]�Ƚ�һ�£���Ϊÿ��ֵ�Լ�����һ������Ϊ1������������
*		
*
*/
//int main1()
//{
//	int n;
//	while(cin >> n)
//	{
//		// �������
//		memset(sequence,0,sizeof(sequence));
//		memset(dp, 0, sizeof(dp));
//		// ��������
//		for (int j = 0;j < n;j++)
//		{
//			cin>>sequence[j];
//			dp[j]=1;  // ��ȫ����ʼ��Ϊ1
//		}
//		for (int i = 0;i < n;i++)
//		{
//			for (int j = 0;j < i;j++)
//			{
//				if(sequence[i]>sequence[j])
//				{
//					dp[i]=max(dp[i],dp[j]+1);
//				}
//			}
//		}
//		// �ҳ���������ֵ
//		int res=-1;
//		for (int i = 0;i < n;i++)
//		{
//			res=max(res,dp[i]);
//		}
//		cout<< res <<endl;
//	}
//	
//	return 0;
//}

int main()
{
	int n;
	while (cin >> n)
	{
		// �������
		memset(sequence, 0, sizeof(sequence));
		fill(dp,dp+ MAX_L+1, INT_MAX);
		// ��������
		for (int j = 0;j < n;j++)
		{
			cin >> sequence[j];
		}
		for (int j =0;j < n;j++)
		{
			// ע�⣬���������Ǵ�1�±꿪ʼ�ģ�������ָ��Ŀ�ʼ�ͽ�β��������һ��int�ĳ���
			// ����������lower_bound������ú�����������ֲ��ҵ�һ�����ڸ���ֵ��ָ��λ�� (�����Լ��Ƶ�һ�£�dp�ǵ���������)
			int* this_i_plus_1=lower_bound(dp+1, dp + MAX_L+1,sequence[j]);
			// ����̬ת�Ʒ��̵�dp[i+1]=min(dp[i+1],a[j])����
			*this_i_plus_1=min(*this_i_plus_1,sequence[j]);

			// �ͳ���Ϊ1���������бȽ�
			dp[1]=min(dp[1],sequence[j]);  // ������仰��ʵ���Բ�Ҫд����Ϊlower_boundû�ҵ����ڸ���ֵʱ����ָ���һ����Ҳ������Ҫ�ȵ�dp[1]
		}
		// �ҳ���������ֵ
		// ���ҵ����±�1��ʼ����ĵ�һ��MAX_INT��Ҳ�����Դӳ�ʼ��������û�Ĺ���ֵ
		int *max_value_pos =lower_bound(dp +1, dp + MAX_L+1, INT_MAX);
		// ���ҵ�dp�����ͷָ�룬������±�1 ��ʼ��
		int *head=dp+1;
		// �����������������������г�����
		cout << max_value_pos-head << endl;
	}

	return 0;
}