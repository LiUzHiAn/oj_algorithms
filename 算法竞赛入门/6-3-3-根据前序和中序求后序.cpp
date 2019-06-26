#include<iostream>
using namespace std;

void build(int len,char* firstOrderSequence, char* midOrderSequence,char* result)
{
	/*firstOrderSequence是先序遍历序列，midOrderSequence是中序遍历序列，
	  result是后序遍历序列，是一个输出参数，firstOrderSequence和midOrderSequence在递归中会改变*/
	if (len<=0) return;
	char root=firstOrderSequence[0];	// 根节点
	int pos=strchr(midOrderSequence,root)-midOrderSequence;	// 根节点在中序遍历中的位置
	
	// 处理左子树
	build(pos,firstOrderSequence+1,midOrderSequence,result);
	// 处理右边子树
	// 这里需要注意下为什么result也需要加上pos，因为我们的result是用来存放后序序列的
	// 后序的顺序是左子树、右子树、根，所以相当于我们把递归处理右子树结果放在左子树结果的前面
	// result其实是存放结果的字符串的头指针
	build(len-1-pos,firstOrderSequence+pos+1,midOrderSequence+pos+1,result+pos);
	
	result[len-1]=root;			// 把根节点放到后序遍历序列的左右子树的后面
	
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

