#include<iostream>
using namespace std;


int BF(char* s, char* t)
{
	int index=0;
	int i=0,j=0;
	while (s[i] != '\0'&&t[j] != '\0')
	{
		if (s[i] == t[j])  // �����Ӧ�ַ���ȣ���ͬʱ����
		{
			i++;
			j++;
		}
		else
		{
			i=++index;
			j=0;
		}
	}
	if (t[j] == '\0') // �����ƥ��Ĵ�����β�����˳���ѭ������ʱһ���ǳɹ�ƥ��
		return index;
	else
		return  -1;  // ���򷵻�-1
}


int main()
{
	char* s="abccba";
	char* t="bca";
	cout<<BF(s,t);
}