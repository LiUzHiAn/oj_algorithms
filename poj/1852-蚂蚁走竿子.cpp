#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_ANTS 1000000
int positon[MAX_ANTS];

int main()
{
	// ˼·�ǣ�
	// �� ��ÿֻ���϶����ž�����Ӷ˵�������Ǹ��˵�ķ����ߣ�������������������춼���£��Ҳ���������
	// ��ʱ�����ʱ����Ǿ�����Ӷ˵���̵���ֻ�������ߵ�ʱ�䣬��min{a1,a2...an},����ai��ʾ��iֻ���ϵ�������Ӷ˵�ĳ���
	// �� ��ÿֻ���϶����ž�����Ӷ˵���Զ���Ǹ��˵�ķ����ߣ������������������������£���Ȼ�����������ǿ��Ի���ͼ�����������Ͳ�������һ����ʱ�䡣
	// ��ʱ���ʱ�����max{a1,a2...an},����ai��ʾ��iֻ���ϵ���Զ���Ӷ˵�ĳ���
	
	// �е���֣���POJ��C++��AC��G++�ᳬʱ
	int caseNum;
	cin>> caseNum;
	while (caseNum--)
	{
		int poleLen,antsNum;
		cin>>poleLen>>antsNum;
		
		for(int i=0;i<antsNum;i++)
			cin>>positon[i];

		int minTime=0,maxTime=0;
		for (int j = 0;j < antsNum;j++)
		{
			minTime = max(min(positon[j], poleLen - positon[j]), minTime);
			maxTime = max(max(positon[j], poleLen - positon[j]), maxTime);
		}
		cout<<minTime<<" "<<maxTime<<endl;
	}

	return 0;

}