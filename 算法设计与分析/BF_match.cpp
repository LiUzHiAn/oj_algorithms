#include<iostream>
using namespace std;


int BF(char* s, char* t)
{
	int index=0;
	int i=0,j=0;
	while (s[i] != '\0'&&t[j] != '\0')
	{
		if (s[i] == t[j])  // 如果对应字符相等，均同时右移
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
	if (t[j] == '\0') // 如果待匹配的串到了尾部，退出了循环，此时一定是成功匹配
		return index;
	else
		return  -1;  // 否则返回-1
}


int main()
{
	char* s="abccba";
	char* t="bca";
	cout<<BF(s,t);
}