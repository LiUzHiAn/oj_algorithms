#include<iostream>
using namespace std;

int maxSubSum(int a[], int begin, int end)
{
	if (begin==end)
		return  a[begin];
	
	int mid=(begin+end)/2;
	int leftSum=maxSubSum(a,begin,mid);		// 最大字段和在左侧
	int rightSum = maxSubSum(a, mid+1,end);	// 最大字段和在右侧
	
	// 最大字段和跨越左右两侧
	int sum1=INT_MIN,lefts=0,sum2= INT_MIN,rights=0;
	for (int i = mid;i >= begin;i--)
	{
		lefts+=a[i];
		if(lefts>sum1)
			sum1=lefts;
	}
	for (int j = mid+1;j <= end;j++)
	{
		rights += a[j];
		if (rights>sum2)
			sum2 = rights;
	}
	int midSum=sum1+sum2;

	// 从3种情况中找最大
	int maxSum= INT_MIN;
	if(leftSum>midSum)
		maxSum=leftSum;
	else
		maxSum=midSum;

	if(rightSum>maxSum)
		maxSum=rightSum;

	return maxSum;
}

int main()
{
	int a[]={5,-3,4,-8,3,-2,6,2};
	cout<<maxSubSum(a,0,7);
}