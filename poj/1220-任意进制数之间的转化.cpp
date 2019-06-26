#include<iostream>
#include<string>
using namespace std;

#define MAX_DIGIT 1000

int char2value[150];		// 0-9,A-Z,a-z��Ӧ��ȡֵ
char value2char[150];       
int f[MAX_DIGIT];	// ���������ÿһλ��ʾʮ���Ƶ���ֵ
int res[MAX_DIGIT];	// ������
int n,i_base,o_base;

void init_value()
{	
	// 0-9��ASCII��Ϊ48-57��A-Z��ASCII��Ϊ65-80��a-z��ASCII��Ϊ97-122
	for (int i = 48;i <= 57;i++)
		char2value[i]= i - 48;
	for (int i = 65;i <= 90;i++)
		char2value[i] = i - 'A' + 10;
	for (int i = 97;i <= 122;i++)
		char2value[i] = i - 'a'+36;

	for (int i = 0;i <= 9;i++)
		value2char[i] = i + '0';
	for (int i = 10;i <= 35;i++)
		value2char[i] = i - 10+ 'A';
	for (int i = 36;i <= 61;i++)
		value2char[i] = i -36 + 'a';
}

/*
*		˼·�ǣ���תΪ10���ƣ���תΪĿ����ơ�
*			1. ������һ����num��Ȼ���������ÿһλ����ʾʮ���Ƶ����ּ�¼������f[]��
*			2. �������ң�������numȥ���ԣ���ת���Ľ����Ǹ���������16�����õ������������Ϊ0,����Ϊ��һ�ε�num.������������һ������res[]��
*			3. Ȼ��res��������֣����������ע�⣬�����ʱ��ҲҪ�õ�value[]���飩	
*/
int main()
{
	init_value();
	cin>>n;
	while (n--)
	{
		string s;
		cin >> i_base >> o_base >> s;

		for (int l = 0;l < s.length();l++)
		{
			f[l] =  char2value[s[l]];
		}
		int num_len=s.length();
		int ans_index = 0;
		while (num_len > 0)   // ֻҪ�̲�Ϊ0����ʼ��ʱ������������
		{
			int temp = 0;
			int shang_index = 0;   // �м�ÿ���̵ĳ���
			bool flag=false;		// ���������� ���flag�൱�൱��Ҫ��������
			// ��һ�γ�������
			for (int i = 0;i < num_len;i++)
			{
				temp = temp*i_base + f[i];
				if (temp / o_base)
					flag = true;   
				if (flag) // ������þ�
				{
					f[shang_index++] = temp / o_base;
					temp %= o_base;
				}
			}
			num_len=shang_index;
			res[ans_index++]=temp;   // ÿһ�γ���������
		}
		cout<<i_base<<" "<<s<<endl;
		cout<<o_base<<" ";
		for (int i = ans_index - 1;i >= 0;i--)  // �������
		{
			cout<<value2char[res[i]];
		}
		cout<<endl<<endl;
		
	}
	
	
	return 0;
}