#include <iostream>
using namespace std;

/**
*	����һ��ģ��ÿ��С���ִ�����̣�Ȼ��������һ�����������ϴ�ʱЧ�ʱȽϵ͡�
**/
//bool flags[1<<20]={false};		// ÿ�����Ŀ���״̬�����20��
//int main()
//{
//	int I,D;
//	while(cin>>D>>I)
//	{ 
//		memset(flags,false,sizeof(bool)*(1<<20));
//		int last_layer_start_index= 1 << (D - 1);	// ���һ���һ��Ҷ�ӽ����±�
//		int index;	// ���һ��С�������Ҷ�ӽ����
//		// I��С��ģ������
//		for (int j = 1;j <= I;j++)
//		{
//			index=1;	// ��1��ʼ
//			while(index< last_layer_start_index)
//			{
//				if(flags[index]==false)	// ���عرգ�������
//				{
//					flags[index] = true;  // �仯����״̬
//					index = index *2;
//				}
//				else				// ���ش򿪣�������
//				{
//					flags[index] = false;  // �仯����״̬
//					index = index * 2+1;
//				}
//			}
//		}
//		cout<<index;
//	}
//	return 0;
//}

/**
*	������������С���������ɿ�֪��ֻҪ�ǵ�����������ô���Ӹ���ʼ�ĵ�һ������ض��������ߣ�
*			��ż�������������ߡ��ݹ��˼�룬���䵽���ڵ����������������ĵ�ִ��ͬ������ż�жϡ�
			�Ӷ�������Ҫflag�������ж�С��Ŀ���״̬.
**/

int main()
{
	int I, D;
	while (cin >> D >> I)
	{
		int index=1;
		for (int j = 1;j < D;j++)  // ÿ����϶�������D-1��
		{
			// ����Ǹø��ڵ�ĵ�����������(I+1)/2��С�򻮷ֵ�����������ȥ	
			if(I%2)	{index*=2;	I=(I+1)/2;}
			else {index=index*2+1; I/=2;}
		}
		cout<<index;
	}
	return 0;
}