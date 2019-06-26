#include<iostream>
using namespace std;
#define MAX_LEN 100

/*
*	求待匹配串的next数组，暴力求解
*/
void get_next_arr(char* t, int* next)
{
	// next[i]的求解方法是，找到从t[0]~t[i-1]的公共最长匹配前缀和后缀的长度
	next[0]=-1;  // next[0]定义为-1
	next[1]=0;	 // next[1]肯定是0
	// 只要待匹配串还没到底，都要求相应位的next[i]值
	for (int i = 2;t[i] != '\0';i++) 
	{
		int max_len=i-1;		// 最长长度为i-1
		int len,j;
		for (len = max_len;len >= 1;len--)  // 从最长的情况开始搜索
		{
			for (j = 0;j < len;j++)
			{
				if(t[j]!=t[j+i-len])  // 只要有任何一位不对应相等，那么当前len就不成立，试探下一个len 
					break;
			}
			// 如果上一个循环是正常退出，即都对应相等了，那就把当前的len赋给next[i],并不再往下试探了
			if(j==len)  
			{
				next[i]=len;
				break;
			}
		}
		if (len < 1)  // 如果len=1的情况都不成立，那next[i]肯定是0了
		{
			next[i]=0;
		}

	}
}


/*
*	求待匹配串的next数组，递归求解
*/
void get_next_arr_2(char* t, int* next)
{
	next[0] = -1;  // next[0]定义为-1
	next[1] = 0;	 // next[1]肯定是0
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
	// 先求待匹配串的next集合
	int next[MAX_LEN];
	get_next_arr_2(t, next);

	// 再开始匹配，匹配时，在搜索串中的下标不回溯，在待匹配串中的下标根据下标j和对应的next[j]进行回溯
	int i=0,j=0;
	while (s[i]!='\0'&&t[j] != '\0')
	{
		if (s[i] == t[j])  // 如果匹配，继续往下搜索
		{
			i++;
			j++;
		}
		// 否则的话，更新索引j
		else
		{
			j = next[j];
			// 注意处理一下-1的情况
			if (-1 == j)
			{
				i++;
				j++;
			}
		}		
	}
	if (t[j] == '\0')  // 如果匹配到了最后，那就是匹配成功，返回串首的下标
		return i-strlen(t);
	else  // 否则返回-1
		return -1;
}
int main()
{
	char* s="abcdabbcdabcdabd";
	char* t="abaababc";
	// 先求待匹配串的next集合
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