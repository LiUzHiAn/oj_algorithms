#include<iostream>
using namespace std;
#define MAX_N 2001
char s[MAX_N], t[MAX_N];

int main()
{
	/*
		˼·�ǣ���ÿ�ε�S����S����Ӧ�ķ�ת��S'�Ƚϣ�
		���S<S',�ʹ�S��ͷȡһ���ַ��������β��ȡһ���ַ�
	*/
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> s[i];

	int left = 0, right = n - 1;
	int pos=0;
	while (left <= right)
	{
		bool left_smaller=false;
		for (int i = 0;i <= right - left;i++)
		{
			if (s[left + i] < s[right - i])  // S<S'
			{
				left_smaller=true;
				break;
			}
			else if (s[left + i] > s[right - i]) // S>S'
			{
				break;
			}
			// ��ǰλ��ȣ��������±�
		}
		if (left_smaller)
			t[pos++]=s[left++];
		else
			t[pos++] = s[right--];
		
	}
	// ���
	int j = 0;
	for (int i = 0;i<n;i++)
	{

		cout << t[i];
		j++;
		if (j == 80)
		{
			j = 0;
			cout << endl;
		}
	}
	return 0;
}