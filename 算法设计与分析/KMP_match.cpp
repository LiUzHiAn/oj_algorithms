#include<iostream>
using namespace std;
#define MAX_LEN 100

/*
*	���ƥ�䴮��next���飬�������
*/
void get_next_arr(char* t, int* next)
{
	// next[i]����ⷽ���ǣ��ҵ���t[0]~t[i-1]�Ĺ����ƥ��ǰ׺�ͺ�׺�ĳ���
	next[0]=-1;  // next[0]����Ϊ-1
	next[1]=0;	 // next[1]�϶���0
	// ֻҪ��ƥ�䴮��û���ף���Ҫ����Ӧλ��next[i]ֵ
	for (int i = 2;t[i] != '\0';i++) 
	{
		int max_len=i-1;		// �����Ϊi-1
		int len,j;
		for (len = max_len;len >= 1;len--)  // ����������ʼ����
		{
			for (j = 0;j < len;j++)
			{
				if(t[j]!=t[j+i-len])  // ֻҪ���κ�һλ����Ӧ��ȣ���ô��ǰlen�Ͳ���������̽��һ��len 
					break;
			}
			// �����һ��ѭ���������˳���������Ӧ����ˣ��ǾͰѵ�ǰ��len����next[i],������������̽��
			if(j==len)  
			{
				next[i]=len;
				break;
			}
		}
		if (len < 1)  // ���len=1�����������������next[i]�϶���0��
		{
			next[i]=0;
		}

	}
}


/*
*	���ƥ�䴮��next���飬�ݹ����
*/
void get_next_arr_2(char* t, int* next)
{
	next[0] = -1;  // next[0]����Ϊ-1
	next[1] = 0;	 // next[1]�϶���0
	int k;
	for (int j = 2;t[j] != '\0';j++)
	{
		k=next[j-1];
		if (k == -1)
		{
			next[j]=0;
			continue;
		}
		else
		{
			while (t[j-1] != t[k] && k!=-1)
				k=next[k];
			if(t[j-1] == t[k])
				next[j]=k+1;
			else
				next[j] = 0;
		}
	}
}

int KMP_match(char* s, char* t)
{
	// �����ƥ�䴮��next����
	int next[MAX_LEN];
	get_next_arr_2(t, next);

	// �ٿ�ʼƥ�䣬ƥ��ʱ�����������е��±겻���ݣ��ڴ�ƥ�䴮�е��±�����±�j�Ͷ�Ӧ��next[j]���л���
	int i=0,j=0;
	while (s[i]!='\0'&&t[j] != '\0')
	{
		if (s[i] == t[j])  // ���ƥ�䣬������������
		{
			i++;
			j++;
		}
		// ����Ļ�����������j
		else
		{
			j = next[j];
			// ע�⴦��һ��-1�����
			if (-1 == j)
			{
				i++;
				j++;
			}
		}		
	}
	if (t[j] == '\0')  // ���ƥ�䵽������Ǿ���ƥ��ɹ������ش��׵��±�
		return i-strlen(t);
	else  // ���򷵻�-1
		return -1;
}
int main()
{
	char* s="abcdabbcdabcdabd";
	char* t="abaababc";
	// �����ƥ�䴮��next����
	int next[MAX_LEN];
	get_next_arr_2(t, next);
	for (int i = 0;i < strlen(t);i++)
	{
		cout<<next[i]<<" ";
	}
	cout <<endl;
	cout<<KMP_match(s,t);
	return 0;
}