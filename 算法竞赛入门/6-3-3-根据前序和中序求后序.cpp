#include<iostream>
using namespace std;

void build(int len,char* firstOrderSequence, char* midOrderSequence,char* result)
{
	/*firstOrderSequence������������У�midOrderSequence������������У�
	  result�Ǻ���������У���һ�����������firstOrderSequence��midOrderSequence�ڵݹ��л�ı�*/
	if (len<=0) return;
	char root=firstOrderSequence[0];	// ���ڵ�
	int pos=strchr(midOrderSequence,root)-midOrderSequence;	// ���ڵ�����������е�λ��
	
	// ����������
	build(pos,firstOrderSequence+1,midOrderSequence,result);
	// �����ұ�����
	// ������Ҫע����ΪʲôresultҲ��Ҫ����pos����Ϊ���ǵ�result��������ź������е�
	// �����˳�����������������������������൱�����ǰѵݹ鴦��������������������������ǰ��
	// result��ʵ�Ǵ�Ž�����ַ�����ͷָ��
	build(len-1-pos,firstOrderSequence+pos+1,midOrderSequence+pos+1,result+pos);
	
	result[len-1]=root;			// �Ѹ��ڵ�ŵ�����������е����������ĺ���
	
}


int main()
{
	char s1[1000], s2[1000], result[1000];
	while(cin>>s1>>s2)
	{
		int len =strlen(s1);
		build(len,s1,s2,result);
		result[len]='\0';
		cout<<result;
	}
	return 0;
}

