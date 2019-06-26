#include<iostream>
using namespace std;



// Definition for singly-linked list.
struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {

		// 处理边界情况
		if (k==0)
			return head;
		if (head==NULL)
			return NULL;

		// 先对链表进行遍历一遍，得到链表的长度
		int len=0;
		ListNode * p=head;
		while (p != NULL)
		{
			p=p->next;
			len++;
		}

		k=k%len;

		// 双指针，left指向倒数第k个结点，right指向最后一个
		ListNode *left=head,*right= head;
		while (k)
		{
			right= right->next;
			k--;
		}
		// 同时移动双指针，直到right到底
		while (right->next != NULL)
		{
			left=left->next;
			right=right->next;
		}
		// 开始更改链表之间的悬挂方式
		// right指针后接到head，left后挂NULL，返回原left的后一个元素
		right->next=head;
		head=left->next;
		left->next=NULL;

		return head;
	}

};


int main()
{
	// 新建一个链表
	ListNode *link=new ListNode(1);
	ListNode *node1 = new ListNode(2);
	link->next=node1;
	ListNode *node2 = new ListNode(3);
	node1->next = node2;
	ListNode *node3 = new ListNode(4);
	node2->next = node3;
	ListNode *node4 = new ListNode(5);
	node3->next = node4;

	Solution s;
	ListNode *result=s.rotateRight(link,10);
	while (result)
	{
		cout<<result->val<<" ";
		result=result->next;
	}
	return 0;
}