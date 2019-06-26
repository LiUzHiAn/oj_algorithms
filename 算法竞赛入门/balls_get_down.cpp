#include <iostream>
using namespace std;

/**
*	方法一：模拟每个小球的执行流程，然后输出最后一个。当层数较大时效率比较低。
**/
//bool flags[1<<20]={false};		// 每个结点的开关状态，最多20层
//int main()
//{
//	int I,D;
//	while(cin>>D>>I)
//	{ 
//		memset(flags,false,sizeof(bool)*(1<<20));
//		int last_layer_start_index= 1 << (D - 1);	// 最后一层第一个叶子结点的下标
//		int index;	// 最后一个小球下落的叶子结点编号
//		// I个小球模拟下落
//		for (int j = 1;j <= I;j++)
//		{
//			index=1;	// 从1开始
//			while(index< last_layer_start_index)
//			{
//				if(flags[index]==false)	// 开关关闭，往左走
//				{
//					flags[index] = true;  // 变化开关状态
//					index = index *2;
//				}
//				else				// 开关打开，往右走
//				{
//					flags[index] = false;  // 变化开关状态
//					index = index * 2+1;
//				}
//			}
//		}
//		cout<<index;
//	}
//	return 0;
//}

/**
*	方法二：根据小球的下落规律可知，只要是第奇数个球，那么它从根开始的第一次下落必定是往左走；
*			第偶数个球则往右走。递归该思想，将落到根节点左子树和右子树的点执行同样的奇偶判断。
			从而不再需要flag数组来判断小球的开关状态.
**/

int main()
{
	int I, D;
	while (cin >> D >> I)
	{
		int index=1;
		for (int j = 1;j < D;j++)  // 每个球肯定都下落D-1次
		{
			// 如果是该根节点的第奇数个求，则将(I+1)/2个小球划分到其左子树上去	
			if(I%2)	{index*=2;	I=(I+1)/2;}
			else {index=index*2+1; I/=2;}
		}
		cout<<index;
	}
	return 0;
}