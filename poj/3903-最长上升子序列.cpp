#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_L 100000

int sequence[MAX_L];
int dp[MAX_L+1];


/*
*	思路是动归：
*	求解方法一：DP[i]表示下标从0到i的序列的最长上升子序列长度
*		则前i位的最长上升子序列求解如下，记第i位前的所有位置为j（到时候要遍历的）.
*		如果sequence[i]>sequence[j],则dp[i]=dp[j]+1,然后对所有j都考虑一下取最大的那个。
*
*	求解方法二：DP[i]表示，所有长度为i的上升子序列中，结尾最小的那个序列的结尾数字大小（dp下标从1开始）
*		所以状态转移方程是这样的：
*		如果在之前求解的dp中，找到第一个dp[i]，使得a[j]>dp[i],那么dp[i+1]=min(dp[i+1],a[j])
*		当然，也要注意每次和dp[1]比较一下，因为每个值自己都是一个长度为1的上升子序列
*		
*
*/
//int main1()
//{
//	int n;
//	while(cin >> n)
//	{
//		// 清空数组
//		memset(sequence,0,sizeof(sequence));
//		memset(dp, 0, sizeof(dp));
//		// 输入数据
//		for (int j = 0;j < n;j++)
//		{
//			cin>>sequence[j];
//			dp[j]=1;  // 先全部初始化为1
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
//		// 找出结果的最大值
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
		// 清空数组
		memset(sequence, 0, sizeof(sequence));
		fill(dp,dp+ MAX_L+1, INT_MAX);
		// 输入数据
		for (int j = 0;j < n;j++)
		{
			cin >> sequence[j];
		}
		for (int j =0;j < n;j++)
		{
			// 注意，这里我们是从1下标开始的，所以在指针的开始和结尾都加上了一个int的长度
			// 在这里用了lower_bound这个内置函数，它会二分查找第一个大于给定值的指针位置 (可以自己推导一下，dp是单调递增的)
			int* this_i_plus_1=lower_bound(dp+1, dp + MAX_L+1,sequence[j]);
			// 即动态转移方程的dp[i+1]=min(dp[i+1],a[j])部分
			*this_i_plus_1=min(*this_i_plus_1,sequence[j]);

			// 和长度为1的上升序列比较
			dp[1]=min(dp[1],sequence[j]);  // 这里这句话其实可以不要写，因为lower_bound没找到大于给定值时，会指向第一个，也就下面要比的dp[1]
		}
		// 找出结果的最大值
		// 先找到从下标1开始往后的第一个MAX_INT，也就是自从初始化以来从没改过的值
		int *max_value_pos =lower_bound(dp +1, dp + MAX_L+1, INT_MAX);
		// 再找到dp数组的头指针，这里从下标1 开始的
		int *head=dp+1;
		// 两个相减就是最长的上升子序列长度了
		cout << max_value_pos-head << endl;
	}

	return 0;
}