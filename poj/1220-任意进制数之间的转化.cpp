#include<iostream>
#include<string>
using namespace std;

#define MAX_DIGIT 1000

int char2value[150];		// 0-9,A-Z,a-z对应的取值
char value2char[150];       
int f[MAX_DIGIT];	// 输入的数字每一位表示十进制的数值
int res[MAX_DIGIT];	// 输出结果
int n,i_base,o_base;

void init_value()
{	
	// 0-9的ASCII码为48-57，A-Z的ASCII码为65-80，a-z的ASCII码为97-122
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
*		思路是：先转为10进制，再转为目标进制。
*			1. 先输入一个数num，然后将这个数的每一位所表示十进制的数字记录在数组f[]中
*			2. 从左往右，不断用num去除以，待转化的进制那个数（例如16），得到的余数如果不为0,就作为下一次的num.余数保存在另一个数组res[]中
*			3. 然后将res里面的数字，逆序输出（注意，输出的时候也要用到value[]数组）	
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
		while (num_len > 0)   // 只要商不为0，初始化时被除数看作商
		{
			int temp = 0;
			int shang_index = 0;   // 中间每次商的长度
			bool flag=false;		// ！！！！！ 这个flag相当相当重要！！！！
			// 作一次除法运算
			for (int i = 0;i < num_len;i++)
			{
				temp = temp*i_base + f[i];
				if (temp / o_base)
					flag = true;   
				if (flag) // 如果除得尽
				{
					f[shang_index++] = temp / o_base;
					temp %= o_base;
				}
			}
			num_len=shang_index;
			res[ans_index++]=temp;   // 每一次除法的余数
		}
		cout<<i_base<<" "<<s<<endl;
		cout<<o_base<<" ";
		for (int i = ans_index - 1;i >= 0;i--)  // 逆序输出
		{
			cout<<value2char[res[i]];
		}
		cout<<endl<<endl;
		
	}
	
	
	return 0;
}