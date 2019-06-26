#include<iostream>
using namespace std;
#define MAX_N 2001
char s[MAX_N], t[MAX_N];

int main()
{
	/*
		思路是：将每次的S串和S串对应的反转串S'比较，
		如果S<S',就从S的头取一个字符，否则从尾部取一个字符
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
			// 当前位相等，继续往下比
		}
		if (left_smaller)
			t[pos++]=s[left++];
		else
			t[pos++] = s[right--];
		
	}
	// 输出
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